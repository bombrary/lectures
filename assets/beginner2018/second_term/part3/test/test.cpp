#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(d.begin(), d.end());

  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (v[i - 1] != v[i]) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
