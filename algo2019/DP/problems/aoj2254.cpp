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

int dp[1 << 20];
int solve(int N)
{
  for (int i = 0; i < (1 << 20); i++) {
    dp[i] = INF;
  }
  dp[0] = 0;
  vector<vector<int>> t(N, vector<int>(N));
  vector<int> t0(N);
  for (int i = 0; i < N; i++) {
    cin >> t0[i];
    for (int j = 0; j < N; j++) {
      cin >> t[i][j];
    }
  }
  for (int b = 0; b < (1 << N); b++) {
    for (int to = 0; to < N; to++) {
      if ((b >> to) & 1) continue;
      dp[b | (1 << to)] = min(dp[b | (1 << to)], dp[b] + t0[to]);
      for (int use = 0; use < N; use++) {
        if (!((b >> use) & 1)) continue;
        dp[b | (1 << to)] = min(dp[b | (1 << to)], dp[b] + t[to][use]);
      }
    }
  }
  return dp[(1 << N) - 1];
}

int main()
{
  int N;
  while (cin >> N, N) {
    cout << solve(N) << endl;
  }
  return 0;
}
