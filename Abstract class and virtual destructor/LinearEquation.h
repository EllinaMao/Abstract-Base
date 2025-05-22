#pragma once

#include <iostream>
#include <stdexcept>
#include "AbstractBase.h"
#include "EquationRoots.h"	
#include "customExceptions.h"

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

    void roots() override {
        try {
            if (mK == 0 && mB == 0) {
                throw InfiniteSolutionsException();
            }
            if (mK == 0 && mB != 0) {
                throw NoSolutionsException();
            }
            short size = 1;
            auto* root = new double[size]; 
            root[0] = -mB / mK;
            mRoots.SetRoot(root, size);
            delete[] root;
            return;
        }
        catch (const InfiniteSolutionsException& e) {
            std::cout << e.what() << std::endl;
            mRoots.SetState(std::string("Infinite solutions"));
        }
        catch (const NoSolutionsException& e) {
            std::cerr << e.what() << std::endl;
            mRoots.SetState(std::string("No solution"));
        }
    }

    void showRoot() override {
        std::cout << "Root(s) of the linear equation: ";
        mRoots.printRoots();
    }

};