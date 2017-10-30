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
		
		_mean = 0.5;
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


void BM1DProcess::Run(Int_t nRun){

Double_t g1, g2;
Int_t index,j;

std::cout << "BM1DProcess::Run(Int_t nRun)" << std::endl;
for (j = 0; j < nRun; j++){
		

	x.push_back(0.0);
	t.push_back(0.0);

for (Int_t i = 1;i < nSteps;i++){
	
	index = j*nSteps+i;

	std::cout << " i: " << index << " t: "<< t[index]; 

      rand1 = randomGenerator->Uniform();
	if(rand1 < p0) {  //step in time, but no step in x
	  t.push_back(i + 1);
	  x.push_back(x[index-1]);
		std::cout << " x : " << x[index] << std::endl;
	
	}
	else {

		if((x[i-1] < _x2) && (x[i-1] > _x1) ){
		
		_mean = 0.5;
		_sigma = 0.2;
		g1 = randomGenerator->Gaus(_mean, _sigma);
	      t.push_back(i+1);
	      x.push_back(x[index-1]+ g1); 
		std::cout << " g : " << g1 << " x : " << x[index] << std::endl;
		}

		else {
		_mean = 1.0;
		_sigma = 2.0;
		g2 = randomGenerator->Gaus(_mean, _sigma);
		t.push_back(i+1);
		x.push_back(x[index-1]+ g2);
		
		std::cout << " g : " << g2 << " x : " << x[index] << std::endl;
		}
	  }

	}
  }

//for(Int_t j = 0; j < t.size(); j++) 
//	std::cout << x[j] <<" "<<t[j] <<" " << j << std::endl;
}
