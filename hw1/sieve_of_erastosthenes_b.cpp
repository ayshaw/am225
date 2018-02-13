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

//calling your variables
main()
{
	int k[n] = {0, 1, 2};
	int d[n] = {7, 5, 2};
	int B = 10;
	int divisor = 3;
	int remainder = 0;
	
	findingremainder(k,d, B,divisor,remainder);
	remainder = remainder;
	std::cout<<remainder<<std::endl;



}





