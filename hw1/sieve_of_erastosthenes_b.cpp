#include <iostream>
#include <cmath>

// define the length of your d,k vectors
#define n 3

//function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
double findingremainder(double k[n],double d[n], double B, double divisor,double &remainder)
{
	for (int i=0;i<n;i++)

	{
		
		remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	}
	
		remainder=remainder-floor(remainder/divisor)*divisor;
		return remainder;
}

//calling your variables
main()
{
	double k[n] = {0, 1, 2};
	double d[n] = {7, 5, 2};
	double B = 10;
	double divisor = 3;
	double remainder = 0;
	
	findingremainder(k,d, B,divisor,remainder);

	std::cout<<remainder<<std::endl;



}





