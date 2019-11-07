#include <iostream>

using namespace std;

int main()
{
  auto add = [](int a, int b)->double {
    return a + b;
  };
  cout << add(1, 2) << endl;
  return 0;
}
