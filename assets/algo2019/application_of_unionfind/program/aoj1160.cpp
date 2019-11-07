#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

struct UnionFind {
  pair<int, int> par[60][60];
  int sz[60][60];
  int cnt;
  UnionFind(int h, int w) {
    for (int i = 0; i <= h; i++) {
      for (int j = 0; j <= w; j++) {
        par[i][j] = MP(i, j);
        sz[i][j] = 1;
      }
    }
  }
  pair<int, int> find(int i, int j) {
    if (MP(i, j) == par[i][j]) return par[i][j];
    return par[i][j] = find(par[i][j].FI, par[i][j].SE);
  }
  void unite(int i1, int j1, int i2, int j2) {
    pair<int, int> x = find(i1, j1);
    pair<int, int> y = find(i2, j2);
    if (x == y) return;
    int xsize = sz[x.FI][x.SE];
    int ysize = sz[y.FI][y.SE];
    if (xsize < ysize) {
      par[x.FI][x.SE] = y;
      sz[y.FI][y.SE] += sz[x.FI][x.SE];
    } else {
      par[y.FI][y.SE] = x;
      sz[x.FI][x.SE] += sz[y.FI][y.SE];
    }
  }
  bool same(int i1, int j1, int i2, int j2) {
    return find(i1, j1) == find(i2, j2);
  }
};

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
  int w, h;
  while (cin >> w >> h, w|h) {
    vector<vector<int>> mp(h+2, vector<int>(w+2, 0));
    UnionFind uf(h, w);
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> mp[i][j];
      }
    }
    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        for (int i = 0; i < 8; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (mp[ny][nx] == mp[y][x]) {
            uf.unite(y, x, ny, nx);
          }
        }
      }
    }
    set<pair<int, int>> st;
    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        if (mp[y][x] == 1) st.insert(uf.find(y, x));
      }
    }
    cout << st.size() << endl;
  }
  return 0;
}
