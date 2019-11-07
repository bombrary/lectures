#include <iostream>
#include <queue>
#include <vector>
#define INF 1100000000

using namespace std;

int dist[110];
int main()
{
  for (int i = 0; i < 110; i++) dist[i] = INF;
  int n;
  cin >> n;
  vector<vector<int>> vv(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      vv[u].push_back(v);
    }
  }

  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (! q.empty()) {
    int from = q.front(); q.pop();
    for (auto to : vv[from]) {
      if (dist[to] > dist[from] + 1) {
        dist[to] = dist[from] + 1;
        q.push(to);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << (i + 1) << ' ';
    if (dist[i] == INF) cout << -1 << endl;
    else cout << dist[i] << endl;
  }

  return 0;
}
