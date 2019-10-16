#define CoSelector_cxx
// The class definition in CoSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("CoSelector.C")
// root> T->Process("CoSelector.C","some options")
// root> T->Process("CoSelector.C+")
//


#include "CoSelector.h"
#include <TH2.h>
#include <TStyle.h>

void CoSelector::Begin(TTree * eventTree)
{

  outputFilePrefix = "72Co_Beta_n_out";
  fReader.SetTree(eventTree);

  TString option = GetOption();

  GetOutputList()->Clear();
}

void CoSelector::SlaveBegin(TTree * eventTree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   //78Zn for use with files 10-14
   // cut78Zn = new TCutG("ZN78CUT",13);
   // cut78Zn->SetVarX("mass_charge");
   // cut78Zn->SetVarY("nuclear_z");
   // cut78Zn->SetTitle("Graph");
   // cut78Zn->SetFillStyle(1000);
   // cut78Zn->SetPoint(0,881.873,654.714);
   // cut78Zn->SetPoint(1,840.294,649.714);
   // cut78Zn->SetPoint(2,814.706,641.857);
   // cut78Zn->SetPoint(3,819.504,631.857);
   // cut78Zn->SetPoint(4,859.484,624.714);
   // cut78Zn->SetPoint(5,910.659,624);
   // cut78Zn->SetPoint(6,955.437,630.429);
   // cut78Zn->SetPoint(7,985.822,639);
   // cut78Zn->SetPoint(8,984.223,652.571);
   // cut78Zn->SetPoint(9,947.441,660.429);
   // cut78Zn->SetPoint(10,912.258,662.571);
   // cut78Zn->SetPoint(11,894.667,659);
   // cut78Zn->SetPoint(12,881.873,654.714);

   //78Zn for use with files 30-53
   cut78Zn = new TCutG("CUTG78",11);
   cut78Zn->SetVarX("pid plot");
   cut78Zn->SetVarY("");
   cut78Zn->SetTitle("Graph");
   cut78Zn->SetFillStyle(1000);
   cut78Zn->SetPoint(0,1310.63,653.387);
   cut78Zn->SetPoint(1,1228.32,639.521);
   cut78Zn->SetPoint(2,1229.69,630.697);
   cut78Zn->SetPoint(3,1285.93,622.504);
   cut78Zn->SetPoint(4,1335.32,621.874);
   cut78Zn->SetPoint(5,1381.96,622.504);
   cut78Zn->SetPoint(6,1427.23,631.958);
   cut78Zn->SetPoint(7,1423.11,639.521);
   cut78Zn->SetPoint(8,1379.21,652.126);
   cut78Zn->SetPoint(9,1335.32,654.647);
   cut78Zn->SetPoint(10,1310.63,653.387);

   //71Co for use with files 10-14
   // cut71Co = new TCutG("CUT71CO",13);
   // cut71Co->SetVarX("mass_charge");
   // cut71Co->SetVarY("nuclear_z");
   // cut71Co->SetTitle("Graph");
   // cut71Co->SetFillStyle(1000);
   // cut71Co->SetPoint(0,693.166,536.857);
   // cut71Co->SetPoint(1,645.19,533.286);
   // cut71Co->SetPoint(2,610.007,524.714);
   // cut71Co->SetPoint(3,582.821,514.714);
   // cut71Co->SetPoint(4,589.217,501.143);
   // cut71Co->SetPoint(5,622.801,495.429);
   // cut71Co->SetPoint(6,680.372,495.429);
   // cut71Co->SetPoint(7,717.154,504);
   // cut71Co->SetPoint(8,758.734,515.429);
   // cut71Co->SetPoint(9,768.329,526.143);
   // cut71Co->SetPoint(10,736.345,534);
   // cut71Co->SetPoint(11,709.158,536.143);
   // cut71Co->SetPoint(12,693.166,536.857);

   //71Co for use with files 30-53
   cut71Co = new TCutG("CUTG71",12);
   cut71Co->SetVarX("pid plot");
   cut71Co->SetVarY("");
   cut71Co->SetTitle("Graph");
   cut71Co->SetFillStyle(1000);
   cut71Co->SetPoint(0,1085.65,526.706);
   cut71Co->SetPoint(1,1026.67,515.361);
   cut71Co->SetPoint(2,1011.58,505.908);
   cut71Co->SetPoint(3,1029.41,496.454);
   cut71Co->SetPoint(4,1095.26,491.412);
   cut71Co->SetPoint(5,1163.85,495.824);
   cut71Co->SetPoint(6,1209.11,511.58);
   cut71Co->SetPoint(7,1199.51,518.513);
   cut71Co->SetPoint(8,1172.08,524.185);
   cut71Co->SetPoint(9,1141.9,527.966);
   cut71Co->SetPoint(10,1110.35,529.227);
   cut71Co->SetPoint(11,1085.65,526.706);

   //72Co for use with files 10-14
   // cut72Co = new TCutG("CO72CUT",12);
   // cut72Co->SetVarX("mass_charge");
   // cut72Co->SetVarY("nuclear_z");
   // cut72Co->SetTitle("Graph");
   // cut72Co->SetFillStyle(1000);
   // cut72Co->SetPoint(0,618.003,535.429);
   // cut72Co->SetPoint(1,565.229,541.857);
   // cut72Co->SetPoint(2,530.047,541.857);
   // cut72Co->SetPoint(3,491.665,534.714);
   // cut72Co->SetPoint(4,469.276,524);
   // cut72Co->SetPoint(5,469.276,510.429);
   // cut72Co->SetPoint(6,504.459,504.714);
   // cut72Co->SetPoint(7,549.237,504.714);
   // cut72Co->SetPoint(8,571.626,509.714);
   // cut72Co->SetPoint(9,587.618,516.143);
   // cut72Co->SetPoint(10,624.4,533.286);
   // cut72Co->SetPoint(11,618.003,535.429);

   //72Co for use with files 30-53
   cut72Co = new TCutG("CO72CUT",12);
   cut72Co->SetVarX("pid plot");
   cut72Co->SetVarY("");
   cut72Co->SetTitle("Graph");
   cut72Co->SetFillStyle(1000);
   cut72Co->SetPoint(0,1070.56,526.706);
   cut72Co->SetPoint(1,1030.78,517.252);
   cut72Co->SetPoint(2,1000.6,507.168);
   cut72Co->SetPoint(3,969.053,500.235);
   cut72Co->SetPoint(4,910.067,500.866);
   cut72Co->SetPoint(5,884.003,507.168);
   cut72Co->SetPoint(6,916.925,520.403);
   cut72Co->SetPoint(7,941.617,530.487);
   cut72Co->SetPoint(8,971.797,533.008);
   cut72Co->SetPoint(9,1023.92,533.639);
   cut72Co->SetPoint(10,1056.85,526.706);
   cut72Co->SetPoint(11,1070.56,526.706);



   Correlations = new TObjArray;

   //   Correlations->add(new TH1F("Name","title",bins, low, high));
   Correlations->Add(new TH2F ("PID","pid plot",1500,0,1500,400,400,800));
   Correlations->Add(new TH2F ("ZN_PID","pid gated on 78Zn",1500,0,1500,400,400,800));
   Correlations->Add(new TH2F ("CO_PID","pid gated on 72Co",1500,0,1500,400,400,800));
   Correlations->Add(new TH2F ("CO72_PID","pid gated on 72Co",1500,0,1500,400,400,800));
   Correlations->Add(new TH1F("IMPLANT_GAMMAS","gammas correlated with 78Zn implants", 4000, 0, 2000));
   Correlations->Add(new TH1F("DECAY_CURVE","Time difference between 72Co implant and correlated decay (1ms)", 500., 0., 500.));
   Correlations->Add(new TH2F("GE_VS_DECAY","Decay gammas vs decay time", 500., 0., 500., 6000.,0.,3000.));
   Correlations->Add(new TH2F("BGDIFF_VS_GE","Beta-gamma tdiff vs. decay gammas", 6000.,0.,3000., 1000., -500., 500.));
   Correlations->Add(new TH2F("UG_N_QDC_VS_CORTOF", "Neutron qdc vs corTof - ungated", 2100, -50, 1000 ,30000, 0, 30000));
   Correlations->Add(new TH2F("N_QDC_VS_TOF", "Neutron qdc vs Tof", 2100, -50, 1000 ,30000, 0, 30000));
   Correlations->Add(new TH2F("N_QDC_VS_CORTOF", "Neutron qdc vs corTof", 2100, -50, 1000, 30000, 0, 30000));
   Correlations->Add(new TH2F("FAST_N_QDC_VS_CORTOF", "Neutron qdc vs corTof - short decay time", 2100, -50, 1000, 30000, 0, 30000));
   Correlations->Add(new TH2F("SLOW_N_QDC_VS_CORTOF", "Neutron qdc vs corTof - long decay time", 2100, -50, 1000, 30000, 0, 30000));

   TIter next(Correlations);

   while( TH1* hist=(TH1*)next() ){
     GetOutputList()->Add(hist);
   }
  
   while( TH2* hist=(TH2*)next() ){
     GetOutputList()->Add(hist);
   }
}

