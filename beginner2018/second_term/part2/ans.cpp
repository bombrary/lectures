#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  vector<int> v;
  for (int i = a; i <= b; i++) {
    v.push_back(i);
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;

  return 0;
}


#include <stdio.h>

int main(void)
{
  int a, b;
  int buf[10000];

  scanf("%d %d", &a, &b);
  for (int i = 0; i <= b - a; i++) {
    buf[i] = i + a;
  }

  for (int i = 0; i <= b - a; i++) {
    printf("%d ", buf[i]);
  }
  printf("\n");

  return 0;
}

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v(N);
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  
  for (int i = 0; i < N; i++) {
    cout << v[i].size() << endl;
  }
  
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  
  string ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') ans += '0';
    else if (s[i] == '1') ans += '1';
    else if (s[i] == 'B' && !ans.empty()) ans.pop_back();
  }
  cout << ans << endl;
  
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int ap = 0;
  int zp = s.size() - 1;
  while(s[ap] != 'A') ap++;
  while(s[zp] != 'Z') zp--;
  cout << (zp - ap + 1) << endl;

  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
  string s;
  cin >> s;
  
  int ap = s.find("A");
  int zp = s.rfind("Z");
  
  cout << (zp - ap + 1) << endl;
  
  return 0;
}
