#pragma once

#include <iostream>
#include <string>

struct EquationRoots {
private:
	double* mRoots;
	string state;
	size_t mCount;


public:
	void SetRoot(double* roots, size_t count) {
		if (count <= 0) {
			mRoots = nullptr;
			return;
		}
		if (mRoots) {
			delete[] mRoots;
		}
		mRoots = new double[count];
		for (size_t i = 0; i < count; ++i) {
			mRoots[i] = roots[i];
		}
		mCount = count;
	}
	EquationRoots() : mRoots(nullptr), mCount(0), state("No Roots") {}
	EquationRoots(double* roots, size_t count) : mCount(count) {
		if (count <= 0) {
			mRoots = nullptr;
			state = "No Roots";
			return;
		}
		mRoots = new double[mCount];
		state = std::to_string(count) + " roots";
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
		if (!mRoots) {
			return;
		}
		delete[] mRoots;
		mRoots = nullptr;
	}
	void printRoots() const {
		if (!mRoots) {
			std::cout << "No roots" << std::endl;
			return;
		}
		
		for (size_t i = 0; i < mCount; ++i) {
			std::cout << mRoots[i] << " ";
		}
		std::cout << std::endl;
	}

	double* getRoots() const {
		return mRoots;
	}
	size_t getCount() const {
		return mCount;
	}

};