#include <iostream>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  
  int ans = -1;
  for (int i = 1; i * i <= M; i++) {
    if (M % i == 0) {
      int tmp = M / i;
      if (M / i >= N) ans = max(ans, i);
      if (M / tmp >= N) ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  
  return 0;
}
