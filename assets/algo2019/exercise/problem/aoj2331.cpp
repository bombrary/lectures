#include <iostream>
#include <vector>

using namespace std;

int psum[110000];
int main()
{
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    psum[a]++;
    psum[b+1]--;
  }
  for (int i = 0; i < 100010; i++) {
    psum[i + 1] += psum[i];
  }
  int ans = 0;
  for (int i = 1; i < 100010; i++) {
    if (psum[i] >= i-1) ans = i-1;
  }
  cout << ans << endl;
  return 0;
}
