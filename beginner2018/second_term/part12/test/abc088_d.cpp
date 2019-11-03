#include <iostream>
#include <queue>
#define INF 1100000000
using namespace std;

char mp[60][60];
long long dist[60][60];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int main()
{
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 60; j++) {
      mp[i][j] = '#';
      dist[i][j] = INF;
    }
  }

  long long H, W;
  cin >> H >> W;
  long long B = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char c;
      cin >> c;
      if (c == '#') B++;
      mp[i][j] = c;
    }
  }

  queue<pair<int, int>> q;
  q.push(make_pair(1, 1));
  dist[1][1] = 0;
  while (! q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    int y = tmp.first;
    int x = tmp.second;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (mp[ny][nx] == '.' && dist[ny][nx] > dist[y][x] + 1) {
        dist[ny][nx] = dist[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }

  if (dist[H][W] < INF) cout << (H*W - dist[H][W] - B - 1) << endl;
  else cout << -1 << endl;

  return 0;
}
