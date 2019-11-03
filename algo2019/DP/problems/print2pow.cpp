#include <iostream>

using namespace std;

int main()
{
  int x;
  cin >> x;
  for (int i = 0; x > 0; i++) {
    int t = min(1 << i, x);
    cout << t << ' ';
    x -= t;
  }
  cout << endl;
  return 0;
}
