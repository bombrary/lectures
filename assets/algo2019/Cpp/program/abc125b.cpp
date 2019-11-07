#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> V(N), C(N);
  for_each(V.begin(), V.end(), [](int& e) { cin >> e; });
  for_each(C.begin(), C.end(), [](int& e) { cin >> e; });

  vector<int> diffv, posiv;
  auto sub = [](int& v, int &c) { return v - c; };
  auto isPositive = [](int &x) { return x > 0; };

  transform(V.begin(), V.end(), C.begin(), back_inserter(diffv), sub);
  copy_if(diffv.begin(), diffv.end(), back_inserter(posiv), isPositive);
  cout << accumulate(posiv.begin(), posiv.end(), 0) << endl;
  return 0;
}
