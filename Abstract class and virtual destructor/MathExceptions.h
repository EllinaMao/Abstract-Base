#pragma once
#include "CustomExceptions.h"

class MathException : public CustomException {
public:
    explicit MathException(const std::string& msg = "Mathematical error") : CustomException(msg) {}
};


class InfiniteSolutionsException : public MathException {
public:
    InfiniteSolutionsException() : MathException("The equation has infinite solutions") {}
};

class NoSolutionsException
    : public MathException {
public:
    NoSolutionsException() : MathException("The equation has no solutions") {}
};

class LinearEquationException
    : public MathException {
public:
    LinearEquationException() : MathException("Linear equation error") {}
};