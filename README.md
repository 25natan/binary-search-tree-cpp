# Binary search tree - cpp template implementation
An implementation of binary search tree in cpp programming language, using cpp templates.<br/>
To use it, you can simply include it in your source code.<br/>
The elements in the tree can be of any type as long as it implements the operators `<=` and `<<`<br/>

Code example for usage with `int` and `double` types and also with custom class `Point`:
```cpp
#include "bst.h"
#include <iostream>
struct Point {
    float _x, _y;
    Point(float x, float y): _x(x), _y(y) {}
    float distanceFromOrigin() const {
        return sqrt(_x * _x + _y * _y);
    }
};
bool operator<=(const Point& p1, const Point& p2) {
    return p1.distanceFromOrigin() <= p2.distanceFromOrigin();
}
bool operator==(const Point& p1, const Point& p2) {
    return p1._x == p2._x && p1._y == p2._y;
}
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << '(' << p._x << ',' << p._y << ')';
    return out;
}
int main() {
    Bst<double> bstDouble({0.5, 3.21, -0.9});
    bstDouble.insert(100.765);
    bstDouble.printData(Travers::InOrder);
    bstDouble.printData(Travers::PreOrder);
    bstDouble.printData(Travers::PostOrder);
    std::cout << std::boolalpha << bstDouble.find(0.5) << std::endl;

    Bst<int> bstInt({5, -1, 7, 6});
    bstInt.printData(Travers::InOrder);
    bstInt.printData(Travers::PreOrder);
    bstInt.printData(Travers::PostOrder);
    std::cout << std::boolalpha << bstInt.find(8) << std::endl;

    Bst<Point> bstPoint({Point(1,2)});
    bstPoint.insert(Point(4,-3))
        .insert({Point(0.7, 0.1), Point(5,9)});
    bstPoint.printData(Travers::InOrder);
    bstPoint.printData(Travers::PreOrder);
    bstPoint.printData(Travers::PostOrder);
    std::cout << std::boolalpha << bstPoint.find(Point(5,9)) << std::endl;

    return 0;
}
```

Output:
```
-0.9 0.5 3.21 100.765 
0.5 -0.9 3.21 100.765 
-0.9 100.765 3.21 0.5 
true
-1 5 6 7 
5 -1 7 6 
-1 6 7 5 
false
(0.7,0.1) (1,2) (4,-3) (5,9) 
(1,2) (0.7,0.1) (4,-3) (5,9) 
(0.7,0.1) (5,9) (4,-3) (1,2) 
true
```