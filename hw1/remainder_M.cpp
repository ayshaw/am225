#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include "omp.h"


// define the length of your d,k vectors
#define n 2413528

void largestsquarelessthanN(int val,int& m);

double findingremainder(double k[n],double d[n], double B, int divisor,double& remainder);

// int myPow(int x, int p)


// //function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
// int myPow(int x, int p)
// {
//   if (p == 0) return 1;
//   if (p == 1) return x;

//   int tmp = myPow(x, p/2);
//   if (p%2 == 0) return tmp * tmp;
//   else return x * tmp * tmp;
// }

//function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
int findingremainder(int k[n],int d[n], int B, int divisor,int &remainder)
{
	int q[n]={0};
	int rem[n]={0};
	// for (int i=0;i<n;i++)

	// {
		
	// 	remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	// }
	
	// 	remainder=remainder-floor(remainder/divisor)*divisor;
	// 	return remainder;
	q[0]=(int)d[0]/divisor;
	rem[0]=d[0]%divisor;
	for (int i=1; i<n; i++){
		q[i]=floor((rem[i-1]*B+d[i])/divisor);
		rem[i]=(rem[i-1]*B+d[i])%divisor;
	}
	remainder=rem[n-1];
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
	int k[1]= {2413528};
	// for (int i=0;i<2413528;i++) k[i]=i+1;
	// std::cout<<k<<endl;
	int B = (int)pow(2,32);
	int d[1]={(int)pow(2,17)};
	
	
	int remainder = 0;
	
	bool prime[val+1];
	largestsquarelessthanN(n,v);
	memset(prime, true, sizeof(prime));
	

	for (int p=2; p<=v ; p++)
		{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
			{
				#pragma omp parallel for
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)	prime[i] = false;
			}
	//if (p*p<=n) printf("%d",omp_get_num_threads());
		}



#pragma omp parallel for reduction (+:counter)
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
	
	printf("factors of M: %d", counter);
	return 0;
}







