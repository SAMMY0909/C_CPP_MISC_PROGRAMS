#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <array>
#include <random>
#include <cstdlib>
#include <cstring>
using namespace std;
double fn(double arr[]);
double random(double fs[], double ls[],int i);
//The function:
double fn(double arr[])
{
	double ans;
	ans = exp(arr[0]*arr[1]); // include your function out of simpler functions
  return ans;
}
double random(double fs[], double ls[],int i)
{
  return ((rand() / (double) RAND_MAX) *  (ls[i] - fs[i])) + fs[i];
}
 int main(void)
 {
	 srand(time(NULL));
	 int , it, i,j,k,dim;
	 printf("Input the dimension of the phase space: ");
   cin>>dim;
   double ls[dim];
  double fs[dim];
  double N[dim];
  printf("Input the values of lower bounds in 1D array format: ");
  
  for(i = 0; i <dim; i ++)
  {
      
      cin>>fs[i];    
  }
  
  printf("\n Input the values of upper bounds in 1D array format: ");
  for(i = 0; i < dim; i ++)
  {
       
    cin>>ls[i]; 
  }
	 printf("Input number of iterations: ");
		cin>>it;
		
		printf("Input number of samples: ");
		for(i = 0; i <dim; i ++)
  {
      
      cin>>N[i];    
  }
  
		 
  double sum = 0, ans = 0,prod=1;
   double vl[dim];
  // Monte Carlo Method Calculation
  for (i = 0; i <it; i++)
  {
    for (j = 0; j <N; j++)
    {
		for (k = 0; k<dim; k++)
    {
      vl[k]=random(fs,ls, k);
      
    }
      sum += fn(vl);
      
    }
   }
  sum /= (double (it));
  for (k = 0; k <dim; k++)
    {
  sum = (sum * (ls[k]- fs[k]));
}
for (k = 0; k <dim; k++)
    {
  prod=prod*N[k];
}
sum /=(double (prod));
	 // Midpoint Rule Calculation
	 double dif[dim];
	 double diff=1.0;
	 
	 for (k = 0; k<dim; k++)
  {
   dif[k] = (ls[k]-fs[k])/((double) N);
}

for (k = 0; k <dim; k++)
  {
   diff  =diff * (ls[k]-fs[k]);
}
diff /=((double) N);

    double vl1[dim];
  for (j = 0; j < N; j++)
  {
	  for (k = 0; k < dim; k++)
  {
    vl1[k]= j * dif[k] + fs[k];
    
  }
ans += fn(vl1) * diff;
}
printf("Integral using midpoint rule is ");
printf("%1f",ans);

return 0;

}
