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

ll knapsack(vector<P>& S, ll W)
{
  vector<P> S1, S2;
  for (int i = 0; i < S.size(); i++) {
    if (i < S.size()/2) S1.push_back(S[i]);
    else S2.push_back(S[i]);
  }

  vector<P> T1, T2;
  for (int b = 0; b < (1 << S1.size()); b++) {
    P item(0, 0);
    for (int i = 0; i < S1.size(); i++) {
      if ((b >> i) & 1) {
        item.first  += S1[i].first;
        item.second += S1[i].second;
      }
    }
    T1.push_back(item);
  }
  for (int b = 0; b < (1 << S2.size()); b++) {
    P item(0, 0);
    for (int i = 0; i < S2.size(); i++) {
      if ((b >> i) & 1) {
        item.first  += S2[i].first;
        item.second += S2[i].second;
      }
    }
    T2.push_back(item);
  }


  sort(T2.begin(), T2.end());
  vector<P> T2p;
  if (!T2.empty()) T2p.push_back(T2[0]);
  for (int i = 1; i < T2.size(); i++) {
    if (T2p.back().second < T2[i].second) {
      T2p.push_back(T2[i]);
    }
  }

  ll ret = -1;
  for (int i = 0; i < T1.size(); i++) {
    if (T1[i].first > W) continue;
    auto itr = lower_bound(T2p.begin(), T2p.end(), make_pair(W - T1[i].first, LLINF)) - 1;
    ret = max(ret, T1[i].second + itr->second);
  }
  return ret;
}

int main()
{
  ll N, W;
  cin >> N >> W;
  vector<P> S;
  for (int i = 0; i < N; i++) {
    ll v, w;
    cin >> v >> w;
    S.push_back(make_pair(w, v));
  }
  cout << knapsack(S, W) << endl;

  return 0;
}
