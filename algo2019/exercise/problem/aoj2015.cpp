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

int N, M;
ll whist[2000000], hhist[2000000];
int main()
{
  while (cin >> N >> M, N|M) {
    for (int i = 0; i < 2000000; i++) {
      whist[i] = hhist[i] = 0;
    }
    vector<int> h(N, 0), w(M, 0);
    for (int i = 0; i < N; i++) cin >> h[i];
    for (int i = 0; i < M; i++) cin >> w[i];

    for (int l = 0; l < N; l++) {
      ll sum = 0;
      for (int r = l; r < N; r++) {
        sum += h[r];
        hhist[sum]++;
      }
    }
    for (int l = 0; l < M; l++) {
      ll sum = 0;
      for (int r = l; r < M; r++) {
        sum += w[r];
        whist[sum]++;
      }
    }
    
    ll ans = 0;
    for (int i = 1; i < 2000000; i++) {
      ans += hhist[i] * whist[i];
    }
    cout << ans << endl;
  }
  return 0;
}
