#include <iostream>
#include <vector>

using namespace std;

bool dp[110][11000];

int main()
{
  int N;
  cin >> N;
  vector<int> p(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    sum += p[i];
  }

  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i + 1][j] |= dp[i][j];
      dp[i + 1][j + p[i]] |= dp[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i <= sum; i++) {
    ans += dp[N][i];
  }
  cout << ans << endl;

  return 0;
}
