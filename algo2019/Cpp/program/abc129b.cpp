#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  int ans = 1100000000;
  for (int i = 0; i < N-1; i++) {
    int S1 = 0, S2 = 0;
    for (int j = 0; j < N; j++) {
      if (j <= i) S1 += v[j];
      else S2 += v[j];
    }
    ans = min(ans, abs(S1-S2));
  }
  cout << ans << endl;
  return 0;
}
