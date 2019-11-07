#include <iostream>
#include <string>

using namespace std;

int hist[26];
int main()
{
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    hist[S[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (hist[i] % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
