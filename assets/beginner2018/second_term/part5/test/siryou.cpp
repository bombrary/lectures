int& ar;
vector<int>& vr;
void func(vector<int>& v) { ... }

#include <iostream>

using namespace std;

void divide(int a, int b, int& q, int& r) {
  q = a / b;
  r = a % b;
}

int main()
{
  int a = 16;
  int b = 3;
  int q, r;

  divide(a, b, q, r);
  cout << q << ' ' << r << endl;

  return 0;
}


#include <stdio.h>
void showArray(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(void)
{
    int x[5] = {2, 4, 6, 8, 10};
    showArray(x, 5);
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

void showArray(vector<int> v)
{
  int i;
  for(i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

int main(void)
{
  vector<int> u = {2, 4, 6, 8, 10};
  showArray(u);

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void showArray(vector<int>& v)
{
  int i;
  for(i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

int main(void)
{
  vector<int> u = {2, 4, 6, 8, 10};
  showArray(u);

  return 0;
}

const int a = 10;
int add(const int a, const int b)
{
  return a + b;
}
void showArray(const vector<int>& v)
{
  int i;
  for(i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

for (型 要素名 : コンテナ名) { ... }

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  vector<int> v = {1, 2, 3 ,4, 5};

  int sum = 0;
  for (int e : v) {
    sum += e;
  }
  cout << sum << endl;

  return 0;
}

for (int e : v) {
  sum += e;
}
for (int i = 0; i < v.size(); i++) {
  sum += v[i];
}
for (auto itr = v.begin(); itr != v.end(); itr++) {
  sum += *itr;
}

for (const auto& e : v) {
  sum += e;
}

