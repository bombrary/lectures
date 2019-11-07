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

ll splitAndList(ll N, ll X, vector<ll>& w)
{
  vector<ll> S1(w.begin(), w.begin() + w.size()/2);
  vector<ll> S2(w.begin() + w.size()/2, w.end());

  vector<ll> T1;
  for (int b = 0; b < (1 << S1.size()); b++) {
    ll sum = 0;
    for (int i = 0; i < S1.size(); i++) {
      if ((b >> i) & 1) sum += S1[i];
    }
    T1.push_back(sum);
  }
  vector<ll> T2;
  for (int b = 0; b < (1 << S2.size()); b++) {
    ll sum = 0;
    for (int i = 0; i < S2.size(); i++) {
      if ((b >> i) & 1) sum += S2[i];
    }
    T2.push_back(sum);
  }

  map<ll, ll> mp;
  for (auto e : T1) mp[e]++;
  ll ret = 0;
  for (auto e : T2) ret += mp[X - e];

  return ret;
}

int main()
{
  ll N, X;
  cin >> N >> X;
  vector<ll> w(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }
  cout << splitAndList(N, X, w) << endl;
  return 0;
}
