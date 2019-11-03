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


int main()
{
  ll b;
  while (cin >> b, b) {
    ll a0, n;
    for (ll n = 1; n*n <= 2*b; n++) {
      if ((2*b) % n > 0) continue;

      ll n1 = n, n2 = 2*b/n;

      ll a0_tmp;
      a0_tmp = 2*b/n1 - n1 + 1;
      if (a0_tmp > 0 && a0_tmp % 2 == 1) {
        a0 = max(a0, a0_tmp/2);
      }
      a0_tmp = 2*b/n2 - n2 + 1;
      if (a0_tmp > 0 && a0_tmp % 2 == 1) {
        a0 = max(a0, a0_tmp/2);
      }
    }
    cout << a0 << ' ' << n << endl;
  }
  return 0;
}
