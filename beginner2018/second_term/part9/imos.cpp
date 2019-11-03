#include <iostream>

using namespace std;

int time[110000];

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int s, t;
    cin >> s >> t;
    for (int j = s; j <= t; j++) {
      time[j]++;
    }
  }

  int ans = -1;
  for (int i = 0; i <= 100000; i++) {
    ans = max(ans, time[i]);
  }
  cout << ans << endl;

  return 0;
}

#include <iostream>

using namespace std;

int time[110000];

int main()
{
  int N;
  cin >> N;

  // 1. 配列に値を設定
  for (int i = 0; i < N; i++) {
    int s, t;
    cin >> s >> t;
    time[s]++;
    time[t + 1]--;
  }

  // 2. 累積和をとる
  for (int i = 0; i <= 100000; i++) {
    time[i + 1] += time[i];
  }

  // 3. 値を調べる
  int ans = -1;
  for (int i = 0; i <= 100000; i++) {
    ans = max(ans, time[i]);
  }
  cout << ans << endl;

  return 0;
}