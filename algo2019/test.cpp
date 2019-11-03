#include <iostream>
#include <queue>
#include <vector>
#define LLINF 1100000000000000000
#define NODE 110000

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
vector<vector<P>> edge(NODE);
ll dist[NODE];
void dijkstra(int start)
{
  for (int i = 0; i < NODE; i++) dist[i] = LLINF;
  dist[start] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    // Take out the elem from pq
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
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge[s].push_back(make_pair(t, d));
  }
  dijkstra(r);
  for (int i = 0; i < V; i++) {
    if (dist[i] >= LLINF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }
  return 0;
}
