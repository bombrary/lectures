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
constexpr int INF = 11000000;
constexpr long long LLINF = 1100000000000000000LL;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
  int n, m;
  while (cin >> n >> m, n|m) {
    int taro = 0, hanako = 0;
    vector<int> a(n), b(m);
    REP(i, n) {
      cin >> a[i];
      taro += a[i];
    }
    REP(i, m) {
      cin >> b[i];
      hanako += b[i];
    }

    int c1 = INF, c2 = INF;
    REP(i, n) {
      REP(j, m) {
        if (taro - a[i] + b[j] == hanako - b[j] + a[i]) {
          if (c1 + c2 > a[i] + b[j]) {
            c1 = a[i];
            c2 = b[j];
          }
        }
      }
    }
    if (c1 == INF && c2 == INF) cout << -1 << endl;
    else cout << c1 << ' ' << c2 << endl;
  }
  return 0;
}
