#include "BM1DProcess.hh"

BM1DProcess::BM1DProcess(Int_t nP) : 
  nSteps (nP), p0(0.5), p1(0.3), _mean(0.0), _sigma(1.0), _x1(100), _x2(300)
{
  randomGenerator = new TRandom();
}

BM1DProcess::~BM1DProcess()
{
  ;
}

void BM1DProcess::Init(){
  t.push_back(0.0);  //let's start at t=0, x=0, you can change it if you vant, please use Set methods
  x.push_back(0.0);
}

void BM1DProcess::Run(){
  for (Int_t i = 1;i < nSteps;i++)
    {

      rand1 = randomGenerator->Uniform();
	if(rand1 < p0) {  //step in time, but no step in x
	  t.push_back(t[i-1] + 1);
	  x.push_back(x[i-1]);
	}
	else {

		if((x[i-1] < _x2) && (x[i-1] > _x1) ){
		
		_mean = 0.7;
		_sigma = 0.2;

	      t.push_back(t[i-1]+1);
	      x.push_back(x[i-1]+ randomGenerator->Gaus(_mean, _sigma)); 
		}

		else {
		_mean = 1.0;
		_sigma = 2.0;
		t.push_back(t[i-1]+1);
		x.push_back(x[i-1]+ randomGenerator->Gaus(_mean, _sigma));
		}
	  }

	}
	
    }
