#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Shape.h"
#include "FileException.h"

class Circle : public Shape {
private:
	int mX; // Координата центра по оси X
	int mY; // Координата центра по оси Y
	double mRadius; // Радиус окружности
	std::string mName; // Имя фигуры

public:
	Circle() : mX(0), mY(0), mRadius(1.0), mName("Circle") {} // Конструктор по умолчанию
	Circle(const int x, const int y, const double radius) : mX(x), mY(y), mRadius(radius), mName("Circle") {}
	void Show() override; // Вывод на экран информации о фигуре
	void Save(std::ofstream& out) override; // Сохранение фигуры в файл
	void Load(std::ifstream& in) override; // Считывание фигуры из файла

};