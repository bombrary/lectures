int expr(int a, int n)
{
  int ret = 1;
  for (int i = 0; i < n; i++) {
    ret *= a;
  }
  return ret;
}

int expr(int a, int n)
{
  if (n == 0) return 1;
  return a * expr(a, n - 1);
}

int expr_iter(int a, int n, int ret)
{
  if (n == 0) return ret;
  return expr_iter(a, n - 1, ret * a);
}

int expr(int a, int n)
{
  return expr_iter(a, n, 1);
}

#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> a;

bool dfs(int i, int sum)
{
  // 0～N-1まで見終わったら,今の総和がkかどうかを判定する.
  if (i == N) return sum == K;

  // 選ぶ,選ばない場合を試してみて,Kになる状態が発見できればtrue返す
  if (dfs(i + 1, sum      )) return true;
  if (dfs(i + 1, sum + a[i])) return true;

  // 選んでも選ばなくても,Kとなる状態が発見できなかった
  return false;
}

int main()
{
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cin >> K;

  cout << dfs(0, 0) << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> queen[8];

bool check()
{
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      int dx = queen[i].first - queen[j].first;
      int dy = queen[i].second - queen[j].second;
      if (abs(dx) == abs(dy) || dx == 0 || dy == 0) return false;
    }
  }
  return true;
}

bool dfs(int cnt)
{
  if (cnt == 8) {
    if (check()) return true;
    else return false;
  }

  bool x[8] = { }, y[8] = { };
  for (int i = 0; i < cnt; i++) {
    y[queen[i].first] = x[queen[i].second] = true;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (y[i] || x[j]) continue;
      queen[cnt].first = i;
      queen[cnt].second = j;
      if (dfs(cnt + 1)) return true;
    }
  }

  return false;
}

int main()
{
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      if (c == 'Q') {
        queen[cnt].first = i;
        queen[cnt].second = j;
        cnt++;
      }
    }
  }

  if (dfs(cnt)) {
    char mp[8][8];
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        mp[i][j] = '.';
      }
    }
    for (int i = 0; i < 8; i++)
      mp[queen[i].first][queen[i].second] = 'Q';
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << mp[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "No Answer" << endl;
  }

  return 0;
}

// インクリメント,デクリメントのみ許される
// このとき足し算は次のように定義できる.
int add(int a, int b)
{
  if (b == 0) return a;
  else return add(++a, --b);
}

int pascal(int i, int j)
{
  // 不正な入力
  if (i < 0 || j < 0 || j > i + 1) return -1;

  if (i == 0 || j == 0 || j == i) return 1;
  else return pascal(i - 1, j) + pascal(i - 1, j - 1);
}
