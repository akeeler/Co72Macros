#ifndef EVENT_BUILDER_H
#define EVENT_BUILDER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <ProcessorRootStruc.hpp>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TCutG.h>

#include "TFile.h"
#include "TTree.h"
#include "TApplication.h"
#include "TROOT.h"
#include "TSystem.h"

//#include "PspmtEvent.hpp"
#include "ProcessorRootStruc.hpp"

std::pair<double, double> CalculatePosition(double &xa, double &xb, double &ya, double &yb, bool &lowgain);
std::pair<int, int> CalculatePixel(std::pair<double, double> &position);

void EventBuilder(TFile* file, std::string outfile);

struct PspmtEvent {

  processor_struct::PID PidEvent;

  bool wanted_implant = false;
  double timestamp = -999;
  std::pair<double, double> pos = std::make_pair(-20, -20);
  std::pair<int, int> pixel = std::make_pair(-20, -20);

};

TCutG *cut72Co;
TCutG *cut78Zn;



#endif
