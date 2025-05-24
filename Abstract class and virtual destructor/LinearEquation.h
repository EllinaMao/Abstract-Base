#pragma once

#include <iostream>
#include <stdexcept>
#include "AbstractBase.h"
#include "EquationRoots.h"	
#include "customExceptions.h"
#include "MathExceptions.h"


class LinearEquation : public Equation {
private:
	double mK;
	double mB; // Коэффициенты линейного уравнения ax + b = 0
	EquationRoots mRoots;
	
public:
    LinearEquation() :mK(0), mB(0) {}
	LinearEquation(double k, double b) : mK(k), mB(b) {
        roots();
    }

    void roots() override;

	void showRoot() const override;

};