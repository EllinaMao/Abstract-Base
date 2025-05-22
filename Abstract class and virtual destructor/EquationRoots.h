#pragma once

#include <iostream>

struct EquationRoots {
private:
	double* mRoots;
	size_t mCount;

public:
	EquationRoots() : mRoots(nullptr), mCount(0) {}
	EquationRoots(double* roots, size_t count) : mCount(count) {
		if (count <= 0) {
			mRoots = nullptr;
			return;
		}
		mRoots = new double[mCount];
		for (size_t i = 0; i < mCount; ++i) {
			mRoots[i] = roots[i];
		}
	}
	EquationRoots(double* roots) {
		mCount++;
		mRoots = new double[mCount];
		for (size_t i = 0; i < mCount; ++i) {
			mRoots[i] = roots[i];
		}
	}
	EquationRoots(const EquationRoots& other) : mRoots(nullptr), mCount(other.mCount) {
		if (mCount > 0) {
			mRoots = new double[mCount];
			for (int i = 0; i < mCount; ++i) {
				mRoots[i] = other.mRoots[i];
			}
		}
	}

    EquationRoots& operator=(const EquationRoots& other) {  
       if (this == &other) {  
           return *this;  
       }  
       delete[] mRoots;  
       mCount = other.mCount;  
       mRoots = nullptr;  
       if (mCount > 0) {  
           mRoots = new double[mCount];  
           for (size_t i = 0; i < mCount; ++i) {  
               mRoots[i] = other.mRoots[i];  
           }  
       }  
       return *this;  
    }

	void AddRoot() {
		double* newRoots = new double[mCount + 1];
		for (size_t i = 0; i < mCount; ++i) {
			newRoots[i] = mRoots[i];
		}
		delete[] mRoots;
		mRoots = newRoots;
		mCount++;
	}

	~EquationRoots() {
		delete[] mRoots;
	}
	void printRoots() const {
		if (mCount == 0) {
			std::cout << "No roots" << std::endl;
			return;
		}
		std::cout << "Roots: ";
		for (size_t i = 0; i < mCount; ++i) {
			std::cout << mRoots[i] << " ";
		}
		std::cout << std::endl;
	}
};