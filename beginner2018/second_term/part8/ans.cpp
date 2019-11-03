#include <iostream>
#include <vector>

using namespace std;

// エラトステネスの篩

#define MAX_N 100000
vector<int> prime;
bool is_prime[MAX_N + 1];

int sieve(int n)
{
  int p = 0;
  for (int i = 0; i < n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}

int main()
{
  int n; cin >> n;
  sieve(n);
  cout << prime.size() << endl;

  return 0;
}

#include <iostream>

using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n != 1;
}

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (is_prime(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}

void divisor(int n, vector<int>& res) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
}

int main()
{
  int n; cin >> n;
  int a, b, c;
  cin >> a >> b;

  int g = gcd(a, b);
  if (n == 3) {
    cin >> c;
    g = gcd(g, c);
  }

  vector<int> v;
  divisor(g, v);
  sort(v.begin(), v.end());
  for (auto e : v) {
    cout << e << endl;
  }
  return 0;
}

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


