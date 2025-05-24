#include "Rectangle.h"
using namespace std;
void Rectangle::Show()
{
    cout << "Name: " << mName << endl;
	cout << "Width: " << mWidth << endl;
	cout << "Height: " << mHeight << endl;
	cout << "Top-left corner: (" << mX << ", " << mY << ")" << endl;


}

//
void Rectangle::Save(ofstream& out)  
{  
    if (!out) {  
        throw FileWriteException();  
    }  
    out << mWidth << " " << mHeight << " " << mX << " " << mY << " " << mName << endl;
    cout << "Rectangle saved to file." << endl;
}

void Rectangle::Load(ifstream& in)
{
    cout << "Loading rectangle from file..." << endl;
    if (!in) {
    throw FileNotFoundException();
    }
    in >> mWidth >> mHeight >> mX >> mY >> mName;
    if (in.fail()) {
    throw FileReadException();
    }

}

