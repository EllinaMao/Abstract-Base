#include "Ellipse.h"
using namespace std;

void Ellipse::Show() {
	cout << "Name: "<< mName << endl;
	cout << "Top-left corner: (" << mX << ", " << mY << ")" << endl;
	cout << "Width: " << mWidth << endl;
	cout << "Height: " << mHeight << endl;
}

void Ellipse::Save(std::ofstream& out) {
	if (!out) {
		throw FileWriteException();
	}
	out << mX << " " << mY << " " << mWidth << " " << mHeight << " " << mName << endl;
	cout << "Ellipse saved to file." << endl;
}

void Ellipse::Load(std::ifstream& in) {
	cout << "Loading ellipse from file..." << endl;
	if (!in) {
		throw FileNotFoundException();
	}
	in >> mX >> mY >> mWidth >> mHeight >> mName;
	if (in.fail()) {
		throw FileReadException();
	}
}