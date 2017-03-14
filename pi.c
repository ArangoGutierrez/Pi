#include <stdlib.h>
#include <stdio.h>   
#include <omp.h>   
#include <time.h>
#include <math.h>
 
static long MULTIPLIER  = 1366;   
static long ADDEND      = 150889;   
static long PMOD        = 714025;   
long random_last = 0.0;   
double random_low, random_hi;   
#define r 1
/*
Functions used to generate random numbers
*/
   
double randomi()   
{
	clock_t t;
	t=clock();
	double tc;
	tc = (((float)t)/CLOCKS_PER_SEC);
	double X = fmod(((3*t)+(3/tc)),(3/tc));/*Seed*/
	double M = 2147483648,n;
	int a = 1103515245,c=12345,i;
	for(i=1;i<1000;i++)
	{
		X =  fmod((a*X+c),M);// Linear congruence
		n = (X/(M-1));
	double te = (3*3/2)+(0.017453293*(n)*pow(-1,(int) (n*10)));
		}  
	return n;   
}     
//    
// The monte carlo pi program   
//   
   
int main (int argc, char *argv[])   
{   
   int num_trials= atoi(argv[1]);
   long i;  long Ncirc = 0;   
   double pi;   
   //double r = 1.0;   // radius of circle. Side of squrare is 2*r    
   
  #pragma omp parallel for private(i) reduction(+:Ncirc) 
   for(i=0;i<num_trials; i++)   
   {   
     double  x = randomi();    
     double y = randomi();   
   
      double test = x*x + y*y;   
   
      if (test <= r*r) Ncirc++;   
    }   
   
    pi = 4.0 * ((double)Ncirc/(double)num_trials);   
   
    printf("\n %ld trials, pi is %f \n",num_trials, pi);   
   
    return 0;   
}
