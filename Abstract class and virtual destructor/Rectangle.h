#pragma once
#include "Shape.h"
#include "FileException.h"
//Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами

class Rectangle :
    public Shape
{
    private:
        double mWidth;
		double mHeight;

        int mX;
        int mY;
        std::string mName;

    public:
        Rectangle() : mWidth(0), mHeight(0), mX(0), mY(0), mName("Rectangle") {}
        Rectangle(const double w, const double h, const int x, const int y) : mWidth(w), mHeight(h), mX(x), mY(y), mName("Rectangle") {}
        void Show() override; // вывод на экран информации о фигуре
        void Save(std::ofstream& out) override; // сохранение фигуры в файл
        void Load(std::ifstream& in) override; // считывание фигуры из файла
};

