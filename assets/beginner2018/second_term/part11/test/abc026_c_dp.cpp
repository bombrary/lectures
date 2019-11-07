#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool mat[20][20];
int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vv(N);
  REP(i, M) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    mat[A][B] = mat[B][A] = true;
    vv[A].push_back(B);
    vv[B].push_back(A);
  }

  REP(i, N) {
    int ans = 0;
    for (auto to : vv[i]) {
      for (auto toto : vv[to]) {
        if (!mat[i][toto]) ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
