#pragma once
#include <iostream>
#include <stdexcept>
#include "AbstractBase.h"
#include "EquationRoots.h"	
#include "customExceptions.h"
#include "MathExceptions.h"

class QuadraticEquation : public Equation {
private:
	double mA;
	double mB;
	double mC; 

	EquationRoots mRoots;

public:
    QuadraticEquation() : mA(0), mB(0), mC(0) {}
    QuadraticEquation(double a, double b, double c) : mA(a), mB(b), mC(c) {
        this->roots();
        
    }

    void roots() override;

    void showRoot() const override;
};

