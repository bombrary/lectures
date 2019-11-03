#include <iostream>

using namespace std;

long long sum[110000];

int main() {
	int N, K;
	cin >> N >> K;
	sum[0] = 0;
	for(int i = 1; i <= N ; i++) {
		long long a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	
	long long ans = 0;
	for(int i = 0; i < N - K + 1; i++) {
		ans += sum[i + K] - sum[i];
	}
	cout << ans << endl;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;

  int rE = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'E') rE++;
  }

  int lW = 0;
  int ans = 1100000000;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'E') rE--;
    ans = min(ans, lW + rE);
    if (S[i] == 'W') lW++;
  }
  cout << ans << endl;

  return 0;
}

#include <iostream>

using namespace std;

int t[1200000];

int main()
{
  int N, T;
  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    t[A]++;
    t[A + T]--;
  }
  for (int i = 0; i < 1200000; i++) {
    t[i + 1] += t[i];
  }

  int ans = 0;
  for (int i = 0; i < 1200000; i++) {
    if (t[i] > 0) ans++;
  }
  cout << ans << endl;

  return 0;
}
#include <iostream>

using namespace std;

int col[1100000];
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    col[a]++;
    col[b + 1]--;
  }
  for (int i = 0; i < 1100000; i++) {
    col[i + 1] += col[i];
  }

  int ans = -1;
  for (int i = 0; i < 1100000; i++) {
    ans = max(ans, col[i]);
  }
  cout << ans << endl;

  return 0;
}

#include <iostream>

using namespace std;

int t[1200000];

int main()
{
  int N, T;
  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    t[A] = T;
  }
  for (int i = 0; i < 1200000; i++) {
    t[i + 1] = max(t[i] - 1, t[i + 1]);
  }

  int ans = 0;
  for (int i = 0; i < 1200000; i++) {
    if (t[i] > 0) ans++;
  }
  cout << ans << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  long long l = 0, r = 0;
  for (int i = 0; i < K; i++) {
    r += a[i];
  }
  long long ans = r - l;
  for (int i = 0; i < N - K; i++) {
    l += a[i];
    r += a[i + K];
    ans += r - l;
  }
  cout << ans << endl;

  return 0;
}