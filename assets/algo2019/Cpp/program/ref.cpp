#include <iostream>
#include <vector>

using namespace std;

void showVec(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
int main()
{
  vector<int> v = {1, 2, 3, 4};
  showVec(v);
  return 0;
}
