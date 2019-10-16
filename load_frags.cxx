

#include <iostream>
#include <fstream>
#include <string>

#include "TSystem.h"
#include "TObject.h"
#include "TROOT.h"
#include "TProof.h"


TChain *DDchain;

TProof *pr;

int load_frags(const Bool_t proof=false){

  DDchain= new TChain("eventTree");

       // for (auto it=0; it<28 ; it++){
       //  std::stringstream ss;
       
       //  ss <<"/home/akeeler/rootFiles/frag010-"<<it<<".root";
       //    DDchain->Add(ss.str().c_str());
       //    ss.str("");
          
       //  }
       // for(auto it=0; it < 28; it++){
       //   std::stringstream ss;
       //   ss <<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents10_"<<it<<".root";
       //   DDchain->Add(ss.str().c_str());
       //   ss.str("");
       // }
       // for (auto it=0; it < 20; it++){
       //   if(it == 12 || it == 8) continue;
       //   std::stringstream ss;
       //   ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents11_"<<it<<".root";
       //   DDchain->Add(ss.str().c_str());
       //   ss.str("");
       // }
       // for (auto it=0; it < 8; it++){
       //   if(it == 1) continue;
       //   std::stringstream ss;
       //   ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents12_"<<it<<".root";
       //   DDchain->Add(ss.str().c_str());
       //   ss.str("");
       // }
  for (auto it=0; it < 5; it++){
    if (it == 4) continue;
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents30_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 11; it++){
    if (it == 8) continue;
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents31_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 8; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents32_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }

  for (auto it=0; it < 10; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents43_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 10; it++){
    //    if (it == 8) continue;
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents44_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 8; it++){
    if (it == 4) continue;
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents45_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 12; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents46_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 11; it++){
    if (it == 3 || it == 8) continue;
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents47_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
       }
  for (auto it=0; it < 5; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents48_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 13; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents49_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 12; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents50_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 16; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents51_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 13; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents52_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  for (auto it=0; it < 12; it++){
    std::stringstream ss;
    ss<<"/SCRATCH/DRunScratch2/ak_tmp/frag_root/CoEvents53_"<<it<<".root";
    DDchain->Add(ss.str().c_str());
    ss.str("");
  }
  
       /*
  std::stringstream ss;
  ss <<"/home/akeeler/tests/co_tests/frag11.root";
  DDchain->Add(ss.str().c_str());
*/


      gDirectory->Add(DDchain);
      
      if (proof){
        pr = TProof::Open("lite://","workers=35");
        gProof->Load("/home/akeeler/paass/install/lib/libSysRootStrucLib.so",kTRUE);
        DDchain->SetProof();
      }
      std::cout << "Number of TTrees added to DDchain: " << DDchain->GetNtrees() << std::endl;
      
      return 0;
}
