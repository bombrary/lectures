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

typedef long long ll;
typedef pair<ll,ll> P;
#define NODE 100001
#define INF 1000000000
vector<vector<pair<ll,ll> > > v(NODE);
vector<vector<pair<ll,ll> > > u(NODE);
ll dist1[NODE];
ll dist2[NODE];
int dijkstra1(int start){
  for(int i = 0;i < NODE;i++)dist1[i] = INF;
  dist1[start] = 0;
  priority_queue<P,vector<P>,greater<P> > pq;
  pq.push(make_pair(0,start));
  while(!pq.empty()){
    P now = pq.top();pq.pop();
    ll d = now.first;
    ll node = now.second;
    if(dist1[node] < d)continue;
    for(int i = 0;i < v[node].size();i++){
      ll opp_n = v[node][i].first;
      ll opp_d = v[node][i].second;
      if(dist1[opp_n] > d + opp_d){
        dist1[opp_n] = d + opp_d;
        pq.push(make_pair(dist1[opp_n],opp_n));
      }
    }
  }
}

int dijkstra2(int start){
  for(int i = 0;i < NODE;i++)dist2[i] = INF;
  dist2[start] = 0;
  priority_queue<P,vector<P>,greater<P> > pq;
  pq.push(make_pair(0,start));
  while(!pq.empty()){
    P now = pq.top();pq.pop();
    ll d = now.first;
    ll node = now.second;
    if(dist2[node] < d)continue;
    for(int i = 0;i < u[node].size();i++){
      ll opp_n = u[node][i].first;
      ll opp_d = u[node][i].second;
      if(dist2[opp_n] > d + opp_d){
        dist2[opp_n] = d + opp_d;
        pq.push(make_pair(dist2[opp_n],opp_n));
      }
    }
  }
}

int main()
{
  ll N, M, T;
  cin >> N >> M >> T;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  REP(i, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v[a].PB(MP(b, c));
    u[b].PB(MP(a, c));
  }
  dijkstra1(0);
  dijkstra2(0);

  ll ans = -1;
  for (int i = 0; i < N; i++) {
    ll cost = T - dist1[i] - dist2[i];
    if (cost < 0) continue;
    ans = max(ans, cost*A[i]);
  }
  cout << ans << endl;

  return 0;
}
