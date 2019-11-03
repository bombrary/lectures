#include <iostream>

using namespace std;

char mp[110][110];
int N, M;

void dfs(int y, int x)
{
  mp[y][x] = '.';
  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      if (mp[y + dy][x + dx] == 'W') {
        dfs(y + dy, x + dx);
      }
    }
  }
}

int main()
{
  // 初期化
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 110; j++) {
      mp[i][j] = '.';
    }
  }

  // 入力
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> mp[i][j];
    }
  }

  // Wのところを見つけてDFS
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (mp[i][j] == 'W') {
        ans++;
        dfs(i, j);
      }
    }
  }

  // 出力
  cout << ans << endl;

  return 0;
}
