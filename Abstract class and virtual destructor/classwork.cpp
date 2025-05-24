/*
// Абстрактный класс и виртуальный деструктор
Задание 1
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.Создать производные классы : класс линейных уравнений и класс квадратных уравнений.Определить функцию вычисления корней уравнений.

//////////////////////////
Задание 2
Создайте абстрактный класс Shape для рисования плоских фигур.Определите виртуальные методы :

Show() — вывод на экран информации о фигуре,
Save() — сохранение фигуры в файл,
Load() — считывание фигуры из файла.
Определите производные классы :

Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны
Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами
Circle — окружность с заданными координатами центра и радиусом
Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника со сторонами, параллельными осям координат, и размерами этого прямоугольника.
Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой из фигур.

*/
	


#include <iostream>
#include "EquationRoots.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include "AbstractBase.h"
#include "customExceptions.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "FileException.h"
#include <memory>

//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

using namespace std;

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	cout << "Task1" << endl;

	try {
		auto** equations = new Equation * [4];
		equations[0] = new LinearEquation(4.5, 5.1);
		equations[1] = new QuadraticEquation(1.1, -3.1, 2.1);
		equations[2] = new LinearEquation(0, 5.1);
		equations[3] = new QuadraticEquation(0, 2.1, 3.1);

		for (size_t i = 0; i < 4; i++) {
			cout << "Equation " << i + 1 << ": ";
			equations[i]->showRoot();
		}

		for (size_t i = 0; i < 4; i++) {
			delete equations[i];
		}

	delete[] equations;

	system("pause");
	system("cls");

	}

	catch (...) {
		cout << "An unknown error occurred." << endl;
	}

	cout << "Task2" << endl;

	try {
		ofstream outFile("shapes.txt", ios::out | ios::trunc);
		if (!outFile) {
			throw FileWriteException();
		}
		size_t shapeCount = 4;

		Shape** shapes = new Shape * [shapeCount];

		shapes[0] = new Square(10, 20, 30);
		shapes[1] = new Rectangle(15, 25, 5, 10);
		shapes[2] = new Circle(30, 40, 20);
		shapes[3] = new Ellipse(50, 60, 70, 80);

		{
			for (size_t i = 0; i < shapeCount; i++) {
				shapes[i]->Save(outFile);
			}
			outFile.close();
			cout << "Shapes saved to file." << endl;

			ifstream inFile("shapes.txt", ios::in);
			if (!inFile) {
				throw FileNotFoundException();
			}

			inFile.close();
		}

		// Load shapes from file
		{
			ifstream inFile("shapes.txt", ios::in);
			if (!inFile) {
				throw FileNotFoundException();
			}
			for (size_t i = 0; i < shapeCount; i++) {
				shapes[i]->Load(inFile);
			}
			inFile.close();
			cout << "Shapes loaded from file." << endl;
		}

		// Display shapes

		for (size_t i = 0; i < shapeCount; i++) {
			cout << string(50, '-') << endl;
			cout << "Shape " << i + 1 << ":" << endl;
			shapes[i]->Show();
			cout << endl;
		}

		
	}
	catch (const FileException& e) {
		cout << "File error: " << e.what() << endl;

	}
	catch (const CustomException& e) {
		cout << "Custom error: " << e.what() << endl;
	}
	catch (const std::exception& e) {
		cout << "Standard error: " << e.what() << endl;
	}
	catch (...) {
		cout << "An unknown error occurred." << endl;
	}

	return 0;

}

