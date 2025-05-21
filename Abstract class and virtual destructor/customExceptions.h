#pragma once

class InfiniteSolutionsException : public std::logic_error {
public:
	InfiniteSolutionsException()
		: std::logic_error("The equation has infinitely many solutions") {}
};

class NoSolutionsException
	: public std::logic_error {
public:
	NoSolutionsException()
		: std::logic_error("The equation has no solutions") {}
};
