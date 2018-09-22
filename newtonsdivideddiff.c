//* Newtion's divided difference interpolation /*

//* Standard Headers */
	#include<math.h>
	#include<stdio.h>
	int main()
	{
//* Declaration of variables */
	int i,j,n;
        float x1,x[15],f[15],y,df,df1,dx;
        FILE *FP;


//* Open the data file to be interpolated */
        FP=fopen ("data.dat","r");

//* Read the data till the end of the file */
	i=0;
        while(!feof(FP))
        {fscanf(FP,"%f %f \n",&x[i],&f[i]); i++;}
        fclose(FP);

	n=i-1;

//* construct the divided difference table */
        for(j=0;j<n;j++)
        {
	 df=f[j];
         for(i=1;i<=(n-j);i++)
	 {
	  df1=df;
	  df=(f[i+j]-f[i+j-1])/(x[i+j]-x[i-1]);
	  if(i>1)f[i+j-1]=df1;
         }
//*  Store the coefficients of the polynomials in the f[i] array */
         f[n]=df;
	 printf("%d %f \n",j, f[j+1]);
        }

//*  Interpolate between the first four points */
        FP=fopen ("newton.dat","w");
	dx=(x[3]-x[0])/15.0;
         for(x1=x[0];x1<=x[3];x1=x1+dx)
           { y=f[0]+(x1-x[0])*(f[1]+(x1-x[1])
              *(f[2]+(x1-x[2])*f[3]));
	    fprintf(FP,"%f %f \n",x1, y);}
	fclose(FP);
	return 0;
        }

