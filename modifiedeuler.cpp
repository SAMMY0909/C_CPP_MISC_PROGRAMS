//HEADER DEFINITIONS
#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>

//USING NAMESPACE STANDARD 
using namespace std;

//main
int main()
{
		ofstream outputFile;
		outputFile.open("euler.dat");
		
		//input parameters
		double x0,v0;
		double k,m;
		double tf,ti,h;
		cout<<"Enter the value of initial position:"<<flush;
		cin>>x0;
		cout<<"Enter the value of initial velocity:"<<flush;
		cin>>v0;
		cout<<"Enter the value of mass:"<<flush;
		cin>>m;
		cout<<"Enter the value of spring constant:"<<flush;
		cin>>k;
		cout<<"Enter the value of final time:"<<flush;
		cin>>tf;
		cout<<"Enter the value of initial time:"<<flush;
		cin>>ti;
				
		
		//storage variables
		long double   x[5000],v[5000],t[5000],E[5000];
		// int i=0,j=0;
    
    //intialise
    for(int i=0;i<5000;i++){
    x[i]=0;
    v[i]=0;
    t[i]=0;
     }
    
    v[0]=v0;
    x[0]=x0;
    t[0]=ti;
        
    for(int i=0;i<=4998;i++){
    
    h=(tf-ti)/4999.0;
    
    t[i+1]=t[i]+h*i;
    
    //prediction
    
    x[i+1]=x[i]+v[i]*h;
	v[i+1]=v[i]-(k/m)*x[i]*h;
	
	//correction to predicted
	
	x[i+1]=x[i]+(v[i]+v[i+1])*h*0.5;
    v[i+1]=v[i]-(k/m)*(x[i]+x[i+1])*h*0.5;
           
    E[i]=0.5*m*x[i]*x[i]+0.5*k*v[i]*v[i];
    
   outputFile<<setw(6)<<x[i]<<setw(6)<<v[i]<< setw(6)<<t[i]<< setw(6)<< E[i] << endl;
}
		
			  outputFile<<endl;
			  outputFile.close();	
			  return 0;
}
