#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

#define INF 1100000000

using namespace std;

int H, W;
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

void drawmp()
{
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if (dist[i][j] >= INF) cout << "INF ";
        else cout << setw(3) << dist[i][j] << ' ';
      }
      cout << endl;
    }
}

int main()
{
  cin >> H >> W;
  
  init();

  int sx, sy, gx, gy;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 'S') {
        sy = i;
        sx = j;
      }
      if (mp[i][j] == 'G') {
        gy = i;
        gx = j;
      }
    }
  }

  for (int i = 0; i <= H + 1; i++) {
    for (int j = 0; j <= W + 1; j++) {
      cout << mp[i][j];
    }
    cout << endl;
  }

  queue<pair<int, int>> q;
  q.push(make_pair(sy, sx));
  dist[sy][sx] = 0;
  drawmp();
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
  drawmp();

  return 0;
}
