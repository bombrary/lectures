#include <iostream>
#include <cmath>
#include <algorithm>
#define MOD 1000000007

using namespace std;

#define MOD 1000000007
long long modpow(long long a, long long n)
{
  long long ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret *= a;
    ret %= MOD;
    a = a*a % MOD;
    n /= 2;
  }
  return ret;
}

int main()
{
  long long a, n;
  cin >> a >> n;
  cout << modpow(a, n) << endl;
  return 0;
}
