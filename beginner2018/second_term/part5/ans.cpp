#include <iostream>

using namespace std;

int hist[1100000];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    hist[a]++;
  }
  
  int ans = -1;
  for (int i = 0; i < 1100000; i++) {
  	ans = max(ans, hist[i - 1] + hist[i] + hist[i + 1]);
  }
  cout << ans << endl;
  
  return 0;
}

string str = "Hello, World!";
cout << str.substr(0, 5) << endl;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  t[0] = x[0] = y[0] = 0;
  for (int i = 1; i <= N; i++) {
  	int dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    int dt = t[i] - t[i - 1];
    int rt = dt - dist;
    if (rt < 0 || rt % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  string S;
  cin >> S;

  string pat[4] = {"maerd", "remaerd", "esare", "resare"};
  reverse(S.begin(), S.end());
  int i = 0;
  while (i < S.size()) {
    bool flag = true;
    for (int j = 0; j < 4; j++) {
      if (S.substr(i, pat[j].size()) == pat[j]) {
        i += pat[j].size();
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string S;
	cin >> S;
	reverse(S.begin(), S.end());

	int i = 0;
	while(i < S.size()) {
		if(S.substr(i, 5) == "maerd") i += 5;
		else if(S.substr(i, 7) == "remaerd") i += 7;
		else if(S.substr(i, 5) == "esare") i += 5;
		else if(S.substr(i, 6) == "resare") i+= 6;
		else { cout << "NO" << endl; return 0; }
	}

	cout << "YES" << endl;

	return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    mp[A]++;
  }
  int ans = 0;
  for (auto e : mp) {
    if (e.second % 2 == 1) ans++;
  }
  cout << ans << endl;
  
  return 0;
}

#include <iostream>
#include <algorithm>
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
  sort(a.begin(), a.end());

  int ans = 0;
  int cnt = 1;
  for (int i = 0; i < N - 1; i++) {
    if (a[i] != a[i + 1]) {
      ans += cnt % 2;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  ans += cnt % 2;
  cout << ans << endl;

  return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string S;

int findOfString(string str, int p)
{
	bool flag = true;
	//cout << str << ':' << endl;
	for(int i = 0, size = str.size(); i < size; i++) {
		//printf("%c, %c\n", str[i], S[p + i]);
		if(str[i] != S[p + i]) {
			flag = false;
			break;
		}
	}
	if(flag) {
		return str.size();
	}else {
		return 0;
	}
}
int main(void)
{
	string buf[] = { "dream", "dreamer", "erase", "eraser" };
	cin >> S;
	reverse(S.begin(), S.end());
	for(int i = 0; i < 4; i++) {
		reverse(buf[i].begin(), buf[i].end());
	}
	for(int i = 0, size = S.size(); i < size;) {
		bool flag = true;
		for(int j = 0; j < 4; j++) {
			int n = findOfString(buf[j], i);
			if(n != 0) {
				flag = false;
				i += n;
				break;
			}
		}
		if(flag){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
