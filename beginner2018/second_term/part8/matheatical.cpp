bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return n != 1;
}

#define MAX_N 10000
vector<int> prime;
bool is_prime[MAX_N + 1];

void sieve(int n)
{
  for (int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (int j = 2 * i; j <= n; j += i)  is_prime[j] = false;
    }
  }
  return;
}

void prime_factor(int n, map<int, int>& res) {
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
}
int main()
{
  int N;
  cin >> N;

  map<int, int> mp;
  prime_factor(N, mp);
  for (auto e : mp) {
    cout << e.first << ' ' << e.second << endl;
  }

  return 0;
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
  int N;
  cin >> N;

  vector<int> v;
  divisor(N, v);
  sort(v.begin(), v.end());
  for (auto e : v) {
    cout << e << ' ';
  }
  cout << endl;

  return 0;
}

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


