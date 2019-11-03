#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

#define INF 1100000000

using namespace std;

int dist[110][110];
char mp[110][110];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void init()
{
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 110; j++) {
      dist[i][j] = INF;
      mp[i][j] = '#';
    }
  }
}

int main()
{
  int H, W;
  cin >> H >> W;
  
  init();

  int sx, sy, gx, gy;
  cin >> sy >> sx;
  cin >> gy >> gx;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> mp[i][j];
    }
  }

  queue<pair<int, int>> q;
  q.push(make_pair(sy, sx));
  dist[sy][sx] = 0;
  while (! q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    int y = tmp.first;
    int x = tmp.second;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (mp[ny][nx] != '#' && dist[y][x] + 1 < dist[ny][nx]) {
        dist[ny][nx] = dist[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
  cout << dist[gy][gx] << endl;

  return 0;
}
