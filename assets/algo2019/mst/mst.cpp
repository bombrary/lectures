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

// el[i] = (cost, from, to)
int getMst(int V, vector<pair<ll, pair<int, int>>>& el)
{
  sort(el.begin(), el.end());
  UnionFind uf(V);
  ll ret = 0;
  for (auto e : el) {
    if (!uf.same(e.SE.FI, e.SE.SE)) {
      uf.unite(e.SE.FI, e.SE.SE);
      ret += e.FI; 
    }
  }
  return ret;
}

int main()
{

  return 0;
}
