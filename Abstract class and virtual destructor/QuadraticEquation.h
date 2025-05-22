#pragma once
#include <iostream>
#include <stdexcept>
#include "Abstract Base.h"
#include "EquationRoots.h"	
#include "customExceptions.h"

class QuadraticEquation : public Equation {
private:
	double mA;
	double mB;
	double mC; 
	EquationRoots mRoots;

public:
	QuadraticEquation() : mA(0), mB(0), mC(0) {}
	QuadraticEquation(double a, double b, double c) : mA(a), mB(b), mC(c) {}

	EquationRoots roots() override {
		if (mA == 0) {
			throw LinearEquationException();
		}
		double D = mB * mB - 4 * mA * mC;
		if (D < 0) {
			throw NoSolutionsException();
		}
		else if (D == 0) {
			double root = -mB / (2 * mA);
			return EquationRoots(&root, 1);
		}
		else {
			
			double root1 = (-mB + sqrt(D)) / (2 * mA);
			double root2 = (-mB - sqrt(D)) / (2 * mA);
			double roots[] = { root1, root2 };
			return EquationRoots(roots, 2);
		}
	}
};

