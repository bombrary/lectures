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

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int mp[60][60];
void dfs(int y, int x)
{
  REP(i, 8) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (mp[ny][nx] == 1) {
      mp[ny][nx] = 0;
      dfs(ny, nx);
    }
  }
}

void init()
{
  REP(i, 60) REP(j, 60) mp[i][j] = 0;
}
int main()
{
  int w, h;
  while (cin >> w >> h, w|h) {
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> mp[i][j];
      }
    }
    int ans = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (mp[i][j] == 1) {
          ans++;
          mp[i][j] = 0;
          dfs(i, j);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
