#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1100000000

using namespace std;

vector<int> tetra;
vector<int> teodd;
int dp1[2][1100000];
int dp2[2][1100000];
void makeTetrahedral()
{
  for (int n = 1; n*(n+1)*(n+2)/6 < 1100000; n++) {
    tetra.push_back(n*(n+1)*(n+2)/6);
    if ((n*(n+1)*(n+2)/6) % 2 == 1) teodd.push_back(n*(n+1)*(n+2)/6);
  }
  for(int i = 0; i < 1100000; i++) {
    dp1[0][i] = dp1[1][i] = INF;
  }
  
  // ふつうの正四面体数
  dp1[0][0] = 0;
  for (int i = 0; i < tetra.size(); i++) {
    for (int j = 0; j < 1100000; j++) {
      dp1[1][j] = min(dp1[1][j], dp1[0][j]);
      if (j + tetra[i] < 1100000) {
        dp1[1][j + tetra[i]] = min(dp1[1][j + tetra[i]], dp1[1][j] + 1);
      }
    }
    for (int j = 0; j < 1100000; j++) {
      dp1[0][j] = dp1[1][j];
      dp1[1][j] = INF;
    }
  }

  // 奇数の正四面体数
  for(int i = 0; i < 1100000; i++) {
    dp2[0][i] = dp2[1][i] = INF;
  }
  dp2[0][0] = 0;
  for (int i = 0; i < teodd.size(); i++) {
    for (int j = 0; j < 1100000; j++) {
      dp2[1][j] = min(dp2[1][j], dp2[0][j]);
      if (j + teodd[i] < 1100000) {
        dp2[1][j + teodd[i]] = min(dp2[1][j + teodd[i]], dp2[1][j] + 1);
      }
    }
    for (int j = 0; j < 1100000; j++) {
      dp2[0][j] = dp2[1][j];
      dp2[1][j] = INF;
    }
  }
}

int main()
{
  makeTetrahedral();
  int n;
  while (cin >> n, n) {
    cout << dp1[0][n] << ' ' << dp2[0][n]<< endl;
  }
  return 0;
}
