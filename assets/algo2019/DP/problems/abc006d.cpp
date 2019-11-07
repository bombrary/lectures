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


int dp[31000];
int main()
{
  REP(i, 31000) dp[i] = INF;

  int N;
  cin >> N;
  REP(i, N) {
    int c;
    cin >> c;
    int idx = lower_bound(dp, dp + N, c) - dp;
    dp[idx] = c;
  }
  int tmp;
  for (tmp = 0 ; tmp < N; tmp++) {
    if (dp[tmp] >= INF) break;
  }
  cout << (N - tmp) << endl;

  return 0;
}
