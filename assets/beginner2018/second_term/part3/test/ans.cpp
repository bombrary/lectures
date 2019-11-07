#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (v[i - 1] != v[i]) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

vector<int> newv;
newv.push_back(v[0]);
for (int i = 1; i < N; i++) {
  if (v[i - 1] != v[i]) {
    newv.push_back(v[i]);
  }
}

v.erase(unique(v.begin(), v.end()), v.end());
unique(first, last);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  int Alice = 0;
  int Bob = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) Alice += a[i];
    else Bob += a[i];
  }
  cout << (Alice - Bob) << endl;
  
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, Y;
  cin >> N >> Y;
  
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= N; k++) {
        if (i + j + k == N && 10000*i + 5000*j + 1000*k == Y) {
          cout << i << ' ' <<
                  j << ' ' <<
                  k << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, Y;
  cin >> N >> Y;
  
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N - i; j++) {
		int k = N - i - j;
      	if (10000*i + 5000*j + 1000*k == Y) {
        	cout << i << ' ' << j << ' ' << k << ' ' << endl;
          	return 0;
        }
    }
  }
  cout << "-1 -1 -1" << endl;
  
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, Y;
  cin >> N >> Y;
  
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N - i; j++) {
      int k = N - i - j;
      if (10000*i + 5000*j + 1000*k == Y) {
        cout << i << ' ' << j << ' ' << k << ' ' << endl;
          return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, Y;
  cin >> N >> Y;
  
  int t = Y/1000 - N;
  int x;
  if (t >= 4*N) x = -(N + t) / 5;
  else x = -t / 4;
  
  if (t >= 0 && 9*x <= -2*t) {
    int i = 4*x + t;
    int j = -9*x -2*t;
    int k = N - i - j;
    cout << i << ' ' << j << ' ' << k << endl;
  } else {
    cout << "-1 -1 -1" << endl;
  }
  
  return 0;
}



