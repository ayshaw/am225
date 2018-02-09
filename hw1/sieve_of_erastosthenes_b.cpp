#include <iostream>
#include <cmath>


main()
{
	int k[3] = {0, 1, 2};
	int d[3] = {7, 5, 2};
	int B = 10;
	int divisor = 3;
	int remainder = 0;
	for (int i=1;i=3;i++)

	{
		int power=pow(B, k[i]);
		remainder=d[i]*power%divisor+remainder;
	}
	
		remainder=remainder%divisor;
		
	std::cout<<remainder<<std::endl;



}




