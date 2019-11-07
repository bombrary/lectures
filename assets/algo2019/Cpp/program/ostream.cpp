#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
  Point(int x, int y): x(x), y(y) { }
};
ostream& operator<<(ostream& stream, const Point& value) {
  stream << "(" << value.x << ", " << value.y << ")";
  return stream;
}

int main()
{
  Point p(1, 3);
  cout << p << endl;
  return 0;
}
