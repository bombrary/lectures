#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }

  vector<long long> minus;
  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    long long tmp = a[i] - b[i];
    if (tmp < 0) minus.push_back(tmp);
    else if (tmp > 0) cnt += tmp;
  }
  
  bool flag = true;
  long long sum = 0;
  for (int i = 0; i < minus.size(); i++) {
    if (-minus[i] % 2 == 1) {
      flag = false;
      break;
    }
    sum += minus[i];
  }

  if (flag && sum + 2*cnt <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
