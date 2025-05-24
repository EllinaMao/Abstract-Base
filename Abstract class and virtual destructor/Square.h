#pragma once
#include "Shape.h"
//Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны
class Square :
    public Shape
{
private:
	size_t mSide;
    int mX;
	int mY;
	std::string mName;; // Имя фигуры

public:
	Square() : mSide(0), mX(0), mY(0), mName("Square") {} // конструктор по умолчанию
	Square(const int x, const int y, const size_t side) :mSide(side), mX(x), mY(y), mName("Square") {}
	void Show() override; // рисование на экране фигуры
	void Save(std::ofstream& out) override; // сохранение фигуры в файл
	void Load(std::ifstream& in) override; // считывание фигуры из файла
	~Square() override = default; // виртуальный деструктор
};

