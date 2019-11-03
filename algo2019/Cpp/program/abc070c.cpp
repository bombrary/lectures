#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
typedef long long ll;

long long gcd(long long a, long long b)
{
  while(b) {
    long long at = a;
    a = b;
    b = at % b;
  }
  return a;
}

int main()
{
  int N;
  cin >> N;
  vector<ll> T(N);
  for_each(T.begin(), T.end(), [](ll& e) { cin >> e; });
  auto lcm = [](ll acc, ll e) {
    if (e > acc) swap(acc, e);
    return acc / gcd(acc, e) * e;
  };
  cout << accumulate(T.begin(), T.end(), 1LL, lcm) << endl;
  return 0;
}
