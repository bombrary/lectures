#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  
  ll r = 0, ans = 0;
  ll sum = 0;
  for (ll l = 0; l < N; l++) {
    while (r < N && (sum + A[r]) == (sum ^ A[r])) {
      sum += A[r];
      r++;
    }
    ans += r - l;
    if (r == l) r++;
    else sum -= A[l];
  }
  cout << ans << endl;
  return 0;
}
