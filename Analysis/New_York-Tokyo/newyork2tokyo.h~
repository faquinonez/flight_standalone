//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jun 15 18:04:25 2016 by ROOT version 5.34/36
// from TChain T/
//////////////////////////////////////////////////////////

#ifndef newyork2tokyo_h
#define newyork2tokyo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class newyork2tokyo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        momentumGeV;
   ULong64_t       NGamma;
   ULong64_t       NPositron;
   ULong64_t       NElectron;
   ULong64_t       NMuPlus;
   ULong64_t       NMuMinus;
   ULong64_t       NPi0;
   ULong64_t       NPiPlus;
   ULong64_t       NPiMinus;
   ULong64_t       NNeutron;
   ULong64_t       NProton;
   ULong64_t       NAntiProton;
   ULong64_t       NOthers;
   ULong64_t       NTotal;

   // List of branches
   TBranch        *b_momentumGeV;   //!
   TBranch        *b_NGamma;   //!
   TBranch        *b_NPositron;   //!
   TBranch        *b_NElectron;   //!
   TBranch        *b_NMuPlus;   //!
   TBranch        *b_NMuMinus;   //!
   TBranch        *b_NPi0;   //!
   TBranch        *b_NPiPlus;   //!
   TBranch        *b_NPiMinus;   //!
   TBranch        *b_NNeutron;   //!
   TBranch        *b_NProton;   //!
   TBranch        *b_NAntiProton;   //!
   TBranch        *b_NOthers;   //!
   TBranch        *b_NTotal;   //!

   newyork2tokyo(TTree *tree=0);
   virtual ~newyork2tokyo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef newyork2tokyo_cxx
newyork2tokyo::newyork2tokyo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("T",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("T","");
      chain->Add("totalNEWYORK2TOKYO.root/T");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

newyork2tokyo::~newyork2tokyo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t newyork2tokyo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t newyork2tokyo::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void newyork2tokyo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("momentumGeV", &momentumGeV, &b_momentumGeV);
   fChain->SetBranchAddress("NGamma", &NGamma, &b_NGamma);
   fChain->SetBranchAddress("NPositron", &NPositron, &b_NPositron);
   fChain->SetBranchAddress("NElectron", &NElectron, &b_NElectron);
   fChain->SetBranchAddress("NMuPlus", &NMuPlus, &b_NMuPlus);
   fChain->SetBranchAddress("NMuMinus", &NMuMinus, &b_NMuMinus);
   fChain->SetBranchAddress("NPi0", &NPi0, &b_NPi0);
   fChain->SetBranchAddress("NPiPlus", &NPiPlus, &b_NPiPlus);
   fChain->SetBranchAddress("NPiMinus", &NPiMinus, &b_NPiMinus);
   fChain->SetBranchAddress("NNeutron", &NNeutron, &b_NNeutron);
   fChain->SetBranchAddress("NProton", &NProton, &b_NProton);
   fChain->SetBranchAddress("NAntiProton", &NAntiProton, &b_NAntiProton);
   fChain->SetBranchAddress("NOthers", &NOthers, &b_NOthers);
   fChain->SetBranchAddress("NTotal", &NTotal, &b_NTotal);
   Notify();
}

Bool_t newyork2tokyo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void newyork2tokyo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t newyork2tokyo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef newyork2tokyo_cxx
