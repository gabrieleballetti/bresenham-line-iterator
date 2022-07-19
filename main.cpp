#include <iostream>
#include "BresenhamLineIterator.h"

int main()
{
    Point2D start = Point2D(13, -2);
    Point2D end = Point2D(3, 7);
    for (auto& pt : BresenhamLineIterator(start, end))
    {
        std::cout << "(" << pt[0] << ", " << pt[1] << ")" << std::endl;
    }
}

// Output:
//
//(13, -2)
//(12, -1)
//(11, 0)
//(10, 1)
//(9, 2)
//(8, 2)
//(7, 3)
//(6, 4)
//(5, 5)
//(4, 6)
