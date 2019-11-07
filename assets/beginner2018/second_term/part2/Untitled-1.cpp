#include <iostream>

using namespace std;

template<typename T>
T sum(T x, T y)
{
  return x + y;
}

int main()
{
  cout << sum<int>(10, 12) << endl;
  cout << sum<double>(3.14, 2.23) << endl;
  return 0;
}

int sum(int x, int y)
{
    return x + y;
}

double sum(double x, double y)
{
    return x + y;
}

vector<int> vi(100);
vector<string> vs(100, "");
vector<vector<int>> vvi;
pair<char, int> p;
map<string, int> mp;
queue<pair<int, int>> q;
vector<vector<pair<int, int>>> g;

vector<int> v;
vector<int> vi(100);
vector<char> vi2(100, 'a');

int N;
cin >> N;
vector<int> v(N);

vi[10] = 123;
v.push_back(345);
v.push_back(567);
cout << v.front() << endl;
cout << v.back() << endl;
vi2.pop_back();

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

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
  }
  cout << sum << endl;

  return 0;
}

  vector<int> a;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  string str1 = "Hello";
  string str2 = ", World";
  string str3 = str1 + str2;
  str3 += '!';
  cout << str3 << endl;
  cout << "size: " << str3.size() << endl;

  string str4;
  cin >> str4;
  for (int i = 0; i < str4.size(); i++) {
    cout << str4[i] << endl;
  }

  string sa = "abc", sb = "def";
  if (sa > sb)
    cout << sa << " > " << sb << endl;
  else
    cout << sa << " <= " << sb << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(12);
  v.push_back(24);
  v.push_back(1243);
  v.push_back(-23);

  vector<int>::iterator itr;
  for (itr = v.begin(); itr != v.end(); itr++) {
    cout << *itr << endl;
  }

  return 0;
}


#include <stdio.h>

int main(void)
{
  char str[20] = "Hello, World";
  char *p;

  for (p = str; *p != '\0'; p++) {
    printf("%c\n", *p);
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(12);
  v.push_back(24);
  v.push_back(1243);
  v.push_back(-23);
  v.push_back(0);

  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;


  return 0;
}

sort(v.begin(), v.end(), greater<int>());

pair<int, int> p1;
pair<string, int> p2;
pair<int, pair<int, int>> p3;

p1.first = 12;
p2.second = 10;

p2.first = "Taro";
p2.second = 170;

cout << p2.first << ' ' << p2.second << endl;

pair<int, int> p1;
p1 = make_pair(12, 10);

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<pair<string, int>> v;
  v.push_back(make_pair("Taro", 170));
  v.push_back(make_pair("Jiro", 190));
  v.push_back(make_pair("Saburo", 200));

  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << ' '
         << v[i].second << endl;
  }

  return 0;
}


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<int> v = {1, 3, 2, 4, 5};
  string str = "Hello, World!";

  reverse(v.begin(), v.end());
  reverse(str.begin(), str.end());

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;

  cout << str << endl;

  return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(12);
  v.push_back(24);
  v.push_back(1243);
  v.push_back(3);

  vector<int>::iterator itr = v.begin();
  itr++;
  itr++;
  cout << (itr - v.begin()) << endl;

  return 0;
}

vector<int>::iter iter = v.begin();
auto iter = v.begin();

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(12);
  v.push_back(24);
  v.push_back(1243);
  v.push_back(3);
  v.push_back(-1);

  auto res1 = find(v.begin(), v.end(), 1243);
  auto res2 = find(v.begin(), v.end(), 456);

  if (res1 != v.end())
    cout << res1 - v.begin() << endl;
  else 
    cout << "Not Found." << endl;

  if (res2 != v.end())
    cout << res2 - v.begin() << endl;
  else
    cout << "Not Found." << endl;

  return 0;
}

int res = -1;
for (int i = 0; i < N; i++) {
  res = max(res, a[i]);
}

int ans = 0;
for(int i = 0; i <= A; i++) {
  for(int j = 0; j <= B; j++) {
    for(int k = 0; k <= C; k++) {
      if(i * 10 + j * 2 + k == X) {
        ans++;
      }
    }
  }
}

vector<pair<int, int>> v;
v.push_back(make_pair(1, 2));
v.push_back(make_pair(6, 21));

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<pair<int, int>> v;
  v.push_back(make_pair(1, 2));
  v.push_back(make_pair(2, -1));
  v.push_back(make_pair(-2, 1));
  v.push_back(make_pair(2, 10));

  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << "(" << v[i].first
        << ", " << v[i].second << ")" << endl;
  }

  return 0;
}

vector<vector<int>> v(3);
v[0].push_back(2);
v[0].push_back(0);
v[1].push_back(2);
v[1].push_back(0);
v[0].push_back(2);
v[1].push_back(1);
v[2].push_back(1);
v[1].push_back(1);
v[2].push_back(1);
