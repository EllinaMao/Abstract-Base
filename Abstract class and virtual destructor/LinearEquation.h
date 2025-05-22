#pragma once

#include <iostream>
#include <stdexcept>
#include "Abstract Base.h"
#include "EquationRoots.h"	
#include "customExceptions.h"

class LinearEquation : public Equation {
private:
	double mK;
	double mB; // Коэффициенты линейного уравнения ax + b = 0
	
public:
	LinearEquation() :mK(0), mB(0) {}
	LinearEquation(double k, double b) : mK(k), mB(b) {}

	EquationRoots roots() override {
		if (mK == 0 && mB == 0) {
			throw InfiniteSolutionsException();
		}
		if (mK == 0 && mB != 0) {
			throw NoSolutionsException();
		}
		double x = -mB / mK;

		return EquationRoots(&x, 1);
	}

	
};