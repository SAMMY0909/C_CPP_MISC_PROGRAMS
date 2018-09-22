#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    double x0=0.1,v0=1.0,x1,v1,x_m,v_m,x1_m,v1_m,x,v,t,h,E;
    ofstream fileout("trial.out");
    for(h=0.01;h<=50;h=h+0.01){
    x1=v;
    v1=-x;
    x_m=x0+0.5*h*x1;
    v_m=v0+0.5*h*v1;
    x1_m=v_m;
    v1_m=-x_m;
    x=x+h*x1_m;
    v=v+h*v1_m;
    t=t+h;
    E=0.5*x*x+0.5*v*v;
    fileout << x << "" << v << "" << t << "" << E << endl;
    }
    fileout.close();
    return 0;
}
