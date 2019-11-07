#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interval_scheduling(int N, vector<int>& vs, vector<int>& vt) {
  vector<pair<int, int>> itv;
  for (int i = 0; i < N; i++) {
    itv.push_back(make_pair(vt[i], vs[i]));
  }
  sort(itv.begin(), itv.end());

  int ans = 0, t = 0;
  for (int i = 0; i < N; i++) {
    if (t <= itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }
  return ans;
}

int main()
{
  int N, M; cin >> N >> M;
  vector<int> s(M), t(M);
  for (int i = 0; i < M; i++) cin >> s[i] >> t[i];
  cout << interval_scheduling(M, s, t) << endl;
  return 0;
}
