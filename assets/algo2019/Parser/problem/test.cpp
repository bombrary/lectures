#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#define INF          1e9
#define INFLL        1e18
#define EPS          1e-9
#define MOD          1000000007
#define REP(i,n)     for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)    for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)    for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)   for(ll i=(n);i>0;--i)
#define REPC(i,obj)  for(auto i:obj)
#define ALL(obj)     (obj).begin(),(obj).end()
#define SETP(n)      cout<<fixed<<setprecision(n)
#define VV(T,h,w)    vector<vector<T>>(h,vector<T>(w))
#define VVI(T,h,w,i) vector<vector<T>>(h,vector<T>(w,i))
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

using state=string::const_iterator;
ll expr(state &, int d);
ll term(state &, int d);
ll fuct(state &, int d);
ll expr(state &s, int d)
{
  REP(i, d) cout << ' ';
  cout << "expr: " << *s << endl;
  ll ret = term(s, d + 1); ++s;
  while (true) {
    char opr = *s; ++s;
    ll arg = term(s, d + 1); ++s;
    if (opr == '+') {
      if (ret == 2 || arg == 2)ret = 2;
      else if (ret == 1 || arg == 1)ret = 1;
      else ret = 0;
    } else if (opr == '*') {
      if (ret == 0 || arg == 0)ret = 0;
      else if (ret == 1 || arg == 1)ret = 1;
      else ret = 2;
    } else {
      break;
    }
  }
  return ret;
}
ll term(state & s, int d)
{
  REP(i, d) cout << ' ';
  cout << "term: " << *s << endl;
  if (*s == '-') {
    ++s;
    return 2 - term(s, d + 1);
  } else {
    ll ret = fuct(s, d + 1); ++s;
    return ret;
  }
}
ll fuct(state & s, int d)
{
  REP(i, d) cout << ' ';
  cout << "fact: " << *s << endl;
  if (*s == '(') {
    ++s;
    ll ret = expr(s, d + 1);
    ++s;
    return ret;
  } else if (isdigit(*s)) {
    ll ret = *s - '0';
    ++s;
    return ret;
  }
}
int main()
{
  while (true) {
    if (string inp = in<string>(); inp[0] != '.') {
      ll ans = 0;
      for (int p = 0; p <= 2; ++p) {
        for (int q = 0; q <= 2; ++q) {
          for (int r = 0; r <= 2; ++r) {
            string exstr = inp;
            replace(ALL(exstr), 'P', to_string(p)[0]);
            replace(ALL(exstr), 'Q', to_string(q)[0]);
            replace(ALL(exstr), 'R', to_string(r)[0]);
            if (p == 0 && q == 2 && r == 0) {
              auto s = exstr.cbegin();
              int res = expr(s, 0);
              cout << exstr << ' ' << res << endl;
              ans += res == 2;
            }
          }
        }
      }
      cout << ans << endl;
    } else {
      break;
    }
  }
}
