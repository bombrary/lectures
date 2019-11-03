#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
  if (b > a) swap(a, b);
  return a / gcd(a, b) * b;
}

int main()
{
  int N;
  cin >> N;
  long long l = 1;
  for (int i = 0; i < N; i++) {
    long long T;
    cin >> T;
    l = lcm(l, T);
  }
  cout << l << endl;

  return 0;
}
