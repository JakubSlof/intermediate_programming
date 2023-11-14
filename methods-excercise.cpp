#include <iostream>
#include <cassert>

/*
 * Doimplementujte metody struktury Rectangle
 */

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    Point topLeft;
    Point bottomRight;

    int width() const
    {
        return abs(bottomRight.x - topLeft.x);
    }
    int height() const
    {
        return abs(bottomRight.y - topLeft.y);
    }
    int area() const
    {
        return height() * width();
    }
    bool contains(const Point &p) const
    {
        if (p.x <= bottomRight.x && p.y <= bottomRight.y && p.x >= topLeft.x && p.y >= topLeft.y)
        {
            return true;
        }
        return false;
    }

    void move(int dx, int dy){
        topLeft.x = dx+topLeft.x;
        topLeft.y = dy +topLeft.y;
        bottomRight.x = dx+bottomRight.x;
        bottomRight.y = dy+bottomRight.y;
    }
};

int main()
{
    Rectangle r = {{0, 0}, {10, 10}};
    const Rectangle &cr = r;
    assert(cr.width() == 10);
    assert(cr.height() == 10);
    assert(cr.area() == 100);
    assert(cr.contains({5, 5}));
    assert(!cr.contains({-1, -1}));
    assert(!cr.contains({11, 11}));

    r.move(1, 1);
     assert(cr.contains({5, 5}));
     assert(!cr.contains({-1, -1}));
    assert(cr.contains({11, 11}));

    std::cout << "All tests passed!\n";
}
