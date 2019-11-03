#include <iostream>
#include <vector>

using namespace std;

// i個目までみたとき、jが作れるか？
bool dp[200][11000];
int main()
{
  int N; cin >> N;
  vector<int> s(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 10000; j++) {
      dp[i + 1][j] |= dp[i][j];
      dp[i + 1][j + s[i]] |= dp[i][j];
    }
  }

  int ans = 0;
  for (int j = 0; j <= 10000; j++) {
    if (dp[N][j] && j % 10 > 0) ans = j;
  }
  cout << ans << endl;

  return 0;
}
