#include <iostream>
using namespace std;
struct Point {
  int x, y;
  Point(int x, int y): x(x), y(y) { }
};
Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}

int main()
{
  Point p1(1, 2), p2(3, 4);
  Point p3(p1 + p2);
  cout << p3.x << ' ' << p3.x << endl;
}

