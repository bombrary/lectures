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

ll splitAndList(ll n, ll m, vector<ll>& a)
{
  // Split
  vector<ll> S1(a.begin(), a.begin() + n/2);
  vector<ll> S2(a.begin() + n/2, a.end());

  // List
  vector<ll> T1;
  for (int b = 0; b < (1 << S1.size()); b++) {
    ll sum = 0;
    for (int i = 0; i < S1.size(); i++) {
      if ((b >> i) & 1) (sum += S1[i]) %= m;
    }
    T1.push_back(sum);
  }
  vector<ll> T2;
  for (int b = 0; b < (1 << S2.size()); b++) {
    ll sum = 0;
    for (int i = 0; i < S2.size(); i++) {
      if ((b >> i) & 1) (sum += S2[i]) %= m;
    }
    T2.push_back(sum);
  }
  sort(T2.begin(), T2.end());

  ll ret = 0;
  for (int i = 0; i < T1.size(); i++) {
    // T1[i] + T2[j] < m
    int j = lower_bound(T2.begin(), T2.end(), m - T1[i]) - T2.begin();
    if (j <= 0) continue;
    ret = max(ret, T1[i] + T2[j-1]);
  }
  return ret;
}

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << splitAndList(n, m, a) << endl;
  return 0;
}
