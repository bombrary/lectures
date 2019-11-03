#include <iostream>
#include <vector>
#define INF 1100000000

using namespace std;

int dp[110000];
int a[110000];

int main()
{
  for (int i = 0; i < 110000; i++) {
    dp[i] = INF;
  }
  int N;
  cin >> N;
  
  for (int i = 0;  i < N; i++) {
    cin >> a[i];
  }
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    dp[i + 1] = min(dp[i] + abs(a[i + 1] - a[i]), dp[i + 1]);
    dp[i + 2] = min(dp[i] + abs(a[i + 2] - a[i]), dp[i + 2]);
  }
  cout << dp[N - 1] << endl;
  
  return 0; 
}

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

#include <iostream>
#include <vector>

using namespace std;

// dp[i][j][k] :=
// i個目まで見たとき,幅の合計値j以下,
// 貼り付け可能枚数kのとき
// の重要度の最大値
int dp[60][11000][60];
int main()
{
  int W, N, K;
  cin >> W >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= K; k++) {
        // i番目のスクリーンショットを選ばないとき
        dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
        // i番目のスクリーンショットを選ぶとき
        dp[i + 1][j + A[i]][k + 1] = max(dp[i][j][k] + B[i], dp[i + 1][j + A[i]][k + 1]);   
      }
    }
  }
  cout << dp[N][W][K] << endl;

  return 0;
}
