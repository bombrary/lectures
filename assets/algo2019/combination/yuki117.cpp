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
typedef string::const_iterator State;

int number(State &s) {
  int ret = 0;
  while (isdigit(*s)) {
    ret *= 10;
    ret += *s - '0';
    s++;
  }
  return ret;
}

pair<char, pair<int, int>> parse(State &s) {
  pair<char, pair<int, int>> ret;
  ret.first = *s++;
  s++;
  ret.second.first = number(s);
  s++;
  ret.second.second = number(s);
  return ret;
}

long long modpow(long long a, long long n)
{
  long long ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret *= a;
    ret %= MOD;
    a = a*a % MOD;
    n /= 2;
  }
  return ret;
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
long long comb(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return moddiv(fact[n], (fact[r] * fact[n - r]) % MOD);
}
long long perm(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return moddiv(fact[n], fact[n - r]);
}
long long homo(int n, int r) {
	if (n == 0 && r == 0) return 1;
  return comb(n + r - 1, r);
}

int main()
{
  factInit();
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    string S;
    cin >> S;
    State begin = S.begin();
    pair<char, pair<int, int>> tmp = parse(begin);
    int c = tmp.first;
    int n = tmp.second.first;
    int r = tmp.second.second;
    if (c == 'C') cout << comb(n, r) << endl;
    if (c == 'P') cout << perm(n, r) << endl;
    if (c == 'H') cout << homo(n, r) << endl;
  }
  return 0;
}
