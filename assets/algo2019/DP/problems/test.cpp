#include <iostream>
#include <vector>

using namespace std;

int dp[1 << 20];
int t[20][20]
int t0[20];
int solve(int N)
{
  for (int i = 0; i < N; i++) {
    cin >> t0[i];
    for (int j = 0; j < N; j++) {
      cin >> t[i][j];
    }
  }
}

int main()
{
  int N;
  while (cin >> N, N) {
    cout << solve(N) << endl;
  }
  return 0;
}
