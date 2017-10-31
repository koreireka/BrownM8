#include <iostream>
#include "BM1DProcess.hh"
#include "Plotter.hh"
#include "TApplication.h"

using namespace std;

int main(int argc, char* argv[])
{
  TApplication App("tapp", &argc, argv);
  Int_t n = 1000;
  Int_t nsample = 50;
  BM1DProcess *myBM1DProcess = new BM1DProcess(n);

	myBM1DProcess->SetP0(0.2);
	//myBM1DProcess->SetP1(0.5);
	//myBM1DProcess->SetMean(0.2);
	//myBM1DProcess->SetSigma(2.0);

  //myBM1DProcess->Init();
  myBM1DProcess->Run(nsample);
  Plotter* myPlotter = new Plotter();
 // myPlotter->Plot(n*nsample, myBM1DProcess->GetT(), myBM1DProcess->GetX());

myPlotter->MultiPlot(n,nsample, myBM1DProcess->GetT(), myBM1DProcess->GetX());

  App.Run();
  return 0;
}
