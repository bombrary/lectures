#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
  int r, D, xt;
  cin >> r >> D >> xt;
  vector<int> x(10);
  generate(x.begin(), x.end(), [&]() {
      xt = r * xt - D;
      return xt;
  });
  copy(x.begin(), x.end(), ostream_iterator<int>(cout, "\n"));
  return 0;
}
