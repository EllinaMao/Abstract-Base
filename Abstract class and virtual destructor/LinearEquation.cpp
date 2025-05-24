#include "LinearEquation.h"

void LinearEquation::roots()
{
    try {
        if (mK == 0 && mB == 0) {
            throw InfiniteSolutionsException();
        }
        if (mK == 0 && mB != 0) {
            throw NoSolutionsException();
        }
        short size = 1;
        auto* root = new double[size];
        root[0] = -mB / mK;
        mRoots.SetRoot(root, size);
        delete[] root;
        return;
    }
    catch (const InfiniteSolutionsException& e) {
        std::cout << e.what() << std::endl;
        mRoots.SetState(std::string("Infinite solutions"));
    }
    catch (const NoSolutionsException& e) {
        std::cerr << e.what() << std::endl;
        mRoots.SetState(std::string("No solution"));
    }
}

void LinearEquation::showRoot() const
{
    std::cout << "Root(s) of the linear equation: ";
    mRoots.printRoots();
}