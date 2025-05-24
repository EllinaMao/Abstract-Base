#include "Square.h"
#include "FileException.h"
using namespace std;

void Square::Show()
{
    cout << "Name: " << mName << endl;
    cout << "Sides: " << mSide << endl;
    cout << "Top-left corner: (" << mX << ", " << mY << ")" << endl;


}

//
void Square::Save(ofstream& out)
{
    if (!out) {
        throw FileWriteException();
    }
    out << mSide << " " << mX << " " << mY << " "<< mName << endl;
    cout << "Rectangle saved to file." << endl;
}

void Square::Load(ifstream& in)
{
    cout << "Loading rectangle from file..." << endl;
    if (!in) {
        throw FileNotFoundException();
    }
    in >> mSide >> mX >> mY >> mName;
    if (in.fail()) {
        throw FileReadException();
    }

}