// 아래처럼 동작하는 Point 클래스를 작성해 주세요.


#include <iostream>

class Point
{
    int x_, y_;
public:
    explicit Point(int x, int y) : x_(x), y_(y) {}
    Point(const Point& p) : x_(p.get_x()), y_(p.get_y()) {}
    int get_x() const { return x_; }
    int get_y() const { return y_; }

    Point operator+(const Point& other) const
    {
        return Point(x_ + other.get_x(), y_ + other.get_y());
    }

};

std::ostream& operator<<( std::ostream& os, 
						  const Point& pt)
{
	return os << pt.get_x() << ", " << pt.get_y();
}

int main() 
{
    // Point p = {1, 2};            // error 나와야 한다.
    const Point p1{1, 1};
    const Point p2{5, 5};

    std::cout << p2.get_x() << std::endl;  // 5 나와야 합니다.
    const Point p3 = p1 + p2;
    std::cout << p3 << std::endl;           // 6, 6으로 출력되어야 합니다.
    return 0;
}