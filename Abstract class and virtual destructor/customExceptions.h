#pragma once
#include <stdexcept>

class InfiniteSolutionsException : public std::domain_error {
public:
	InfiniteSolutionsException()
		: std::domain_error("The equation has infinitely many solutions") {}
};

class NoSolutionsException
	: public std::domain_error {
public:
	NoSolutionsException()
		: std::domain_error("The equation has no solutions") {}
};

class LinearEquationException
	: public std::logic_error {
public:
	LinearEquationException()
		: std::logic_error("The equation is linear") {}
};