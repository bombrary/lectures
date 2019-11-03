#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N; cin >> N;
  vector<int> p(N);
  for_each(p.begin(), p.end(), [](int& e){ cin >> e; });
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      swap(p[i], p[j]);
      if (is_sorted(p.begin(), p.end())) {
        cout << "YES" << endl;
        return 0;
      }
      swap(p[i], p[j]);
    }
  }
  cout << "NO" << endl;
  return 0;
}
