//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 23 13:30:33 2019 by ROOT version 6.14/06
// from TTree eventTree/eventTree
// found on file: files/CoEvents22_0.root
//////////////////////////////////////////////////////////

#ifndef CoSelector_h
#define CoSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TCutG.h>
#include <TString.h>

// Headers needed by this particular selector
#include <string>

#include "ProcessorRootStruc.hpp"

#include <vector>

#include "EventBuilder.hpp"



class CoSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

  TCutG *cut78Zn;
  TCutG *cut72Co;
  TCutG *cut71Co;

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<TString> event_type = {fReader, "event_type"};
   TTreeReaderValue<Bool_t> implant = {fReader, "implant"};
   TTreeReaderValue<Bool_t> decay = {fReader, "decay"};
   // TTreeReaderValue<processor_struct::PID> pid = {fReader, "pid"};
   // TTreeReaderValue<Double_t> nuclear_z = {fReader, "nuclear_z"};
   // TTreeReaderValue<Double_t> mass_charge = {fReader, "mass_charge"};
   // TTreeReaderValue<Double_t> uncorrected_tof = {fReader, "uncorrected_tof"};
   // TTreeReaderValue<Double_t> position = {fReader, "position"};
   TTreeReaderArray<processor_struct::VANDLES> vandle = {fReader, "vandle"};
   // TTreeReaderArray<Double_t> vandle_tof = {fReader, "vandle.tof"};
   // TTreeReaderArray<Double_t> vandle_corTof = {fReader, "vandle.corTof"};
   // TTreeReaderArray<Double_t> vandle_qdcPos = {fReader, "vandle.qdcPos"};
   // TTreeReaderArray<Double_t> vandle_qdc = {fReader, "vandle.qdc"};
   // TTreeReaderArray<Int_t> vandle_barNum = {fReader, "vandle.barNum"};
   // TTreeReaderArray<string> vandle_barType = {fReader, "vandle.barType"};
   // TTreeReaderArray<Double_t> vandle_tdiff = {fReader, "vandle.tdiff"};
   // TTreeReaderArray<unsigned int> vandle_sNum = {fReader, "vandle.sNum"};
   // TTreeReaderArray<Int_t> vandle_vMulti = {fReader, "vandle.vMulti"};
   // TTreeReaderArray<Double_t> vandle_sTime = {fReader, "vandle.sTime"};
   // TTreeReaderArray<Double_t> vandle_sQdc = {fReader, "vandle.sQdc"};
   TTreeReaderArray<processor_struct::CLOVERS> ge_events = {fReader, "ge_events"};
  // TTreeReaderArray<Double_t> ge_events_energy = {fReader, "ge_events.energy"};
   // TTreeReaderArray<Double_t> ge_events_rawEnergy = {fReader, "ge_events.rawEnergy"};
   // TTreeReaderArray<Double_t> ge_events_time = {fReader, "ge_events.time"};
   // TTreeReaderArray<Int_t> ge_events_detNum = {fReader, "ge_events.detNum"};
   // TTreeReaderArray<Int_t> ge_events_cloverNum = {fReader, "ge_events.cloverNum"};
   TTreeReaderValue<PspmtEvent> pspmt = {fReader, "current_event"};
   // TTreeReaderValue<Bool_t> wanted_implant = {fReader, "wanted_implant"};
   // TTreeReaderValue<Double_t> xa = {fReader, "xa"};
   // TTreeReaderValue<Double_t> xb = {fReader, "xb"};
   // TTreeReaderValue<Double_t> ya = {fReader, "ya"};
   // TTreeReaderValue<Double_t> yb = {fReader, "yb"};
   // TTreeReaderValue<Double_t> timestamp = {fReader, "timestamp"};
   // TTreeReaderValue<Double_t> pos_first = {fReader, "pos.first"};
   // TTreeReaderValue<Double_t> pos_second = {fReader, "pos.second"};
   // TTreeReaderValue<Int_t> pixel_first = {fReader, "pixel.first"};
   // TTreeReaderValue<Int_t> pixel_second = {fReader, "pixel.second"};
   TTreeReaderArray<PspmtEvent> past_events = {fReader, "past_events"};
   // TTreeReaderArray<Bool_t> past_events_wanted_implant = {fReader, "past_events.wanted_implant"};
   // TTreeReaderArray<Double_t> past_events_xa = {fReader, "past_events.xa"};
   // TTreeReaderArray<Double_t> past_events_xb = {fReader, "past_events.xb"};
   // TTreeReaderArray<Double_t> past_events_ya = {fReader, "past_events.ya"};
   // TTreeReaderArray<Double_t> past_events_yb = {fReader, "past_events.yb"};
   // TTreeReaderArray<Double_t> past_events_timestamp = {fReader, "past_events.timestamp"};
   // TTreeReaderArray<Double_t> past_events_pos_first = {fReader, "past_events.pos.first"};
   // TTreeReaderArray<Double_t> past_events_pos_second = {fReader, "past_events.pos.second"};
   // TTreeReaderArray<Int_t> past_events_pixel_first = {fReader, "past_events.pixel.first"};
   // TTreeReaderArray<Int_t> past_events_pixel_second = {fReader, "past_events.pixel.second"};


  CoSelector(TTree */*tree name*/ =0) { }
   virtual ~CoSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

  std::string outputFilePrefix;
  TObjArray* Correlations;
  TFile* outfile;

   ClassDef(CoSelector,0);

};

#endif

#ifdef CoSelector_cxx
void CoSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t CoSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef CoSelector_cxx
