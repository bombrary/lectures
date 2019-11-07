#include <iostream>
#include <vector>

using namespace std;

int dp[110][11000];
int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + w[i] <= W) {
        dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i + 1][j] + v[i]);
        dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
      }
    }
  }
  cout << dp[N][W] << endl;

  return 0;
}
