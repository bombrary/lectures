#include <iostream>
#include <iomanip>

using namespace std;

int pascal(int i, int j)
{
  // 不正な入力
  if (i < 0 || j < 0 || j > i + 1) return -1;

  if (i == 0 || j == 0 || j == i) return 1;
  else return pascal(i - 1, j) + pascal(i - 1, j - 1);
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << setw(3) << pascal(i, j) << ' ';
    }
    cout << endl;
  }
  return 0;
}
