#include <iostream>
#include <vector>
#define LLINF 1100000000000000000LL

using namespace std;
typedef long long ll;

int main()
{
  ll C;
  cin >> C;
  for (int cnt = 0; cnt < C; cnt++) {
    ll N, S;
    cin >> N >> S;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
      cin >> a[i];
    }
    ll r = 0, sum = 0;
    ll ans = LLINF;
    for (ll l = 0; l < N; l++) {
      while (r < N && sum + a[r] < S) {
        sum += a[r];
        r++;
      }
      if (r == N) break;
      else ans = min(ans, r - l + 1);

      if (r == l) r++;
      else sum -= a[l];
    }
    if (ans == LLINF) cout << 0 << endl;
    else cout << ans << endl;
  }
  return 0;
}
