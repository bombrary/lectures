#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vv;

int dfs(int x)
{
  if (vv[x].empty()) return 1;

  int ma = -1, mi = 1100000000;
  for (int i = 0; i < vv[x].size(); i++) {
    int tmp = dfs(vv[x][i]);
    ma = max(ma, tmp);
    mi = min(mi, tmp);
  }

  return ma + mi + 1;
}

int main()
{
  int N;
  cin >> N;
  vv.resize(N);
  for (int i = 1; i < N; i++) {
    int B;
    cin >> B;
    B--;
    vv[B].push_back(i);
  }
  cout << dfs(0) << endl;

  return 0;
}
