#include "Circle.h"
using namespace std;

void Circle::Show() {
	cout << "Name: " << mName << endl;
	cout << "Center: (" << mX << ", " << mY << ")" << endl;
	cout << "Radius: " << mRadius << endl;
}

void Circle::Save(std::ofstream& out) {
	if (!out) {
		throw FileWriteException();
	}
	out << mX << " " << mY << " " << mRadius << " " << mName << endl;
	cout << "Circle saved to file." << endl;
}

void Circle::Load(std::ifstream& in) {
	cout << "Loading circle from file..." << endl;
	if (!in) {
		throw FileNotFoundException();
	}
	in >> mX >> mY >> mRadius>> mName;
	if (in.fail()) {
		throw FileReadException();
	}
}
