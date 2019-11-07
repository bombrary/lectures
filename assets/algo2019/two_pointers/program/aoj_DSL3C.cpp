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
  ll N, Q;
  cin >> N >> Q;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (ll q = 0; q < Q; q++) {
    ll x;
    cin >> x;
    ll ans = 0;
    for (ll l = 0; l < N; l++) {
      ll r, sum = 0;
      for (r = l; r < N; r++) {
        sum += a[r];
        if (sum > x) break;
      }
      ans += r - l;
    }
    cout << ans << endl;
  }
  return 0;
}
