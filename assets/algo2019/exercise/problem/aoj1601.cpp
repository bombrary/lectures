#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pat[] = {5, 7, 5, 7, 7};
bool check(vector<int>& w, int start)
{
  int sum = 0, idx = 0;
  for (int i = start; i < w.size(); i++) {
    sum += w[i];
    if (sum == pat[idx]){
      idx++;
      sum = 0;
    } else if (sum > pat[idx]) {
      return false;
    }
    if (idx == 5) return true;
  }
  return false;
}
int getShortPhrase(vector<int>& w)
{
  for (int i = 0; i < w.size(); i++) {
    if (check(w, i)) return i;
  }
  return -1;
}

int main()
{
  int n;
  while (cin >> n, n) {
    vector<int> w;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      w.push_back(s.size());
    }
    cout << (getShortPhrase(w) + 1) << endl;
  }
}
