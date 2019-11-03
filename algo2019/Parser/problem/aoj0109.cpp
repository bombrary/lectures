#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
typedef string::const_iterator State;

int number(State& s);
int term(State& s);
int factor(State& s);
int expr(State& s);

int number(State& s) {
  int ret = 0;
  while(isdigit(*s)) {
    ret *= 10;
    ret += *s - '0';
    s++;
  }
  return ret;
}


int term(State& s) {
  int ret = factor(s);
  while (1) {
    char op = *s;
    if (op == '*') {
      s++;
      ret *= factor(s);
    } else if (op == '/'){
      s++;
      ret /= factor(s);
    } else {
      break;
    }
  }
  return ret;
}

int factor(State& s) {
  if (*s == '(') {
    s++;
    int ret = expr(s);
    s++;
    return ret;
  } else {
    return number(s);
  }
}

int expr(State& s){
  int ret = term(s);
  while(1){
    char op = *s;
    if (op == '+') {
      s++;
      ret += term(s);
    } else if (op == '-') {
      s++;
      ret -= term(s);
    } else {
      break;
    }
  }
  return ret;
}

int main()
{
  int n; cin >> n;
  while (n--) {
    string str;
    cin >> str;
    str.pop_back();
    State s = str.begin();
    cout << expr(s) << endl;
  }
  return 0;
}
