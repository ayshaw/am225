#include <iostream>
#include <cmath>

// define the length of your d,k vectors
#define n 1

//function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
double findingremainder(double k[n],double d[n], double B, double divisor,double &remainder)
{
	for (int i=1;i<=n;i++)

	{
		
		remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	}
	
		remainder=remainder-floor(remainder/divisor)*divisor;
		return remainder;
}


void largestsquarelessthanN(int val,int& m);

int main()
{

	int v=0;
	int counter=0;
	int n = 1E6;
	double k 77232917\\20;
	double d= 77232917%20;
	double B = pow(2,20);
	double divisor = ;
	double remainder = 0;
	
	
// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n+1];
	largestsquarelessthanN(n,v);
	// printf("largest square less than %d: %d\n",n,v);
	memset(prime, true, sizeof(prime));
	
#pragma omp parallel num_threads(8)
	{
	#pragma omp for
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
	}

#pragma omp parallel num_threads(8)
	{
	#pragma omp for	
	// Print all prime numbers
	for (int p=2; p<=n; p++)		
		{
	
		if (prime[p])
			{ 
			findingremainder(k,d,B,p,remainder)
			if (remainder=0) counter+=counter
				
			}

		}
	}
	return 0;
}

void largestsquarelessthanN(int val,int& m)
	{
	m=(int)floor(sqrt(((float)val)));
	}






