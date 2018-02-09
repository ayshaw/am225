#include <iostream>
#include <cmath>
double findingremainder(double k[3],double d[3], double B, double divisor,double &remainder)
{
	for (int i=1;i=3;i++)

	{
		
		remainder+=d[i]*pow(B, k[i])-divisor*floor(d[i]*pow(B, k[i])/divisor);
	}
	
		remainder=remainder-floor(remainder/divisor)*divisor;
		return remainder;
}

main()
{
	double k[3] = {0, 1, 2};
	double d[3] = {7, 5, 2};
	double B = 10;
	double divisor = 3;
	double remainder = 0;
	
	findingremainder(k,d, B,divisor,remainder);

	std::cout<<remainder<<std::endl;



}





