#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <armadillo>
#include <math.h>
#include <cmath>
using namespace std;
using namespace arma;
double funcM(vec ,vec ,vec ,vec );// amplitude function
int main(void){
	double dsigdomeg,m1,m2,S;// m1 and m2 are the mass of incident particles
	vec pi,pf,p1,p2,p3,p4;
	int n;// allocation size of column vector
	do{
	cout<<"Enter the number of dimensions of scat prob of A+A=======>B+B type two particle collision:"<<flush;
	cin>>n;
}while(n<=0);
//setting array size
	pi.set_size(n);
	pf.set_size(n);
	p1.set_size(n);
	p2.set_size(n);
	p3.set_size(n);
	p4.set_size(n);		
	const long double c=2.99792458*1e+8;// proportionality constant. Refer Griffiths for formula PG430 B.2.1.
	const long double c1=1.581880655;//c1*1e-54.
	cout<<"Enter m1, m2,S in that order:"<<flush; // S is the structure factor
	cin>>m1>>m2>>S;
	//input files for several data
	ifstream myfile0;
    myfile0.open ("mrx3.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile0 ("mrx3.txt");
	
	ifstream myfile;
    myfile.open ("mrx4.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile ("mrx4.txt");
	
	ifstream myfile1;
    myfile1.open ("mrx5.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile1 ("mrx5.txt");
	
	ifstream myfile2;
    myfile2.open ("mrx6.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile2 ("mrx6.txt");
	
	ifstream myfile3;
    myfile3.open ("mrx7.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile3 ("mrx7.txt");
	
	ifstream myfile4;
    myfile4.open ("mrx8.txt", fstream::in |fstream::out |fstream::app);
	ifstream outFile4 ("mrx8.txt");
	//loading data from files to arrays
	
	pi.load("mrx3.txt");//pi is either of incoming momentum
	pf.load("mrx4.txt");//pf is either of outgoing momentum
	p1.load("mrx5.txt");//p1 is incoming momentum of incident particle
	p2.load("mrx6.txt");//p2 is incoming momentum of another incident particle
	p3.load("mrx7.txt");//p3 is outgoing momentum of outgoing particle
	p4.load("mrx8.txt");//p4 is outgoing momentum of another outgoing particle
	
	double val=m1*m2*pow(c,2);
	
		double sum=(c/sqrt(abs(dot(p1,p1))))*sqrt(dot(p1,p2)-pow(val,2));
		dsigdomeg=c1*((S*pow(funcM(p1,p2,p3,p4),2))/pow(sum,2))*(sqrt(abs(dot(pf,pf))))/(sqrt(abs(dot(pi,pi))));//differential cross section
	
	
	
	cout<<"Differential CS is:"<<dsigdomeg<<"*1e-54"<<endl;
	return 0;
}
double funcM(vec p1,vec p2,vec p3,vec p4){//GRIFFITHS PARTICLE PHYSICS, PG216 WITH M_SUB(C)=0
		const double g =1.0;// g is weak coupling constant.
		double val;
		vec pd1,pd2;
		pd1=p4-p2;
		pd2=p3-p2;
		double	s1,s2;
		s1=dot(pd1,pd1);
		s2=dot(pd2,pd2);
		s1=double(s1);
		s2=double(s2);
		
		val=(pow(g,2)/(s1))+(pow(g,2)/(s2));
		
	return val;// returns functional value for amplitude M.
	}
//Compilation: g++ -Wall -std=c++11 -fpermissive diffcs.cpp -o diffcs -larmadillo
