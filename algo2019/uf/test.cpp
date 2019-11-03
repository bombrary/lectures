#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> par{0, 1, 2, 1, 4, 1, 4, 1, 1, 4, 1, 4, 1};
  int x, y;
  cin >> x >> y;
  if (par[x] == par[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
