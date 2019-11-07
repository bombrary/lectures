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

long long modpow(long long a, long long n)
{
  if (n == 0) return 1;
  long long b = modpow(a, n/2);
  b = b*b % MOD;
  if (n % 2 == 0) return b;
  else return a*b % MOD;
}

long long moddiv(long long a, long long b) {
  return (a * modpow(b, MOD - 2)) % MOD;
}


#define MAX_N 2000000
long long fact[MAX_N];
void factInit() {
  fact[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
}
// Combination(binomial coefficients)
long long comb(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return moddiv(fact[n], (fact[r] * fact[n - r]) % MOD);
}

int main()
{
  factInit();
  int H, W;
  cin >> H >> W;
  cout << comb(H + W - 2, H - 1) << endl;
  return 0;
}
