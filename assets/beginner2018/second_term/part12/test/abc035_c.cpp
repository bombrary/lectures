#include <iostream>

using namespace std;

int imos[210000];
int main()
{
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    imos[l]++;
    imos[r + 1]--;
  }

  int now = 0;
  for (int i = 1; i <= N; i++) {
    now += imos[i];
    if (now % 2) cout << '1';
    else cout << '0';
  }
  cout << endl;

  return 0;
}
