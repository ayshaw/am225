#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <array>
#include <cstdio>
#include <math.h>

main()
{
	int k[3] = {0, 1, 2};
	int d[3] = {7, 5, 2};
	int B = 10;
	int divisor = 3;
	int remainder = 0;
	for (int i=0;i=3;i++)

	{
		remainder+=d[i]*(int)pow(B, k[i])%divisor;
	}
	
		remainder=remainder%divisor;
		return remainder;
	std::cout<<remainder<<std::endl;



}



