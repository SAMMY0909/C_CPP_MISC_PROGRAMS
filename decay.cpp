#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <tgmath.h>
#include <cstdio>
#include <fstream>
#include <cstdlib>
//#include <armadillo>
using namespace std;
//using namespace arma;
int main(void){
	double gammaval,m1,m2,m3,S,p;
	const long double hbarcinv=5.03*1e+24;
	const long double c=3.0*1e+24;
	cout<<"Enter m1, m2 ,m3, S in that order:"<<flush;
	cin>>m1>>m2>>m3>>S;
	p=sqrt(pow(m1,4)+pow(m2,4)+pow(m3,4)-2*(pow(m1,2)*pow(m2,2)+pow(m2,2)*pow(m3,2)+pow(m3,2)*pow(m3,2)));
	double funcM(double param){
	;}
	gammaval=((S*p*hbarcinv)/(8*M_PI*pow(m1,2)))*pow(funcM,2);
	cout<<"Decay value is:"<<gammaval;
	return 0;
}

	
	
	
	
	
	
	
