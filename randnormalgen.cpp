// normal_distribution
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{   int a,b,mu,sigma;
	int c;
	cout << "Enter the value of experiments and no of objects to distribute along with maxlim:"<< endl;
	scanf( "%i,%i ,%i", &a, &b,&c);
  const int nrolls=a;  // number of experiments
  const int nstars=b;    // maximum number of stars to distribute
  cout << "Enter the value of mean and standard deviation for the distribution"<< endl;
	scanf( "%i,%i", &mu, &sigma);

  default_random_engine generator;
  normal_distribution<double> distribution(mu,sigma);

  int p[c]={};

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=0.0)&&(number<c)) ++p[int(number)];
  }

  std::cout << "normal_distribution (&mu,&sigma):" << std::endl;

  for (int i=0; i<c; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  return 0;
}
