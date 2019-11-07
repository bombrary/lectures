#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
typedef string::const_iterator State;

int vars[3];
int not_op(int x) {
  return 2 - x;
}
int and_op(int x, int y) {
  if (x == 0 || y == 0) return 0;
  else if (x == 2 && y == 2) return 2;
  else return 1;
}
int or_op(int x, int y) {
  if (x == 2 || y == 2) return 2;
  else if (x == 0 && y == 0) return 0;
  else return 1;
}
int formula(State& s) {
  if (*s == '0' || *s == '1' || *s == '2') {
    int ret = *s - '0';
    s++;
    return ret;
  } else if (*s == 'P' || *s == 'Q' || *s == 'R') {
    int ret = vars[*s - 'P'];
    s++;
    return ret;
  } else if (*s == '-') {
    s++;
    int ret = not_op(formula(s));
    return ret;
  } else if (*s == '('){
    s++;
    int lval = formula(s);
    char op = *s;
    s++;
    int rval = formula(s);
    s++;
    if (op == '*') return and_op(lval, rval);
    else return or_op(lval, rval);
  } else {
    cout << "Error" << endl;
    return -1;
  }
}

int main()
{
  string str;
  while (cin >> str, str != ".") {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          vars[0] = i;
          vars[1] = j;
          vars[2] = k;
          State s = str.begin();
          if (formula(s) == 2) ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
