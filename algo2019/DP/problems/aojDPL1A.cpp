// Coin Changing Problem
#include <iostream>
#include <iomanip>
#include <vector>
#define INF 1100000000;

using namespace std;

int dp[30][60000];

inline void chmin(int& a, int b)
{
  a = min(a, b);
}

int main()
{
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 60000; j++) {
      dp[i][j] = INF;
    }
  }
  int n, K;
  cin >> K >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      chmin(dp[i + 1][j], dp[i][j]);
      chmin(dp[i + 1][j + a[i]], dp[i + 1][j] + 1);
    }
  }
  cout << dp[n][K] << endl;
  return 0;
}
