#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <cstring>

// define the length of your d,k vectors
#define n 1

void largestsquarelessthanN(int val,int& m);

double findingremainder(double k[n],double d[n], double B, int divisor,double& remainder);


//function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
double findingremainder(double k[n],double d[n], double B, int divisor,double& remainder)
{
	for (int i=0;i<n;i++)

	{
		
		remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	}
	
		remainder=remainder-floor(remainder/divisor)*divisor;
		return remainder;
}

void largestsquarelessthanN(int val,int& m)
	{
	m=(int)floor(sqrt(((float)val)));
	}

int main()
{

	int v=0;
	int counter=0;
	int val = 1000000;
	double k[1]= (double)((int)77232917/20);
	double d[1]= (double)((int)77232917%20);
	double B = pow(2,20);
	
	double remainder = 0;
	
	bool prime[val+1];
	largestsquarelessthanN(n,v);
	memset(prime, true, sizeof(prime));
	

	for (int p=2; p<=v ; p++)
		{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
			{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)	prime[i] = false;
			}
	//if (p*p<=n) printf("%d",omp_get_num_threads());
		}




	// Print all prime numbers
	for (int p=2; p<=val; p++)		
		{
	
		if (prime[p])
			{ 
			findingremainder(k,d,B,p,remainder);
			int rem=remainder-1;
			if (rem==0) counter+=counter;
				
			}

		}
	
	printf("factors of M: %d, counter");
	return 0;
}







