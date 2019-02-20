#pragma once


#include "region_particle.h"
#include <TString.h>
#include <TChain.h>
#include <map>


namespace hiporoot {
  
  class HipoROOTOut {

    
  public :
    HipoROOTOut(TString filename);
    virtual ~HipoROOTOut();
    
    void AddAction(TString varExp,TString condExp="1");
    void CompileAction();
    void CleanAction();
    void ReplaceMacroText(TString from,TString to);
    //  virtual TString ExpandVars(TString varExp0,TString seperator){return varExp0;};    
    virtual TString ExpandExpression(TString varExp0,TString seperator);    
    virtual void Loop()=0;
    
    //  virtual Double_t Action()=0;
    virtual Bool_t Condition(){return kTRUE;}

    TString HipoFileName(){return _hipoFileName;}
    TString NextFile();
    Bool_t IsMoreFiles();
    TChain* GetChain(){return &_chain;}


    TString ExpandVars(TString varExp0,TString seperator);
    TString ExpandPart(TString exp);
    TString ExpandParenthesis(TString varExp0,TString seperator);
    TString AddParenthesis(TString varExp0);
    vector<TString> RemoveArithmetic(TString& expr);


  protected :
    
    TString _tempActionName;
    TString _actionClassName;
    std::map<TString,TString> _mapOfParts;

  private :

    TString _hipoFileName;
    TString _curMacro;
    TString _tempDir="~/.hiporoot";
    Int_t _Nactions=0;
    Int_t _Nruns=0;
    TChain _chain;
    Int_t _iHipoFile=0;
    
  };//class HipoROOTOut
  
}
