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

int dp[2000][11000];
int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> v, w;
  REP(i, N) {
    int vi, wi, mi;
    cin >> vi >> wi >> mi;
    for (int j = 0; mi > 0; j++) {
      int t = min(1 << j, mi);
      mi -= t;
      v.PB(t*vi);
      w.PB(t*wi);
    }
  }
  
  N = v.size();
  dp[0][0] = 0;
  REP(i, N) {
    REP(j, W + 1) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + w[i] <= W) {
        dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
      }
    }
  }
  cout << dp[N][W] << endl;

  return 0;
}
