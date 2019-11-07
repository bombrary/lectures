#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
  vector<int> v;
  auto itr = back_inserter(v);
  itr = 1; itr++;
  itr = 2; itr++;
  itr = 4; itr++;
  for(auto e : v) cout << e << ' ';
  cout << endl;
  return 0;
}
