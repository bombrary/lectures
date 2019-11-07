#include <iostream>
#include <queue>

using namespace std;

char mp[60][60];
int dist[60][60];

int main()
{
  // init
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 60; j++) {
      mp[i][j] = '#';
      dist[i][j] = 1100000000;
    }
  }

  int R, C;
  int sy, sx, gy, gx;
  cin >> R >> C;
  cin >> sy >> sx >> gy >> gx;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> mp[i][j];
    }
  }

  /*for (int i = 0; i <= R + 1; i++) {
    for (int j = 0; j <= C + 1; j++) {
      cout << mp[i][j];
    }
    cout << endl;
  }*/

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, -1, 0, 1};
  queue<pair<int, int>> q;
  q.push(make_pair(sy, sx));
  dist[sy][sx] = 0;
  while (! q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    int x = tmp.second;
    int y = tmp.first;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (mp[ny][nx] != '#' && dist[y][x] + 1 < dist[ny][nx]) {
        dist[ny][nx] = dist[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
  cout << dist[gy][gx] << endl;

  return 0;
}
