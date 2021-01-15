//============================================================================
// Name        : LinearInterpolation.cpp
// Author      : SGHristov
//============================================================================

#include <stdio.h>
#include "Linear.h"

int main() {

	Linear linear;

	// For keys less than or equal 0 the expected value is 0
	linear.addPoint(0.0f, 0.0f); // Data 0, Key 0

	// For keys (0, 2] the values should chage from 0 to 2
	// For keys [2, 4) the values should change from 2 to 0
	linear.addPoint(1.0f, 1.0f); // Data 1, Key 1
	linear.addPoint(2.0f, 2.0f); // Data 2, Key 2
	linear.addPoint(1.0f, 3.0f); // Data 1, Key 3

	// For keys equal or greater than 4 the expected value is 0
	linear.addPoint(0.0f, 4.0f); // Data 0, Key 4

	printf("\n\n");

	for(float f=-1.0f; f<5.0; f=f+0.1)
	{
		printf("Key: %3.2f Value:%3.5f \n" , f, linear.getPoint(f));
		fflush(stdout);
	}
	return 0;
}
