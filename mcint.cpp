#include <iostream>
#include <cmath>
#include <cassert>
#include <random>
using namespace std;
double random_uniform_0_1();
double func(double ,double ,double );
double MonteCarloIntegral1D(double , double ,int ,double , double);

int main(int argc, char* argv[])
{
	double mu,sigma,delta;
	double a,b;
	double intval=0;
	int n=0;
	
		cout <<"Enter the value of mu, sigma, delta, and no of trial runs respectively \n";
	cin >> mu >> sigma >> delta>>n;
	a=mu-delta;
	b=mu+delta;
	intval = MonteCarloIntegral1D( a, b, n,  mu, sigma);
	cout<<"THE integration value is \n"<<intval;		
	return 0;
} 
double random_uniform_0_1()
{
return double(rand())/double(RAND_MAX);
}
double func(double mu, double sigma,double t){
	double const pi=3.14159265358979323;
	double temp=t-mu;
		double val=(1/double(sqrt(2*pi)))*exp(-double (pow(temp,2))/double(pow(sigma,2)));
	return val;
	
	} //integrand
double MonteCarloIntegral1D(double a, double b, int n, double mu, double sigma)
{
double u, t;
double sum = 0.0;
double avgValue;
for (int i = 1; i <= n; i++)
{
u = random_uniform_0_1();
t= a + (b - a)*u;
sum += func(mu,sigma,t);
avgValue = double (sum/n) ;
}
double answer = (b-a)*avgValue;
return answer;
}

