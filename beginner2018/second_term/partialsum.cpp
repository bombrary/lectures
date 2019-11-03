#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    int sum = 0;
    for (int j = l; j <= r; j++) {
      sum += a[j];
    }
    cout << sum << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a;
vector<int> s;

// 2.累積和から部分和を計算するパート
int psum(int i, int j)
{
  if (i > j) swap(i, j);
  if (i == 0) return s[j];
  else return s[j] - s[i - 1];
}

int main()
{
  cin >> N;
  a.resize(N);
  s.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  // 1.累積和を作るパート
  s[0] = a[0];
  for (int i = 1; i < N; i++) {
    s[i] = s[i - 1] + a[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << psum(l, r) << endl;;
  }

  return 0;
}


int main()
{
  cin >> N;
  a.resize(N);
  s.resize(N);

  // 0.累積和を作るパート
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s[i] = a[i];
  }

  // 1.累積和を作るパート
  for (int i = 1; i < N; i++) {
    s[i] += s[i - 1];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << psum(l, r) << endl;;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;


int main()
{
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<int> s(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  // 1.累積和を作るパート
  s[0] = 0;
  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + a[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l++; r++;
    // 2.累積和を求めるパート
    cout << (s[r] - s[l - 1]) << endl;;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;


int main()
{
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<int> s(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    s[i] = a[i];
  }

  // 1.累積和を作るパート
  s[0] = 0;
  for (int i = 0; i < N; i++) {
    s[i + 1] += s[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l++; r++;
    // 2.累積和を求めるパート
    cout << (s[r] - s[l - 1]) << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a;
vector<int> s;

int main()
{
  cin >> N;
  a.resize(N);
  s.resize(N);

  // 0.累積和を作るパート
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s[i] = a[i];
  }

  // 1.累積和を作るパート
  for (int i = 1; i < N; i++) {
    s[i] += s[i - 1];
  }

  for (int i = 0; i < N; i++) {
    cout << s[i] << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;


int main()
{
  int N;
  cin >> N;
  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  // 0,1: 累積和を作るパート & 出力するパート
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
    cout << sum << endl;
  }

  return 0;
}


