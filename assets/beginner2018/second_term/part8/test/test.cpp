#include <iostream>
#include <map>
#include <vector>

using namespace std;

// sqrt(N)で素数判定
bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n != 1;
}

// 約数列挙
void divisor(int n, vector<int>& dist) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      dist.push_back(i);
      if (i != n) dist.push_back(n / i);
    }
  }
}

// 素因数分解
void prime_factor(int n, map<int, int>& dist) {
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      dist[i]++;
      n /= i;
    }
  }
  if (n != 1) dist[n] = 1;
}

// エラトステネスの篩

/*#define MAX_N 10000
int prime[MAX_N];
bool is_prime[MAX_N + 1];

int sieve(int n)
{
  int p = 0;
  for (int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; i <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}*/

int main() {
  for (int i = 1; i < 100; i++) {
    if (is_prime(i)) cout << i << ' ';
  }

  return 0;
}
