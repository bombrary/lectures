#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
  int n, qt;
  cin >> n >> qt;
  queue<pair<string, int>> q;
  
  for (int i = 0; i < n; i++) {
    string name;
    int ttime;
    cin >> name >> ttime;
    q.push(make_pair(name, ttime));
  }

  int time = 0;
  while (! q.empty()) {
    pair<string, int> tmp = q.front(); q.pop();
    if (tmp.second > qt) {
      time += qt;
      tmp.second -= qt;
      q.push(tmp);
    } else {
      time += tmp.second;
      cout << tmp.first << ' ' << time << endl;
    }
  }
  
  return 0;
}
