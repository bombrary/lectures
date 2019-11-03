#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(make_pair(a, i + 1));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    for (int i = 0; i < N; i++) {
        cout << v[i].second << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> v(N, 0);
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    v[a]++; v[b]++;
  }
  
  for (int i = 0; i < N; i++) {
    cout << v[i] << endl;
  }
  
  return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> hist(N + 1, 0);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    hist[A]++;
  }

  sort(hist.begin(), hist.end());
  int ans = 0;
  for (int i = 0; i <= N - K; i++) {
    ans += hist[i];
  }
  cout << ans << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> hist(N + 1, 0);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    hist[A]++;
  }

  sort(hist.begin(), hist.end(), greater<int>());
  int tmp = 0;
  for (int i = 0; i < K; i++) {
    tmp += hist[i];
  }
  cout << (N - tmp) << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main()
{
  int N;
  int hist[9] = { };

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a < 3200) hist[a/400]++;
    else hist[8]++;
  }

  int sum = 0;
  for (int i = 0; i < 8; i++) {
    if (hist[i] > 0) sum++;
  }
  if (sum == 0) cout << 1 << ' ';
  else cout << sum << ' ';
  
  cout << sum + hist[8] << endl;

  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, L;
  cin >> N >> L;
  vector<string> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    cout << v[i];
  }
  cout << endl;
  
  return 0;
}