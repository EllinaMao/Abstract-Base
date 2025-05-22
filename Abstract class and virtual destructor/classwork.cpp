/*
// Абстрактный класс и виртуальный деструктор
Задание 1
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.Создать производные классы : класс линейных уравнений и класс квадратных уравнений.Определить функцию вычисления корней уравнений.
// custom task:
Создать массив указателей на базовый класс и заполнить его объектами производных классов.Вывести на экран корни уравнений.
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
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {

		Equation* eq = new LinearEquation(4.5, 5.1);
		Equation* eq2 = new QuadraticEquation(1.1, -3.1, 2.1);
		Equation* eq3 = new LinearEquation(0, 5.1);
		Equation* eq4 = new QuadraticEquation(0, 2.1, 3.1);

		Equation** equations = new Equation * [4];
		equations[0] = eq;
		equations[1] = eq2;
		equations[2] = eq3;
		equations[3] = eq4;

		for (size_t i = 0; i < 4; i++) {
			equations[i]->showRoot();
		}
		// Clean up
		for (size_t i = 0; i < 4; i++) {
			delete equations[i];
		}

	delete[] equations;
	}

	catch (...) {
		cout << "An unknown error occurred." << endl;
	}
	return 0;

}

