#include <stdio.h>

int main(void)
{
    printf("Hello, World!");
    return 0;
}

#include <iostream>

int main()
{
    int a, b;
    double c;

    cin >> a >> b >> c;
    cout << 

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, World" << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int c = a * b;
    cout << c;

    for (int i = 0; i < 10; i++) {
        cout << "Hello" << endl;
    }
    return 0;
}

struct Hoge h;
Hoge h;

class Hoge {
    int x;
    int y;
    void f() {
        std::cout << (x + y) << std::endl;
    }
}

struct Hoge {
    int x;
    int y;
}
void f(struct Hoge& h) {
    printf("%d\n", h->x + h->y);
}

#include <iostream>

using namespace std;

class Hoge {
  public:
    Hoge(int tx, int ty)
    {
      x = tx;
      y = ty;
    }
    void setX(int n) {
      x = n;
    }
    void setY(int n) {
      y = n;
    }
    int getSum() {
      return (x + y);
    }

  private:
    int x;
    int y;
};

int main()
{
  Hoge h(3, 5);
  cout << h.getSum() << endl;

  h.setX(12);
  h.setY(23);
  cout << h.getSum() << endl;

  return 0;
}


v.push_back(1);
v.size();
s.substr(2, 6);

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << str << ":" << endl
         << str[0] << str[3] << endl;

    return 0;
}

#include <cstdio>

using namespace std;

int main()
{
  printf("Hello, World!\n");
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;

  cout << str[0] << ' '
       << str[str.size() - 1] << endl;

  return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[1000];

  scanf("%s", str);
  printf("%c %c", str[0], str[strlen(str) - 1]);

  return 0;
}

#include <iostream>

using namespace std;

int main()
{
  int x = 4;
  int y = 3;

  bool flag = false;
  if (x % 2 == 1) flag = true;
  if (y % 2 == 1) flag = true;

  if (flag) cout << "Hello" << endl;
  else cout << "Bye" << endl;

  return 0;
}


/* ----------------------------------------- */
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a, b, c;
  string S;
  cin >> a >> b >> c >> S;
  cout << (a + b + c) << ' ' << S << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  if (a * b % 2 == 0)
    cout << "Even" << endl;
  else
    cout << "Odd" << endl;

  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int ans = 0;
  if (s[0] == '1') ans++;
  if (s[1] == '1') ans++;
  if (s[2] == '1') ans++;

  cout << ans << endl;

  return 0;
}

#include <iostream>
 
using namespace std;
 
int main()
{
  int A[220];
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
 
  int ans = 0;
  while(1) {
    bool flag = false;
    for (int i = 0; i < N; i++) {
      if (A[i] % 2 == 1) {
        flag = true;
        break;
      }
      A[i] /= 2;
    }
    if (flag) break;
    ans++;
  }
  cout << ans << endl;
 
  return 0;
}


#include <iostream>

using namespace std;

int main()
{
  int N;
  int A[220];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 0;
  while(1) {
    for (int i = 0; i < N; i++) {
      if (A[i] % 2 == 1) {
        cout << ans << endl;
        return 0;
      }
      A[i] /= 2;
    }
    ans++;
  }
}

