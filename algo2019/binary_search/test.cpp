#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define PB push_back

using namespace std;
typedef long long ll;

int main()
{
  int N; cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll lb = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    ll ub = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
    ans += lb * (N - ub);
  }
  cout << ans << endl;

  return 0;
}

