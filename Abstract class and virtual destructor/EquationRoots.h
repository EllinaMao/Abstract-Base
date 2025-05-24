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

	EquationRoots() : mRoots(nullptr), mRootsState("No Roots"), mCount(0) {}

	EquationRoots(double const* roots, size_t count);

	void SetRoot(double const* roots, size_t count);

	explicit EquationRoots(double const* roots);
	EquationRoots(const EquationRoots& other);

	EquationRoots& operator=(const EquationRoots& other);

	void AddRoot();

	~EquationRoots();

	void printRoots() const;

	double* getRoots() const {
		return mRoots;
	}
	size_t getCount() const {
		return mCount;
	}
	std::string getRootsState() const {
		return mRootsState;
	}

};