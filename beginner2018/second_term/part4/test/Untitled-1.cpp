#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int r[110] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		r[tmp]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		if (r[i] > 0) ans++;

	}
	cout << ans << endl;

	return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
  int a;
  unsigned b;
  vector<bool> v1;
  vector<int> v2;
  string s;

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(v1).name() << endl;
  cout << typeid(v2).name() << endl;
  cout << typeid(s).name() << endl;

  return 0;
}
