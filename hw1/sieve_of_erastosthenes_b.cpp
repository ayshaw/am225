#include <iostream>
#include <cmath>

// define the length of your d,k vectors
#define n 3

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}   

//function finds remainder with the k,n,B, and divisor inputs (replaces remainder with right value)
int findingremainder(int k[n],int d[n], int B, int divisor,double &remainder)
{
	// for (int i=0;i<n;i++)

	// {
		
	// 	remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	// }
	
	// 	remainder=remainder-floor(remainder/divisor)*divisor;
	// 	return remainder;
	for (int i=0; i<n; i++){
		remainder+=d[i]*B%divisor-d[i]*(int)pow((double)B%divisor,(double)k[i])*divisor;
	}
	remainder=remainder-floor(remainder/divisor)*divisor;
}

//calling your variables
main()
{
	int k[n] = {0, 1, 2};
	int d[n] = {7, 5, 2};
	int B = 10;
	int divisor = 3;
	int remainder = 0;
	
	findingremainder(k,d, B,divisor,remainder);

	std::cout<<remainder<<std::endl;



}





