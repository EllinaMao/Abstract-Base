#pragma once

#include <iostream>
#include <string>

struct EquationRoots {
private:
	double* mRoots;
	std::string mRootsState;
	size_t mCount;
	

public:
	void SetState(std::string const& state) {
		mRootsState = state;
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
		mRootsState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");	
	}


	EquationRoots() : mRoots(nullptr), mRootsState("No Roots"), mCount(0) {}

	EquationRoots(double const* roots, size_t count) : mCount(count) {
		if (count <= 0) {
			mRoots = nullptr;
			mRootsState = "No Roots";
			return;
		}
		mRoots = new double[mCount];
		mRootsState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");		
		for (size_t i = 0; i < mCount; ++i) {
			mRoots[i] = roots[i];
		}
	}
	explicit EquationRoots(double const* roots) {
		mCount++;
		mRoots = new double[mCount];
		mRootsState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");
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
	   mRootsState = other.mRootsState;
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
		mRootsState = std::to_string(mCount) + (mCount == 1 ? " root" : " roots");
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
			std::cout << mRootsState << std::endl;
			return;
		}
		
		std::cout << mRootsState << std::endl;
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