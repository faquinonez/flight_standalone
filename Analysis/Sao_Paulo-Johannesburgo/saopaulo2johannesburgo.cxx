#define saopaulo2johannesburgo_cxx
#include "saopaulo2johannesburgo.h"
#include <TH2.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <TMath.h>

#include <iostream>

using namespace std;

Double_t calculaN(Double_t p, Double_t m, Double_t lambda1, Double_t lambda2);

void saopaulo2johannesburgo::Loop()
{
  Double_t  m_e   =   0.510998928; // MeV
  Double_t Dm_e   =   0.000000011; // MeV
  Double_t  m_mu  = 105.6583715; // MeV
  Double_t Dm_mu  =   0.0000035; // MeV
  

  Double_t  m_tau = 1776.82; // MeV
  Double_t Dm_tau =    0.16; // MeV
  Double_t  m_pi_plus = 139.57018; // MeV 
  Double_t Dm_pi_plus =   0.00035; // MeV
  Double_t  m_pi_0 = 134.9766; // MeV 
  Double_t Dm_pi_0 =   0.0006; // MeV
  Double_t  m_proton = 938.272046; // MeV
  Double_t Dm_proton =   0.000021; // MeV
  Double_t  m_neutron = 939.565379; // MeV
  Double_t Dm_neutron =   0.000021; // MeV


   fChain->SetBranchStatus("*",1);  // enable all branches
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Double_t totalNCherenkov_electron_uvA = 0.0;
   Double_t totalNCherenkov_electron_uvB = 0.0;
   Double_t totalNCherenkov_electron_uvC = 0.0;
   Double_t totalNCherenkov_positron_uvA = 0.0;
   Double_t totalNCherenkov_positron_uvB = 0.0;
   Double_t totalNCherenkov_positron_uvC = 0.0;
   Double_t totalNCherenkov_muminus_uvA = 0.0;
   Double_t totalNCherenkov_muminus_uvB = 0.0;
   Double_t totalNCherenkov_muminus_uvC = 0.0;
   Double_t totalNCherenkov_muplus_uvA = 0.0;
   Double_t totalNCherenkov_muplus_uvB = 0.0;
   Double_t totalNCherenkov_muplus_uvC = 0.0;
   Double_t totalNCherenkov_p_uvA = 0.0;
   Double_t totalNCherenkov_p_uvB = 0.0;
   Double_t totalNCherenkov_p_uvC = 0.0;
   Double_t totalNCherenkov_pbar_uvA = 0.0;
   Double_t totalNCherenkov_pbar_uvB = 0.0;
   Double_t totalNCherenkov_pbar_uvC = 0.0;

   Double_t* momentumMeVArray = new Double_t[nentries];
   Double_t* NCherenkov_electron_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_electron_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_electron_uvC_Array = new Double_t[nentries];
   Double_t* NCherenkov_positron_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_positron_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_positron_uvC_Array = new Double_t[nentries];
   Double_t* NCherenkov_muminus_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_muminus_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_muminus_uvC_Array = new Double_t[nentries];
   Double_t* NCherenkov_muplus_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_muplus_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_muplus_uvC_Array = new Double_t[nentries];
   Double_t* NCherenkov_p_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_p_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_p_uvC_Array = new Double_t[nentries];
   Double_t* NCherenkov_pbar_uvA_Array = new Double_t[nentries];
   Double_t* NCherenkov_pbar_uvB_Array = new Double_t[nentries];
   Double_t* NCherenkov_pbar_uvC_Array = new Double_t[nentries];

   for(Long64_t i; i<nentries; i++){
     momentumMeVArray[i]=0;
     NCherenkov_electron_uvA_Array[i]=0;
     NCherenkov_electron_uvB_Array[i]=0;
     NCherenkov_electron_uvC_Array[i]=0;
     NCherenkov_positron_uvA_Array[i]=0;
     NCherenkov_positron_uvB_Array[i]=0;
     NCherenkov_positron_uvC_Array[i]=0;
     NCherenkov_muminus_uvA_Array[i]=0;
     NCherenkov_muminus_uvB_Array[i]=0;
     NCherenkov_muminus_uvC_Array[i]=0;
     NCherenkov_muplus_uvA_Array[i]=0;
     NCherenkov_muplus_uvB_Array[i]=0;
     NCherenkov_muplus_uvC_Array[i]=0;
     NCherenkov_p_uvA_Array[i]=0;
     NCherenkov_p_uvB_Array[i]=0;
     NCherenkov_p_uvC_Array[i]=0;
     NCherenkov_pbar_uvA_Array[i]=0;
     NCherenkov_pbar_uvB_Array[i]=0;
     NCherenkov_pbar_uvC_Array[i]=0;

   }


//   Double_t totalNCherenkov_e = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //cout << calculaN( momentum, m_e, 570E-9, 300E-9 ) << endl;
      momentumMeVArray[ jentry ] = momentumGeV*1000;
//      NCherenkov_electron_uvA_Array[ jentry ] = nElectronPositron * calculaN(momentum,m_e,400E-9,315E-9);
      NCherenkov_electron_uvA_Array[ jentry ] = NElectron * calculaN(momentumGeV*1000,m_e,400E-9,315E-9);
      NCherenkov_positron_uvA_Array[ jentry ] = NPositron * calculaN(momentumGeV*1000,m_e,400E-9,315E-9);
      NCherenkov_muminus_uvA_Array[ jentry ] = NMuMinus * calculaN(momentumGeV*1000,m_mu,400E-9,315E-9);
      NCherenkov_muplus_uvA_Array[ jentry ] = NMuPlus * calculaN(momentumGeV*1000,m_mu,400E-9,315E-9);
      NCherenkov_p_uvA_Array[ jentry ] = NProton * calculaN(momentumGeV*1000,m_proton,400E-9,315E-9);
      NCherenkov_pbar_uvA_Array[ jentry ] = NAntiProton * calculaN(momentumGeV*1000,m_proton,400E-9,315E-9);

      NCherenkov_electron_uvB_Array[ jentry ] = NElectron * calculaN(momentumGeV*1000,m_e,315E-9,280E-9);
      NCherenkov_positron_uvB_Array[ jentry ] = NPositron * calculaN(momentumGeV*1000,m_e,315E-9,280E-9);
      NCherenkov_muminus_uvB_Array[ jentry ] = NMuMinus * calculaN(momentumGeV*1000,m_mu,315E-9,280E-9);
      NCherenkov_muplus_uvB_Array[ jentry ] = NMuPlus * calculaN(momentumGeV*1000,m_mu,315E-9,280E-9);
      NCherenkov_p_uvB_Array[ jentry ] = NProton * calculaN(momentumGeV*1000,m_proton,315E-9,280E-9);
      NCherenkov_pbar_uvB_Array[ jentry ] = NAntiProton * calculaN(momentumGeV*1000,m_proton,315E-9,280E-9);

      NCherenkov_electron_uvC_Array[ jentry ] = NElectron * calculaN(momentumGeV*1000,m_e,280E-9,100E-9);
      NCherenkov_positron_uvC_Array[ jentry ] = NPositron * calculaN(momentumGeV*1000,m_e,280E-9,100E-9);
      NCherenkov_muminus_uvC_Array[ jentry ] = NMuMinus * calculaN(momentumGeV*1000,m_mu,280E-9,100E-9);
      NCherenkov_muplus_uvC_Array[ jentry ] = NMuPlus * calculaN(momentumGeV*1000,m_mu,280E-9,100E-9);
      NCherenkov_p_uvC_Array[ jentry ] = NProton * calculaN(momentumGeV*1000,m_proton,280E-9,100E-9);
      NCherenkov_pbar_uvC_Array[ jentry ] = NAntiProton * calculaN(momentumGeV*1000,m_proton,280E-9,100E-9);

      totalNCherenkov_electron_uvA += NCherenkov_electron_uvA_Array[ jentry ];
      totalNCherenkov_positron_uvA += NCherenkov_positron_uvA_Array[ jentry ];
      totalNCherenkov_muminus_uvA += NCherenkov_muminus_uvA_Array[ jentry ];
      totalNCherenkov_muplus_uvA += NCherenkov_muplus_uvA_Array[ jentry ];
      totalNCherenkov_p_uvA += NCherenkov_p_uvA_Array[ jentry ];
      totalNCherenkov_pbar_uvA += NCherenkov_pbar_uvA_Array[ jentry ];
      totalNCherenkov_electron_uvB += NCherenkov_electron_uvB_Array[ jentry ];
      totalNCherenkov_positron_uvB += NCherenkov_positron_uvB_Array[ jentry ];
      totalNCherenkov_muminus_uvB += NCherenkov_muminus_uvB_Array[ jentry ];
      totalNCherenkov_muplus_uvB += NCherenkov_muplus_uvB_Array[ jentry ];
      totalNCherenkov_p_uvB += NCherenkov_p_uvB_Array[ jentry ];
      totalNCherenkov_pbar_uvB += NCherenkov_pbar_uvB_Array[ jentry ];
      totalNCherenkov_electron_uvC += NCherenkov_electron_uvC_Array[ jentry ];
      totalNCherenkov_positron_uvC += NCherenkov_positron_uvC_Array[ jentry ];
      totalNCherenkov_muminus_uvC += NCherenkov_muminus_uvC_Array[ jentry ];
      totalNCherenkov_muplus_uvC += NCherenkov_muplus_uvC_Array[ jentry ];
      totalNCherenkov_p_uvC += NCherenkov_p_uvC_Array[ jentry ];
      totalNCherenkov_pbar_uvC += NCherenkov_pbar_uvC_Array[ jentry ];

      //cout << NCherenkov_electron_uvA_Array[ jentry ] << endl;
   }

   cout << "Toal N Cherenkov photons band UV-A produced by e-: " << totalNCherenkov_electron_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by e-: " << totalNCherenkov_electron_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by e-: " << totalNCherenkov_electron_uvC << endl;
   cout << "Toal N Cherenkov photons band UV-A produced by e+: " << totalNCherenkov_positron_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by e+: " << totalNCherenkov_positron_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by e+: " << totalNCherenkov_positron_uvC << endl;
   cout << "Toal N Cherenkov photons band UV-A produced by mu-: " << totalNCherenkov_muminus_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by mu-: " << totalNCherenkov_muminus_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by mu-: " << totalNCherenkov_muminus_uvC << endl;
   cout << "Toal N Cherenkov photons band UV-A produced by mu+: " << totalNCherenkov_muplus_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by mu+: " << totalNCherenkov_muplus_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by mu+: " << totalNCherenkov_muplus_uvC << endl;
   cout << "Toal N Cherenkov photons band UV-A produced by protons: " << totalNCherenkov_p_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by protons: " << totalNCherenkov_p_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by protons: " << totalNCherenkov_p_uvC << endl;
   cout << "Toal N Cherenkov photons band UV-A produced by antiprotons: " << totalNCherenkov_pbar_uvA << endl;
   cout << "Toal N Cherenkov photons band UV-B produced by antiprotons: " << totalNCherenkov_pbar_uvB << endl;
   cout << "Toal N Cherenkov photons band UV-C produced by antiprotons: " << totalNCherenkov_pbar_uvC << endl;


  TGraph* gelectronuva = new TGraph(nentries, momentumMeVArray, NCherenkov_electron_uvA_Array);
  TGraph* gelectronuvb = new TGraph(nentries, momentumMeVArray, NCherenkov_electron_uvB_Array);
  TGraph* gelectronuvc = new TGraph(nentries, momentumMeVArray, NCherenkov_electron_uvC_Array);
  TGraph* gpositronuva = new TGraph(nentries, momentumMeVArray, NCherenkov_positron_uvA_Array);
  TGraph* gpositronuvb = new TGraph(nentries, momentumMeVArray, NCherenkov_positron_uvB_Array);
  TGraph* gpositronuvc = new TGraph(nentries, momentumMeVArray, NCherenkov_positron_uvC_Array);
  TGraph* gmuminusuva = new TGraph(nentries, momentumMeVArray, NCherenkov_muminus_uvA_Array);
  TGraph* gmuminusuvb = new TGraph(nentries, momentumMeVArray, NCherenkov_muminus_uvB_Array);
  TGraph* gmuminusuvc = new TGraph(nentries, momentumMeVArray, NCherenkov_muminus_uvC_Array);
  TGraph* gmuplusuva = new TGraph(nentries, momentumMeVArray, NCherenkov_muplus_uvA_Array);
  TGraph* gmuplusuvb = new TGraph(nentries, momentumMeVArray, NCherenkov_muplus_uvB_Array);
  TGraph* gmuplusuvc = new TGraph(nentries, momentumMeVArray, NCherenkov_muplus_uvC_Array);
  TGraph* gpuva = new TGraph(nentries, momentumMeVArray, NCherenkov_p_uvA_Array);
  TGraph* gpuvb = new TGraph(nentries, momentumMeVArray, NCherenkov_p_uvB_Array);
  TGraph* gpuvc = new TGraph(nentries, momentumMeVArray, NCherenkov_p_uvC_Array);
  TGraph* gpbaruva = new TGraph(nentries, momentumMeVArray, NCherenkov_pbar_uvA_Array);
  TGraph* gpbaruvb = new TGraph(nentries, momentumMeVArray, NCherenkov_pbar_uvB_Array);
  TGraph* gpbaruvc = new TGraph(nentries, momentumMeVArray, NCherenkov_pbar_uvC_Array);

  gelectronuva->SetLineWidth(3);
  gelectronuvb->SetLineWidth(3);
  gelectronuvc->SetLineWidth(3);
  gpositronuva->SetLineWidth(3);
  gpositronuvb->SetLineWidth(3);
  gpositronuvc->SetLineWidth(3);
  gmuminusuva->SetLineWidth(3);
  gmuminusuvb->SetLineWidth(3);
  gmuminusuvc->SetLineWidth(3);
  gmuplusuva->SetLineWidth(3);
  gmuplusuvb->SetLineWidth(3);
  gmuplusuvc->SetLineWidth(3);
  gpuva->SetLineWidth(3);
  gpuvb->SetLineWidth(3);
  gpuvc->SetLineWidth(3);
  gpbaruva->SetLineWidth(3);
  gpbaruvb->SetLineWidth(3);
  gpbaruvc->SetLineWidth(3);


  gelectronuva->SetLineColor(3);
  gelectronuvb->SetLineColor(4);
  gelectronuvc->SetLineColor(6);
  gpositronuva->SetLineColor(3);
  gpositronuvb->SetLineColor(4);
  gpositronuvc->SetLineColor(6);
  gmuminusuva->SetLineColor(3);
  gmuminusuvb->SetLineColor(4);
  gmuminusuvc->SetLineColor(6);
  gmuplusuva->SetLineColor(3);
  gmuplusuvb->SetLineColor(4);
  gmuplusuvc->SetLineColor(6);
  gpuva->SetLineColor(3);
  gpuvb->SetLineColor(4);
  gpuvc->SetLineColor(6);
  gpbaruva->SetLineColor(3);
  gpbaruvb->SetLineColor(4);
  gpbaruvc->SetLineColor(6);

  //------------------------------------------------------------------------------------------------
  TCanvas *c1 = new TCanvas("c1","c");
  c1->SetLogx();
  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();

  c1->cd();

  gelectronuvc->Draw("CA");
  gelectronuvb->Draw("C");
  gelectronuva->Draw("C");

  gelectronuvc->GetXaxis()->SetTitle("e- Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gelectronuvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he->SetStats(0);


  TLegend* ley1var = new TLegend(.75,.28,.98,.60);
  ley1var->AddEntry(gelectronuva,"e- banda UV-A","L");
  ley1var->AddEntry(gelectronuvb,"e- banda UV-B","L");
  ley1var->AddEntry(gelectronuvc,"e- banda UV-C","L");
  ley1var->SetFillColor(kWhite);
  ley1var->Draw("SAME");

  c1->cd();
  c1->SetSelected(c1);
  c1->SaveAs("electronUV.png");
  c1->Close();
  //------------------------------------------------------------------------------------------------
  TCanvas *c2 = new TCanvas("c2","c");
  c2->SetLogx();
  c2->SetLogy();
  c2->SetGridx();
  c2->SetGridy();

  c2->cd();

  gpositronuvc->Draw("CA");
  gpositronuvb->Draw("C");
  gpositronuva->Draw("C");

  gpositronuvc->GetXaxis()->SetTitle("e+ Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gpositronuvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he+>SetStats(0);


  TLegend* ley2var = new TLegend(.75,.28,.98,.60);
  ley2var->AddEntry(gpositronuva,"e+ banda UV-A","L");
  ley2var->AddEntry(gpositronuvb,"e+ banda UV-B","L");
  ley2var->AddEntry(gpositronuvc,"e+ banda UV-C","L");
  ley2var->SetFillColor(kWhite);
  ley2var->Draw("SAME");

  c2->cd();
  c2->SetSelected(c2);
  c2->SaveAs("positronUV.png");
  c2->Close();
  //------------------------------------------------------------------------------------------------
  TCanvas *c3 = new TCanvas("c3","c");
  c3->SetLogx();
  c3->SetLogy();
  c3->SetGridx();
  c3->SetGridy();

  c3->cd();

  gmuminusuvc->Draw("CA");
  gmuminusuvb->Draw("C");
  gmuminusuva->Draw("C");

  gmuminusuvc->GetXaxis()->SetTitle("#mu- Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gmuminusuvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he+>SetStats(0);


  TLegend* ley3var = new TLegend(.75,.28,.98,.60);
  ley3var->AddEntry(gmuminusuva,"#mu- banda UV-A","L");
  ley3var->AddEntry(gmuminusuvb,"#mu- banda UV-B","L");
  ley3var->AddEntry(gmuminusuvc,"#mu- banda UV-C","L");
  ley3var->SetFillColor(kWhite);
  ley3var->Draw("SAME");

  c3->cd();
  c3->SetSelected(c3);
  c3->SaveAs("muminusUV.png");
  c3->Close();
  //------------------------------------------------------------------------------------------------
  TCanvas *c4 = new TCanvas("c4","c");
  c4->SetLogx();
  c4->SetLogy();
  c4->SetGridx();
  c4->SetGridy();

  c4->cd();

  gmuplusuvc->Draw("CA");
  gmuplusuvb->Draw("C");
  gmuplusuva->Draw("C");

  gmuplusuvc->GetXaxis()->SetTitle("#mu+ Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gmuplusuvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he+>SetStats(0);


  TLegend* ley4var = new TLegend(.75,.28,.98,.60);
  ley4var->AddEntry(gmuplusuva,"#mu+ banda UV-A","L");
  ley4var->AddEntry(gmuplusuvb,"#mu+ banda UV-B","L");
  ley4var->AddEntry(gmuplusuvc,"#mu+ banda UV-C","L");
  ley4var->SetFillColor(kWhite);
  ley4var->Draw("SAME");

  c4->cd();
  c4->SetSelected(c4);
  c4->SaveAs("muplusUV.png");
  c4->Close();
  //------------------------------------------------------------------------------------------------
  TCanvas *c5 = new TCanvas("c5","c");
  c5->SetLogx();
  c5->SetLogy();
  c5->SetGridx();
  c5->SetGridy();

  c5->cd();

  gpuvc->Draw("CA");
  gpuvb->Draw("C");
  gpuva->Draw("C");

  gpuvc->GetXaxis()->SetTitle("p Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gpuvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he+>SetStats(0);


  TLegend* ley5var = new TLegend(.75,.28,.98,.60);
  ley5var->AddEntry(gpuva,"p banda UV-A","L");
  ley5var->AddEntry(gpuvb,"p banda UV-B","L");
  ley5var->AddEntry(gpuvc,"p banda UV-C","L");
  ley5var->SetFillColor(kWhite);
  ley5var->Draw("SAME");

  c5->cd();
  c5->SetSelected(c5);
  c5->SaveAs("pUV.png");
  c5->Close();
  //------------------------------------------------------------------------------------------------
  TCanvas *c6 = new TCanvas("c6","c");
  c6->SetLogx();
  c6->SetLogy();
  c6->SetGridx();
  c6->SetGridy();

  c6->cd();

  gpbaruvc->Draw("CA");
  gpbaruvb->Draw("C");
  gpbaruva->Draw("C");

  gpbaruvc->GetXaxis()->SetTitle("pbar Momentum [MeV]");
  //xaxis->SetNdivisions(510);

  gpbaruvc->GetYaxis()->SetTitle("N Fotones Cherenkov");
  //he+>SetStats(0);


  TLegend* ley6var = new TLegend(.75,.28,.98,.60);
  ley6var->AddEntry(gpbaruva,"pbar banda UV-A","L");
  ley6var->AddEntry(gpbaruvb,"pbar banda UV-B","L");
  ley6var->AddEntry(gpbaruvc,"pbar banda UV-C","L");
  ley6var->SetFillColor(kWhite);
  ley6var->Draw("SAME");

  c6->cd();
  c6->SetSelected(c6);
  c6->SaveAs("pbarUV.png");
  c6->Close();

}

Double_t calculaN(Double_t p, Double_t m, Double_t lambda1, Double_t lambda2){
  Double_t alpha   = 7.2973525698E-3; // fine structure constant
//  Double_t lambda1 = 570E-9; // m
//  Double_t lambda2 = 300E-9; // m
  Double_t n_water = 1.33;
  Double_t n_oil_sylicone = 1.58;
  Double_t mc_over_p = m / p;
  Double_t one_over_beta2 = (p*p + m*m)/(p*p);
  Double_t one_over_n2 = 1.0/(n_water*n_water);
  Double_t one_over_n2beta2 = one_over_n2 * one_over_beta2;

  Double_t gamma;
  //Double_t Dt = 11*60*60; // 11 hours in seconds
  Double_t PhantomDiameter = 0.5758823822969723; // m


  //cout << "beta (p=" << p*1E-6 << "TeV)= " << beta << endl;
  //gamma = 1.0 / TMath::Sqrt(1-beta*beta);
  //cout << "gamma(beta) = " << gamma << endl;
  //cout << "1/(n beta)^2 = " << one_over_n2beta2 << endl;
  // Double_t n_w = 1.33;
  //
  // OUTPUT
  Double_t N_Cherenkov;

  if( one_over_n2beta2 >= 1.0 ){
    N_Cherenkov = 0;
  } else {
    N_Cherenkov = 2*TMath::Pi()*alpha
                 *(1.0/lambda2 - 1.0/lambda1)
                 *(1-one_over_n2beta2);
  }

  N_Cherenkov *= PhantomDiameter;
  //cout << "N Cherenkov = " << N_Cherenkov << endl;

  return N_Cherenkov; 
}



