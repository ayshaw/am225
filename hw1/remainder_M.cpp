#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include "omp.h"

#define n 2413528
// define the length of your d,k vectors


void largestsquarelessthanN(int val,int& m);


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
int findingremainder(int d[n], int B, int divisor,int &remainder)
{
	int qnew=0;
	int remnew=0;
	// for (int i=0;i<n;i++)

	// {
		
	// 	remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	// }
	
	// 	remainder=remainder-floor(remainder/divisor)*divisor;
	// 	return remainder;
	int qold=(int)d[0]/divisor;
	int remold=d[0]%divisor;
	for (int i=1; i<2413528; i++){
		qnew=floor((remold*B+d[i])/divisor);
		remnew=(remold*B+d[i])%divisor;
		qold=qnew;
		remold=remnew;
	}
	remainder=remnew;
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
	//for (int i=0;i<2413528;i++) k[i]=i+1;
	// std::cout<<k<<endl;
	int B = (int)pow(2,32);
	int d[2413528]={0};
	d[2413528-1]=(int)pow(2,21);
	
	
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
			findingremainder(d,B,p,remainder);
			int rem=remainder-1;
			if (rem==0) counter+=counter;
				
			}

		}
	
	printf("factors of M: %d", counter);
	return 0;
}







