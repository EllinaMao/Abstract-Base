﻿#pragma once
#include <iostream>
#include "customExceptions.h"
#include "EquationRoots.h"
#include <stdexcept>


/*
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.Создать производные классы : класс линейных уравнений и класс квадратных уравнений.Определить функцию вычисления корней уравнений. 
// custom task:
Создать массив указателей на базовый класс и заполнить его объектами производных классов.Вывести на экран корни уравнений.
*/
class Equation {
public:
	virtual void roots() = 0;
	virtual void showRoot() const = 0;
	virtual ~Equation() = default;
};
//
