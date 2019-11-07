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

int dp[1100][1100];
int solve(string& X, string& Y)
{
  for (int i = 0; i < 1100; i++) {
    for (int j = 0; j < 1100; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < Y.size(); j++) {
      if (X[i] == Y[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  return dp[X.size()][Y.size()];
}

int main()
{
  int n;
  cin >> n;
  while (n--) {
    string X, Y;
    cin >> X >> Y;
    cout << solve(X, Y) << endl;
  }
  return 0;
}

