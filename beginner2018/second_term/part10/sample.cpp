long long fib(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  else return fib(n - 1) + fib(n - 2);
}

#include <iostream>

using namespace std;

long long dp[100];

long long fib(int n)
{
  if (dp[n] >= 0) return dp[n];
  else return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
  int n;
  cin >> n;

  // dpテーブルの初期化
  for (int i = 0; i < 100; i++) {
    dp[i] = -1;
  }
  dp[0] = 0;
  dp[1] = 1;
  
  cout << fib(n) << endl;

  return 0;
}

#include <iostream>

using namespace std;

long long dp[100];

int main()
{
  int n;
  cin >> n;

  // dpテーブルの初期化
  dp[0] = 0;
  dp[1] = 1;

  // 漸化式通りに計算する
  for (int i = 0; i <= n; i++) {
    dp[i + 2] = dp[i + 1] + dp[i];
  }

  cout << dp[n] << endl;

  return 0;
}

bool dfs(int i, int j)
{
  if (i == 0) return j == 0;

  if (dfs(i - 1, j)) return true;
  if (dfs(i - 1, j - a[i - 1])) return true;

  return false;
}

vector<int> a;
int dp[110][11000];

// i番目までを見たときに,jを作れるかどうか
int dfs(int i, int j)
{
  // 既に訪れた状態ならそれを再利用
  // i == 0のときもここに行き着く
  if (dp[i][j] >= 0) return dp[i][j];

  // a[i-1]を使わない場合
  // i-1番目を見たときに単にjが作れるかどうかをみればよい
  if (dfs(i - 1, j) == 1) return dp[i][j] = 1;
  // a[i-1]を使う場合,
  // i-1番目を見たときにj - a[i-1]が作れればそれにa[i-1]を加えてjにできる
  if (j - a[i - 1] >= 0 && dfs(i - 1, j - a[i - 1]) == 1) return dp[i][j] = 1;
  return dp[i][j] = 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
bool dp[110][11000];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int K;
  cin >> K;

  for (int i = 0; i <= K; i++) dp[0][i] = false;
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      // a[i]を使わないとき
      dp[i + 1][j] |= dp[i][j];
      // a[i]を使うとき
      if (j - a[i] >= 0) dp[i + 1][j] |= dp[i][j - a[i]];
    }
  }

  if (dp[N][K]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

if (j - a[i] < 0) dp[i + 1][j] = dp[i][j];
else dp[i + 1][j] = dp[i][j] | dp[i][j - a[i]];

dp[i + 1][j] |= dp[i][j];
if (j - a[i] >= 0) dp[i + 1][j] |= dp[i][j - a[i]];

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
bool dp[110][11000];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int K;
  cin >> K;

  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      // a[i]を使わないとき
      dp[i + 1][j] |= dp[i][j];
      // a[i]を使うとき
      dp[i + 1][j + a[i]] |= dp[i][j];
    }
  }

  if (dp[N][K]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

if (dp[i][j]) {
  dp[i + 1][j] = true;
  dp[i + 1][j + a[i]] = true;
}

dp[i + 1][j] |= dp[i][j];
dp[i + 1][j + a[i]] |= dp[i][j];

// i番目までみたときに,容量jにおける価値の最大値
int dfs(int i, int j)
{
  // 何も選んでいないとき,価値は0
  if (i == 0) return 0;

  int notuse = -1, use = -1;
  // i個目の品物を選ばない場合
  notuse = dfs(i - 1, j);

  // i個目の品物を選ぶ場合
  if (j - w[i - 1] >= 0)
    use = dfs(i - 1, j - w[i - 1]) + v[i - 1];

  // 選ばない or 選ぶ のうち大きい方を選ぶ
  return max(notuse, use);
}
int dp[110][11000];
// i番目までみたときに,容量jにおける価値の最大値
int dfs(int i, int j)
{
  // 既に探索ずみならその値を再利用する
  if (dp[i][j] >= 0) return dp[i][j];

  int notuse = -1, use = -1;
  // i個目の品物を選ばない場合
  notuse = dfs(i - 1, j);

  // i個目の品物を選ぶ場合
  if (j - w[i - 1] >= 0)
    use = dfs(i - 1, j - w[i - 1]) + v[i - 1];

  // 選ばない or 選ぶ のうち大きい方を選ぶ
  return dp[i][j] = max(notuse, use);
}

#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<int> v, w;
int dp[110][11000];

int main()
{
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    int vi, wi;
    cin >> vi >> wi;
    v.push_back(vi);
    w.push_back(wi);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] < 0) dp[i + 1][j] = dp[i][j];
      else dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }
  cout << dp[N][W] << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<int> v, w;
int dp[120][12000];

int main()
{
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    int vi, wi;
    cin >> vi >> wi;
    v.push_back(vi);
    w.push_back(wi);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      // テーブルの要素数を多めに確保しているのでifの必要はない
      // j + w[i] <= 11000なのでdpテーブルの要素数に注意
      dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
    }
  }
  cout << dp[N][W] << endl;

  return 0;
}
