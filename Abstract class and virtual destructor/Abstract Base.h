#pragma once
#include <iostream>
#include <cmath>
#include <string>


/*
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.Создать производные классы : класс линейных уравнений и класс квадратных уравнений.Определить функцию вычисления корней уравнений.
*/
class Equation {
public:
	virtual void roots() = 0; 
	virtual ~Equation() = default;
};
