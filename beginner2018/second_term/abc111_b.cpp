#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i <= 9; i++) {
    if (100*(i-1) + 10*(i-1) + (i-1) < N &&
        N <= 100*i + 10*i + i) {
      cout << 100*i + 10*i + i << endl;
    }
  }

  return 0;
}
