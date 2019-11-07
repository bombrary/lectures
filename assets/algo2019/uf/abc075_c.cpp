#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
  public:
    UnionFind(int n): par(n, -1) { }
    int root(int x) {
      if (par[x] < 0) return x;
      else return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
      x = root(x), y = root(y);
      if (x == y) return;
      if (par[y] < par[x]) swap(x, y);
      par[x] += par[y];
      par[y] = x;
    }
    bool same(int x, int y) {
      return root(x) == root(y);
    }
    int size(int x) {
      return -par[root(x)];
    }

  private:
    vector<int> par;
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> e;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    e.push_back(make_pair(a, b));
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    UnionFind uf(N);
    for (int j = 0; j < M; j++) {
      if (i != j) {
        uf.unite(e[j].first, e[j].second);
      }
    }
    if (!uf.same(e[i].first, e[i].second)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
