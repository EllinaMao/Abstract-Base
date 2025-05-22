#pragma once
#include <iostream>
#include <stdexcept>
#include "AbstractBase.h"
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
    QuadraticEquation(double a, double b, double c) : mA(a), mB(b), mC(c) {
        roots();
    }

    void roots() override {
        try {
            if (mA == 0) {
                throw LinearEquationException();
            }

            double D = mB * mB - 4 * mA * mC;
            if (D < 0) {
                throw NoSolutionsException();
            }
            else if (D == 0) {
                short size = 1;
                double* rootPtr = new double[size];
                rootPtr[0] = -mB / (2 * mA);
                mRoots.SetRoot(rootPtr, size);
                return;
            }
            else {
				short size = 2;
                double* roots = new double[size];
                roots[0] = (-mB + sqrt(D)) / (2 * mA);
                roots[1] = (-mB - sqrt(D)) / (2 * mA);
                mRoots.SetRoot(roots, size);
                return;
            }
        }
        catch (const InfiniteSolutionsException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const NoSolutionsException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const LinearEquationException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "An unknown error occurred." << std::endl;
        }
    }
    void showRoot() override {
        std::cout << "Root(s) of the quadratic equation: ";
        mRoots.printRoots();
    }
};