Bool_t CoSelector::Process(Long64_t entry)
{
   fReader.SetLocalEntry(entry);

   Bool_t hasDecay = false;
   Bool_t hasImplant = false;
   Bool_t hasCoDecay = false;
   Bool_t hasFastDecay = false;
   Bool_t hasSlowDecay = false;


   if (implant.Get() /*&&  pspmt->PidEvent.position < 1070 && pspmt->PidEvent.position > 950*/)
     hasImplant = true;

   if (decay.Get())
     hasDecay = true;


   Bool_t has78Zn = hasImplant && cut78Zn->IsInside(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z);

   if (hasImplant){
     ((TH2F*)Correlations->FindObject("PID"))->Fill(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z);
   }

   if (has78Zn) {
     ((TH2F*)Correlations->FindObject("ZN_PID"))->Fill(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z);
     // int i = 0;
     for (auto ge_it = ge_events.begin(); ge_it != ge_events.end(); ge_it++) {
       ((TH1F*)Correlations->FindObject("IMPLANT_GAMMAS"))->Fill(ge_it->energy);
       // i++;
     }
     //if (i > 0)
       // cout<<"gamma multiplicity: "<<i<<endl;     

   }

   if (hasImplant && pspmt->PidEvent.nuclear_z > 487 && pspmt->PidEvent.nuclear_z < 532) {
     ((TH2F*)Correlations->FindObject("CO_PID"))->Fill(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z);
   }

   if (hasImplant && cut72Co->IsInside(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z)){
     ((TH2F*)Correlations->FindObject("CO72_PID"))->Fill(pspmt->PidEvent.mass_charge, pspmt->PidEvent.nuclear_z);
   }



   if (hasDecay) {
     for (auto imp_it = past_events.begin(); imp_it != past_events.end(); imp_it++){
       if (imp_it->pixel.first > 5 && imp_it->pixel.first < 17 && imp_it->pixel.second > 7 && imp_it->pixel.second < 18){
         if (pspmt->pixel.first - imp_it->pixel.first >= -1 && pspmt->pixel.first - imp_it->pixel.first <= 1 && pspmt->pixel.second - imp_it->pixel.second >= -1 && pspmt->pixel.second - imp_it->pixel.second <= 1) {
           if (pspmt->timestamp - imp_it->timestamp > 2000){
             if (cut72Co->IsInside(imp_it->PidEvent.mass_charge, imp_it->PidEvent.nuclear_z)){
               hasCoDecay = true;
               if (pspmt->timestamp - imp_it->timestamp < 150000000) hasFastDecay = true;
               if (pspmt->timestamp - imp_it->timestamp > 250000000) hasSlowDecay = true;
               ((TH1F*)Correlations->FindObject("DECAY_CURVE"))->Fill((pspmt->timestamp - imp_it->timestamp) / 1000000 );
               
               for (auto ge_it = ge_events.begin(); ge_it != ge_events.end(); ge_it++){
                 if (ge_it->time - pspmt->timestamp > -150){
                   ((TH2F*)Correlations->FindObject("GE_VS_DECAY"))->Fill((pspmt->timestamp - imp_it->timestamp) / 1000000, ge_it->energy);
                   ((TH2F*)Correlations->FindObject("BGDIFF_VS_GE"))->Fill(ge_it->energy, (ge_it->time - pspmt->timestamp));
                 }
               }
             }
           }
         }
       }
     }
   }



   
   for (auto van_it = vandle.begin(); van_it != vandle.end(); van_it++){
     ((TH2F*)Correlations->FindObject("UG_N_QDC_VS_CORTOF"))->Fill(van_it->corTof, van_it->qdc);
     if (hasCoDecay){
       if (hasFastDecay) {
         ((TH2F*)Correlations->FindObject("FAST_N_QDC_VS_CORTOF"))->Fill(van_it->corTof, van_it->qdc);
       }
       if (hasSlowDecay) {
         ((TH2F*)Correlations->FindObject("SLOW_N_QDC_VS_CORTOF"))->Fill(van_it->corTof, van_it->qdc);
       }
       ((TH2F*)Correlations->FindObject("N_QDC_VS_TOF"))->Fill(van_it->tof, van_it->qdc);
       ((TH2F*)Correlations->FindObject("N_QDC_VS_CORTOF"))->Fill(van_it->corTof, van_it->qdc);
       }
   }
   






   return kTRUE;
}

void CoSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void CoSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  std::stringstream filename;
  filename<<outputFilePrefix<<"_test.root";
  outfile = new TFile(filename.str().c_str(),"RECREATE");

  TIter next(GetOutputList());
  while (TObject* obj = next()){
    obj->Write();
  }
  outfile->Close();

}
