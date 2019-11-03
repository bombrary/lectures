#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  for (int l = 0; l < N; l++) {
    int sum = 0, xsum = 0;
    for (int r = l; r < N; r++) {
      sum += A[r];
      xsum ^= A[r];
      if (sum == xsum) {
        cout << "[" << l << ", " << r << "]" << endl;
      }
    }
  }
  return 0;
}
