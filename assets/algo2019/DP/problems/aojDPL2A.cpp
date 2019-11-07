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

// dp[S][v] := いま頂点をS分見た。今vにいるときの、いままでのコストの最小値
int dp[1 << 16][16];

int main()
{
  for (int i = 0; i < (1 << 16); i++) {
    for (int j = 0; j < 16; j++) {
      dp[i][j] = INF;
    }
  }
  int V, E;
  cin >> V >> E;
  vector<vector<pair<int, int>>> edge(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge[s].push_back(make_pair(t, d));
  }

  // Sが0を含んでいないが、今地点0にいるとみなす
  // 最後に入ってくる
  dp[0][0] = 0;
  for (int S = 0; S < (1 << V); S++) {
    for (int v = 0; v < V; v++) {
      if (dp[S][v] >= INF) continue;
      for (auto& to : edge[v]) {
        int u = to.first;
        int d = to.second;
        if ((S >> u) & 1) continue;
        dp[S | (1 << u)][u] = min(dp[S | (1 << u)][u], dp[S][v] + d);
      }
    }
  }
  if (dp[(1 << V) - 1][0] >= INF) cout << -1 << endl;
  else cout << dp[(1 << V) - 1][0] << endl;

  return 0;
}
