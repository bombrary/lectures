#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<bool> appeared(110000, false);
  int r = 0, ans = 0;
  for (int l = 0; l < N; l++) {
    while (r < N) {
      if (appeared[A[r]]) break;
      appeared[A[r]] = true;
      r++;
    }
    ans = max(ans, r - l);
    if (r == l) r++;
    else appeared[A[l]] = false;
  }
  cout << ans << endl;
  return 0;
}
