// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <omp.h>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void largestsquarelessthanN(int val,int& m);

int main()
{
//	int z;
	int v=0;
	int counter=0;
	int n = 1E6;
	int N = pow(2,77232916)-1;
	printf("%d",N);
	int counterN=0;
	cout<< "Following are the prime numbers smaller than or equal to " << n << endl;
	
// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n+1];
	int M=0+1024+2*pow(1024,2);
	largestsquarelessthanN(n,v);
	printf("largest square less than %d: %d\n",n,v);
	memset(prime, true, sizeof(prime));
	
#pragma omp parallel for num_threads(8)
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

#pragma omp parallel for num_threads(8)
	// Print all prime numbers
	for (int p=2; p<=n; p++)		
		{
	
		if (prime[p])
			{ 
			cout <<"prime number"<< p << " ";
			div_t divresult;
			divresult=div(p,M);
			printf(" %d div %d is %d with remainder %d \n",p,M,divresult.quot,divresult.rem);
			div_t divresultN;
			divresultN=div(N,p);
			if (divresultN.rem==0) {counterN=counterN+1;}
			if (divresult.rem==0) {counter=counter+1;}	
			}

		}
	cout<<"number divisible by M:"<<counter<<"  factors of N: " << counterN<<"\n"<<endl;
	return 0;
}

void largestsquarelessthanN(int val,int& m)
	{
	m=(int)floor(sqrt(((float)val)));
	}


