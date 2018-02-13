#include <iostream>
#include <cmath>

// define the length of your d,k vectors
#define n 3

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

	// for (int i=0;i<n;i++)

	// {
		
	// 	remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	// }
	
	// 	remainder=remainder-floor(remainder/divisor)*divisor;
int qold=(int)d[0]/divisor;
int remold=d[0]%divisor;
int remnew;
int qnew;
	for (int i=1; i<n; i++){
		qnew=floor((remold*B+d[i])/divisor);
		remnew=(remold*B+d[i])%divisor;
		qold=qnew;
		remold=remnew;
	}
	remainder=remnew;
}

//calling your variables
main()
{
	int k[n] = {0, 1, 2};
	int d[n] = {7, 5, 2};
	int B = 10;
	int divisor = 3;
	int remainder = 0;
	
	findingremainder(d, B,divisor,remainder);
	remainder = remainder;
	std::cout<<remainder<<std::endl;



}





