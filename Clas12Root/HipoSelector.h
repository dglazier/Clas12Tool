#ifndef HipoSelector_h
#define HipoSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

#include <TString.h>
#include <TH1.h>
#include <vector>
#include <iostream>

// Headers needed by this particular selector
#include "HipoChain.h"
#include "clas12reader.h"

namespace clas12root{
  using std::cout;
  using std::endl;
  
  
  class HipoSelector : public TSelector {
      public :


      HipoSelector(TString filename) ;
      HipoSelector(HipoChain *chain) ;
      HipoSelector(TTree * /*tree*/ =0); 
      virtual ~HipoSelector() { }
      virtual Int_t   Version() const { return 2; }
      virtual void    Begin(TTree *tree);
      virtual void    SlaveBegin(TTree *tree);
      //    virtual void    Init(TTree *tree);
      //virtual Bool_t  Notify();
      virtual Bool_t  Process(Long64_t entry);
      //virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEnqtry(entry, getall) : 0; }

      Bool_t ProcessEvent();
      
      virtual void    SetOption(const char *option) { fOption = option; }
      virtual void    SetObject(TObject *obj) { fObject = obj; }
      virtual void    SetInputList(TList *input) { fInput = input; }
      virtual TList  *GetOutputList() const { return fOutput; }
      virtual void    SlaveTerminate();
      virtual void    Terminate();


  
    private:

      std::unique_ptr<clas12::clas12reader> _c12;
      HipoChain* _chain=nullptr;

      Int_t _NcurrRecords=0;
      Int_t _iRecord=0;
      Int_t _iFile=0;
      Long64_t _NfileRecords=0;
      
      TH1F* _hist1=nullptr;
      
      ClassDef(clas12root::HipoSelector,0);

    };
}


#endif // #ifdef HipoSelector_cxx
