#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(string& S, string& T, int idx)
{
  for (int i = 0; i < T.size(); i++) {
    if (i + idx >= S.size()) return false;
    if (S[i + idx] != T[i] && S[i + idx] != '?') return false;
  }
  return true;
}

int main()
{
  string S, T;
  cin >> S >> T;
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());

  for (int i = 0; i < S.size(); i++) {
    if (check(S, T, i)) {
      for (int j = 0; j < T.size(); j++) {
        S[i + j] = T[j];
      }
      for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') S[i] = 'a';
      }
      reverse(S.begin(), S.end());
      cout << S << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;

  return 0;
}
