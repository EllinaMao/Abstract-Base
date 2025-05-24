#pragma once
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "FileException.h"

//Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника со сторонами, параллельными осям координат, и размерами этого прямоугольника.

class Ellipse :
    public Shape
{
    private:

    int mX; // Координата верхнего левого угла по оси X
    int mY; // Координата верхнего левого угла по оси Y
    double mWidth; // Ширина эллипса
	double mHeight; // Высота эллипса
    std::string mName; // Имя


    public:
		Ellipse() : mX(0), mY(0), mWidth(0.0), mHeight(0.0), mName("Ellipse") {} // Конструктор по умолчанию
    Ellipse(const int x, const int y, const double width, const double height) 
        : mX(x), mY(y), mWidth(width), mHeight(height), mName("Ellipce") { }
    void Show() override; // Вывод на экран информации о фигуре
    void Save(std::ofstream& out) override; // Сохранение фигуры в файл
    void Load(std::ifstream& in) override; // Считывание фигуры из файла
	~Ellipse() override = default; // Виртуальный деструктор
    
};

