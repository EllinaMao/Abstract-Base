#pragma once

#include <iostream>
#include <string>

struct EquationRoots {
private:
	double* mRoots;
	std::string mState;
	size_t mCount;
	

public:
	void SetState(std::string const& state) {
		mState = state;
	}

	void SetRoot(double const* roots, size_t count) {
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
		mState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");	
	}


	EquationRoots() : mRoots(nullptr), mState("No Roots"), mCount(0) {}

	EquationRoots(double const* roots, size_t count) : mCount(count) {
		if (count <= 0) {
			mRoots = nullptr;
			mState = "No Roots";
			return;
		}
		mRoots = new double[mCount];
		mState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");		
		for (size_t i = 0; i < mCount; ++i) {
			mRoots[i] = roots[i];
		}
	}
	explicit EquationRoots(double const* roots) {
		mCount++;
		mRoots = new double[mCount];
		mState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");
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
	   mState = other.mState;
       if (mCount > 0) {  
           mRoots = new double[mCount];  
           for (size_t i = 0; i < mCount; ++i) {  
               mRoots[i] = other.mRoots[i];  
           }  
       }  
       return *this;  
    }

	void AddRoot() {
		auto* newRoots = new double[mCount + 1];
		for (size_t i = 0; i < mCount; ++i) {
			newRoots[i] = mRoots[i];
		}
		delete[] mRoots;
		mRoots = newRoots;
		mCount++;
		mState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");
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
			std::cout << mState << std::endl;
			return;
		}
		
		std::cout << mState << std::endl;
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