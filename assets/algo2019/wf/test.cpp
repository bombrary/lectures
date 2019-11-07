#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

constexpr ll INF = 110000000000;

vector<vector<P>> edge;
ll dist[110000];
void dijkstra(int s)
{
  for (int i = 0; i < 110000; i++) {
    dist[i] = INF;
  }
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(make_pair(0, s));  // (コスト, 点)の順に注意
  dist[s] = 0;
  while (!pq.empty()) {
    auto tmp = pq.top(); pq.pop();
    int v = tmp.second;
    if (dist[v] < tmp.first) continue;

    for (auto to : edge[v]) {
      int nv = to.first;
      ll cost = to.second;
      if (dist[v] + cost < dist[nv]) {
        dist[nv] = dist[v] + cost;
        pq.push(make_pair(dist[nv], nv));
      }
    }
  }
}

int main()
{
  int V, E, r;
  cin >> V >> E >> r;
  edge.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge[s].push_back(make_pair(t, d));
  }
  dijkstra(r);
  for (int i = 0; i < V; i++) {
    if (dist[i] < INF) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
}

