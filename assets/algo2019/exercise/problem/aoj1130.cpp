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

char mp[50][50];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int main()
{
  int w, h;
  while (cin >> w >> h, w|h) {
    int sy, sx;

    for (int i = 0; i < 50; i++) {
      for (int j = 0; j < 50; j++) {
        mp[i][j] = '#';
      }
    }
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> mp[i][j];
        if (mp[i][j] == '@') {
          mp[i][j] = '#';
          sy = i;
          sx = j;
        }
      }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    int ans = 1;
    while (!q.empty()) {
      int y = q.front().first; 
      int x = q.front().second; 
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (mp[ny][nx] == '.') {
          mp[ny][nx] = '#';
          ans++;
          q.push(make_pair(ny, nx));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
