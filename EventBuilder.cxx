//Root event builder for E14060 data
//author: A Keeler, August 16, 2019


#include <string>
#include <TString.h>
#include "EventBuilder.hpp"


using namespace std;


int main(int argc, char *argv[]){
  TFile *file = new TFile(argv[1]);
  EventBuilder(file, argv[2]);
  file->Close();  
  return 0;
}

void EventBuilder(TFile* file, string outfile){

  TString event_type;
  bool implant;
  bool decay;
  std::vector<processor_struct::VANDLES> VandleEvent;
  std::vector<processor_struct::CLOVERS> GeEvents;
  PspmtEvent current_event;
  vector<PspmtEvent> past_events = {};
  stringstream ss;
  ss<<outfile;
  
  TFile *outFile = new TFile(ss.str().c_str(), "RECREATE");
  TTree *eventTree = new TTree("eventTree", "eventTree");
  eventTree->Branch("event_type", &event_type);
  eventTree->Branch("implant", &implant);
  eventTree->Branch("decay", &decay);
  eventTree->Branch("vandle", &VandleEvent);
  eventTree->Branch("ge_events", &GeEvents);
  eventTree->Branch("current_event", &current_event);
  eventTree->Branch("past_events", &past_events);

  TTree* PixieTree = (TTree*)file->Get("PixTree");
  TTreeReader PixEvent(PixieTree);

  //  PixEvent.SetTree(PixieTree);
  TTreeReaderArray<processor_struct::PID> pid = {PixEvent, "pid_vec_"};
  TTreeReaderArray<processor_struct::PSPMT> pspmt = {PixEvent, "pspmt_vec_"};
  TTreeReaderArray<processor_struct::VANDLES> vandle = {PixEvent, "vandle_vec_"};
  TTreeReaderArray<processor_struct::CLOVERS> ge_events = {PixEvent, "clover_vec_"};

  processor_struct::PID default_pid;
  PspmtEvent default_event;
  

  // cut72Co = new TCutG("72Co_cut",9);
  // cut72Co->SetVarX("mass_charge");
  // cut72Co->SetVarY("nuclear_z");
  // cut72Co->SetTitle("Graph");
  // cut72Co->SetFillStyle(1000);
  // cut72Co->SetPoint(0,1002.68,525.397);
  // cut72Co->SetPoint(1,1042.76,530.36);
  // cut72Co->SetPoint(2,1088.18,530.36);
  // cut72Co->SetPoint(3,1125.59,523.743);
  // cut72Co->SetPoint(4,1126.92,509.404);
  // cut72Co->SetPoint(5,1105.55,499.478);
  // cut72Co->SetPoint(6,1064.13,496.721);
  // cut72Co->SetPoint(7,1030.73,499.478);
  // cut72Co->SetPoint(8,1002.68,525.397);

  cut72Co = new TCutG("CUT72CO",8);
  cut72Co->SetVarX("mass_charge");
  cut72Co->SetVarY("nuclear_z");
  cut72Co->SetTitle("Graph");
  cut72Co->SetFillStyle(1000);
  // cut72Co->SetPoint(0,890.459,524.294);
  // cut72Co->SetPoint(1,878.436,516.022);
  // cut72Co->SetPoint(2,894.467,504.441);
  // cut72Co->SetPoint(3,922.522,498.375);
  // cut72Co->SetPoint(4,1000.01,504.993);
  // cut72Co->SetPoint(5,1000.01,524.846);
  // cut72Co->SetPoint(6,934.546,528.706);
  // cut72Co->SetPoint(7,890.459,524.294);

  cut72Co->SetPoint(0,870.827,530.433);
  cut72Co->SetPoint(1,823.609,527.741);
  cut72Co->SetPoint(2,792.129,518.051);
  cut72Co->SetPoint(3,805.007,505.131);
  cut72Co->SetPoint(4,866.535,503.516);
  cut72Co->SetPoint(5,890.86,507.822);
  cut72Co->SetPoint(6,928.062,519.666);
  cut72Co->SetPoint(7,910.892,527.203);
  cut72Co->SetPoint(8,886.567,529.894);
  cut72Co->SetPoint(9,870.827,530.433);

  

  while (PixEvent.Next()){

    bool hasIon = false;
    bool hasDynodeLow = false, hasDynodeHi = false, hasVeto = false;
    bool hasImplant = false, hasDecay = false;
    bool hasPosition = false, has72Co = false, has78Zn = false;
    double xa_hi = 0, xb_hi = 0, ya_hi = 0, yb_hi = 0;
    double xa_low = 0, xb_low = 0, ya_low = 0, yb_low = 0;
    pair<double,double> pos = make_pair(-2, -2);
    pair<int, int> pixel = make_pair(0, 0);
    double timestamp_l = -999, timestamp_h = -999;

    if(pid.GetSize() > 0){
      if ((*pid.begin()).nuclear_z > 1)
        hasIon = true;
    }
    for (auto posIt = pspmt.begin(); posIt != pspmt.end(); posIt++){
      string stype = posIt->subtype.Data();
      string posTag = posIt->tag.Data();

      //parse the pspmt information to compute positions and tag implants and decays
      if(stype == "anode_high"){
        if (posTag == "xa")
          xa_hi = posIt->energy;
        else if (posTag == "xb")
          xb_hi = posIt->energy;
        else if (posTag == "ya")
          ya_hi = posIt->energy;
        else if (posTag == "yb")
          yb_hi = posIt->energy;
      } else if(stype == "anode_low"){
        if (posTag == "xa")
          xa_low = posIt->energy;
        else if (posTag == "xb")
          xb_low = posIt->energy;
        else if (posTag == "ya")
          ya_low = posIt->energy;
        else if (posTag == "yb")
          yb_low = posIt->energy;
      } else if (stype == "dynode_low" && posIt->energy > 5){
        hasDynodeLow = true;
        timestamp_l = posIt->time;
      } else if (stype == "dynode_high" && 1 < posIt->energy && posIt->energy < 16000){
        hasDynodeHi = true;
        timestamp_h = posIt->time;
      } else if (stype == "veto" && posIt->energy > 350){
        hasVeto = true;
      }
      
      stype = "";
      posTag = "";
    }

    if(pid.GetSize() > 0){
      if(hasIon && hasDynodeLow && !hasVeto && (*pid.begin()).nuclear_z > 400){
        hasImplant = true;
        has72Co = cut72Co->IsInside((*pid.begin()).mass_charge, (*pid.begin()).nuclear_z);
        current_event.wanted_implant = has72Co;
        current_event.timestamp = timestamp_l;
        event_type = "implant";
      }
    }

    if (hasDynodeHi && !hasIon && !hasVeto){
      hasDecay = true;
      current_event.timestamp = timestamp_h;
      event_type = "decay";
    }

    if (hasVeto){
      event_type = "veto";
    }


   

    if (hasImplant && xa_low > 1 && xb_low > 1 && ya_low > 1 && yb_low > 1){
      hasPosition = true;
      pos = CalculatePosition(xa_low, xb_low, ya_low, yb_low, hasImplant);
      pixel = CalculatePixel(pos);
      current_event.pos = pos;
      current_event.pixel = pixel;

    } else if (hasDecay && xa_hi > 1 && xb_hi > 1 && ya_hi > 1 && yb_hi > 1){
      hasPosition = true;
      pos = CalculatePosition(xa_hi, xb_hi, ya_hi, yb_hi, hasImplant);
      pixel = CalculatePixel(pos);
      current_event.pos = pos;
      current_event.pixel = pixel;

    }

    implant = hasImplant && hasPosition;
    decay = hasDecay && hasPosition;

    if (pid.GetSize() > 0){
      current_event.PidEvent = (*pid.begin());
    } else {
      current_event.PidEvent = default_pid;
    }

    double decay_window = 5 * 60 * pow(10,6);

    if (hasPosition && hasImplant)
      past_events.emplace_back(current_event);
    
    if (hasPosition && hasDecay){
      for (auto it=past_events.begin(); it != past_events.end(); it++){
        if (past_events.empty()){
          PspmtEvent tmp;
          past_events.emplace_back(tmp);
          break;
        }
        if (current_event.timestamp - (*it).timestamp > decay_window){
          past_events.erase(it);
        }
      }
    }

    
    for (auto it = vandle.begin(); it != vandle.end(); it++){
      VandleEvent.emplace_back((*it));
    }
    for (auto it = ge_events.begin(); it != ge_events.end(); it++){
      GeEvents.emplace_back((*it));
    }



    eventTree->Fill();
    VandleEvent.clear();
    GeEvents.clear();
    current_event = default_event;
  }


  delete cut72Co;
  outFile->Write();
  outFile->Close();
  ss.str("");
}

pair<double, double> CalculatePosition(double &xa, double &xb, double &ya, double &yb, bool &lowgain){
  double x_pos = 0, y_pos = 0;
  if(lowgain){
    x_pos = ((xa - xb + 0.0005 * (pow(xa,2) - pow(xb,2))) / (xa + xb + 0.0005 * (pow(xa,2) + pow(xb,2)))) * 0.87 + 0.014;
    y_pos = ((ya - yb + 0.0006 * (pow(ya,2) - pow(yb,2))) / (ya + yb + 0.0006 * (pow(ya,2) + pow(yb,2)))) * 0.85 - 0.007;
  } else {
    x_pos = (xa - xb) / (xa + xb);
    y_pos = (ya - yb) / (ya + yb);
  }

  return make_pair(x_pos, y_pos);
}

pair<int, int> CalculatePixel(pair<double, double> &position){
  int x_pixel = 0, y_pixel = 0;
  x_pixel = 12 * (3.33 * position.first + 1);
  y_pixel = 12 * (3.33 * position.second + 1);
  return make_pair(x_pixel, y_pixel);
}


