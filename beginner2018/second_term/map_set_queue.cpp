map<キー型, 要素型> 名前;
map<int, int> mp1;
map<string, int> mp2;
map<char, pair<int, int>> mp3;

mp["Hello"] = 123;
mp1[100] = 20;
mp1[1234] = 0;
mp1[-1] = 0;
cout << mp1[-3] << endl;

mp2["Hello"] = 10;
mp2["World"] = 12;
mp2["good"] = 1;

mp3['a'].first = 120;
mp3['a'].second = 2;
mp3['b'] = make_pair(2, 33);

mp[100] = 10;
mp[12] = 12;
mp[-3] = 29;
mp[-1] = 30;
mp[6] = 1;

for (auto itr = mp.begin(); itr != mp.end(); itr++) {
cout << itr->first << ' '
     << itr->second << endl;
}
for (auto e : mp) {
cout << e.first << ' '
        << e.second << endl;
}


#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<int, int> mp;
  mp[100] = 10;
  mp[12] = 12;
  mp[-3] = 29;
  mp[-1] = 30;
  mp[6] = 1;
  mp[0] = 27;
  mp[10] = -1;

  for (auto e : mp) {
    cout << e.first << ' '
         << e.second << endl;
  }

  return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  map<string, int> mp;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }

  string name;
  int val = -1;
  for (auto e : mp) {
    if (val < e.second) {
      val = e.second;
      name = e.first;
    }
  }
  cout << name << endl;

  return 0;
}

mp[str] := 文字列strがいくつ現れたか

#include <iostream>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    mp[d]++;
  }
  cout << mp.size() << endl;

  return 0;
}


set<int> st1;
set<string> st2;

st1.insert(-1);
st1.insert(2);

if (st1.find(2) != st1.end())
cout << "Found." << endl;

st1.erase(2);

if (st1.empty())
cout << "Empty." << endl;

for (auto itr = st.begin(); itr != st.end(); itr++) {
    cout << *itr << ' ';
}
for (auto e : st) {
    cout << e << ' ';
}

#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<int> st;
  st.insert(-1);
  st.insert(100);
  st.insert(12);
  st.insert(13);
  st.insert(-21);
  st.insert(0);
  st.insert(20);

  for (auto e : st) {
    cout << e << ' ';
  }
  cout << endl;


  return 0;
}

#include <iostream>
#include <set>

using namespace std;

int main()
{
  int N;
  cin >> N;

  set<int> st;
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    st.insert(d);
  }
  cout << st.size() << endl;

  return 0;
}

queue<int> q;
q.push(123);
q.push(29);
q.push(10);
q.push(-1);
q.push(12);
q.push(2);

cout << q.front() << endl;
q.pop();
cout << q.front() << endl;

if (q.empty())
  cout << "Empty." << endl;

while (! q.empty()) {
  int tmp = q.front(); q.pop();
  cout << q.front() << ' ';
  q.pop();
}
cout << endl;
