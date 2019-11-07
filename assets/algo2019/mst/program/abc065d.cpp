#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define Decimal fixed << setprecision(20)
#define SHOWP(x) cerr<<"["<<(x).FI<<", "<<(x).SE<<"]";
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}
constexpr int INF = 1100000000;
constexpr long long LLINF = 1100000000000000000LL;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

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
  int N;
  cin >> N;
  vector<pair<ll, int>> xorder, yorder;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    xorder.PB(MP(x, i));
    yorder.PB(MP(y, i));
  }
  sort(ALL(xorder));
  sort(ALL(yorder));
  
  vector<pair<ll, pair<int, int>>> edge;
  for (int i = 0; i < N - 1; i++) {
    ll cost = abs(xorder[i].FI - xorder[i+1].FI);
    cout << "X:" << xorder[i].SE << ' ' << xorder[i+1].SE << ", cost = " << cost << endl;
    edge.PB(MP(cost, MP(xorder[i].SE, xorder[i+1].SE)));
  }
  for (int i = 0; i < N - 1; i++) {
    ll cost = abs(yorder[i].FI - yorder[i+1].FI);
    cout << "Y:" << yorder[i].SE << ' ' << yorder[i+1].SE << ", cost = " << cost << endl;
    edge.PB(MP(cost, MP(yorder[i].SE, yorder[i+1].SE)));
  }
  
  cout << getMst(N, edge) << endl;

  return 0;
}
