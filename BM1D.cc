#include <iostream>
#include "BM1DProcess.hh"
#include "Plotter.hh"
#include "TApplication.h"

using namespace std;

int main(int argc, char* argv[])
{
  TApplication App("tapp", &argc, argv);
  Int_t n = 1000;
  BM1DProcess *myBM1DProcess = new BM1DProcess(n);

	myBM1DProcess->SetP0(0.1);
	myBM1DProcess->SetP1(0.5);
	//myBM1DProcess->SetMean(0.2);
	//myBM1DProcess->SetSigma(2.0);

  myBM1DProcess->Init();
  myBM1DProcess->Run();
  Plotter* myPlotter = new Plotter();
  myPlotter->Plot(n, myBM1DProcess->GetT(), myBM1DProcess->GetX());

  App.Run();
  return 0;
}
