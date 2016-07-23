#include <TStyle.h>
#include <string>
#include <THStack.h>
#include <TH1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <TLegend.h>
#include <TMath.h>
#include <iostream>
#include "saopaulo2johannesburgo.h"

using namespace std;


int main()
{
  Int_t icol=0;
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetFrameFillColor(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetStatColor(icol);

  //gStyle->SetPaperSize(36,30);
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.26);
  gStyle->SetPadBottomMargin(0.20);
  gStyle->SetPadLeftMargin(0.20);
  gStyle->SetTitleXOffset(1.3);
  gStyle->SetTitleYOffset(1.3);
  Int_t font=42;
  Double_t tsize=0.05;
  gStyle->SetTextFont(font);
  gStyle->SetTextSize(tsize);
  gStyle->SetLabelFont(font,"x");
  gStyle->SetTitleFont(font,"x");
  gStyle->SetLabelFont(font,"y");
  gStyle->SetTitleFont(font,"y");
  gStyle->SetLabelFont(font,"z");
  gStyle->SetTitleFont(font,"z");
  gStyle->SetLabelSize(tsize,"x");
  gStyle->SetTitleSize(tsize,"x");
  gStyle->SetLabelSize(tsize,"y");
  gStyle->SetTitleSize(tsize,"y");
  gStyle->SetLabelSize(tsize,"z");
  gStyle->SetTitleSize(tsize,"z");
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(0.7);
  gStyle->SetHistLineWidth(2);
  gStyle->SetLineStyleString(2,"[12 12]");
  //gStyle->SetEndErrorSize(0.);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1111111);
  //gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPalette(1);

  saopaulo2johannesburgo objeto;
  objeto.Loop();

  return 0;
}
