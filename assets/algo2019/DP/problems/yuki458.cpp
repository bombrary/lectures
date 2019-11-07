#include <iostream>
#include <vector>

using namespace std;

// エラトステネスの篩  O(nloglogn)
#define MAX_N 20000
vector<long long> p;
bool is_prime[MAX_N + 1];
long long sieve(long long n)
{
  for (long long i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i <= n; i++) {
    if (is_prime[i]) {
      p.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
}

int dp[3000][21000];
int main()
{
  sieve(20000);
  for (int i = 0; i < 3000; i++) {
    for (int j = 0; j < 21000; j++) {
      dp[i][j] = -1;
    }
  }
  int N;
  cin >> N;

  dp[0][0] = 0;
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j <= N; j++) {
      if (dp[i][j] < 0) continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + p[i] <= N) {
        dp[i + 1][j + p[i]] = max(dp[i + 1][j + p[i]], dp[i][j] + 1);
      }
    }
  }
  cout << dp[p.size()][N] << endl;

  return 0;
}
