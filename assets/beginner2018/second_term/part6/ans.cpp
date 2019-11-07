#include <iostream>
#include <vector>

using namespace std;

int ball[10];

bool dfs(int l, int r, int cnt)
{
  if (cnt == 10) return true;

  if (l < ball[cnt] && dfs(ball[cnt], r, cnt + 1)) return true;
  if (r < ball[cnt] && dfs(l, ball[cnt], cnt + 1)) return true;

  return false;
}

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int i = 0; i < 10; i++) {
      cin >> ball[i];
    }
    if (dfs(-1, -1, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

#include <stdio.h>

int main(void) {
  int K, S;
  int X, Y, Z;
  int ans = 0;
  
  scanf("%d %d", &K, &S);
  for(X = 0; X <= K; X++) {
    for(Y = 0; Y <= K; Y++) {
      Z = S - X - Y;
      if(0 <= Z && Z <= K) ans++;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}

#include <iostream>
#include <vector>
#define LLINF 110000000000000000

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long ans = LLINF;
  for (int X = -100; X <= 100; X++) {
    long long ret = 0;
    for (int i = 0; i < N; i++) {
      ret += (A[i] - X)*(A[i] - X);
    }
    ans = min(ret, ans);
  }
  cout << ans << endl;

  return 0;
}
