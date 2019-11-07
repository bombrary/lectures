#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  for_each(H.begin(), H.end(), [](int& e) { cin >> e; });

  vector<int> Hmax;
  auto pmax = [](int& acc, int& e) { return max(acc, e); };
  partial_sum(H.begin(), H.end(), back_inserter(Hmax), pmax);

  vector<int> diffv;
  auto sub = [](int& h, int& hm) { return h - hm; };
  transform(H.begin(), H.end(), Hmax.begin(), back_inserter(diffv), sub);

  auto noneNegativeP = [](int& x) { return x >= 0; };
  cout << count_if(diffv.begin(), diffv.end(), noneNegativeP) << endl;

  return 0;
}
