#include "TFile.h" //clase usada para tomar el archivo .dat y crear el archivo root.
#include "TTree.h" //clase usada para crear las ramas del arbol.
#include <string>  
#include <fstream>
#include <string>

using namespace std;

int main()
{

  string a;
  string b;

  b = "totalBAIRES2MADRID.root";
  a = "totalBAIRES2MADRID.dat";


  TFile *f = new TFile(b.c_str(),"RECREATE"); //creacion de archivos .root
  TTree *T = new TTree("T","data from ascii file"); //creacion de los arboles

  Long64_t nlines = 
	T->ReadFile(a.c_str(), "momentumGeV/d:NGamma/l:NPositron:NElectron:NMuPlus:NMuMinus:NPi0:NPiPlus:NPiMinus:NNeutron:NProton:NAntiProton:NOthers:NTotal"); 

  T->Write(); //escribe
  f->Close();

  return 0;
}
