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
constexpr int INF = 1 << 30 - 1;
constexpr long long LLINF = 1LL << 60;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

vector<vector<pair<int, int>>> edge;
int dp[1 << 16][16];
int dfs(int S, int v)
{
  if (dp[S][v] >= 0) return dp[S][v];
  int ret = INF;
  for (auto& to : edge[v]) {
    int u = to.first;
    int d = to.second;
    if ((S >> u) & 1) continue;
    ret = min(ret, dfs(S | (1 << u), u) + d);
  }
  return dp[S][v] = ret;
}

int main()
{
  for (int i = 0; i < 1 << 16; i++) {
    for (int j = 0; j < 16; j++) {
      dp[i][j] = -1;
    }
  }

  int V, E;
  cin >> V >> E;
  edge.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge[s].push_back(make_pair(t, d));
  }
  dp[(1 << V) - 1][0] = 0;
  int ans = dfs(0, 0);
  if (ans >= INF) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
