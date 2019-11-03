#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  long long l = 0, r = 0;
  for (int i = 0; i < K; i++) {
    r += a[i];
  }
  long long ans = r - l;
  for (int i = 0; i < N - K; i++) {
    l += a[i];
    r += a[i + K];
    ans += r - l;
  }
  cout << ans << endl;

  return 0;
}
