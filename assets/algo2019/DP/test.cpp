#include <iostream>
#include <vector>
#define INF 1100000000

using namespace std;

int main()
{
  vector<int> v(100);
  v[0] = 1; // O(1)

  int N;
  cin >> N;
  map<int, int> mp;
  mp[0] = 1; // O(log(mp.size()))

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

  for (auto& e : mp) {
     cout << e.first << ':' << e.second << endl; 
  }

  return 0;
}
