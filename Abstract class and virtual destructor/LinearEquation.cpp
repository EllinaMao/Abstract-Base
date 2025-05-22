#include "LinearEquation.h"

double LinearEquation::roots()
{
	if (mK == 0 && mB == 0) {
		throw InfiniteSolutionsException();
	}
	if (mK == 0 && mB != 0) {
		throw NoSolutionsException();
	}
	double x = -mB / mK;

	return x;
}