sort(v.begin(), v.end());
do {
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
} while (next_permutation(v.begin(), v.end()));

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  do {
    for (int i = 0; i < n; i++) {
      cout << v[i] << ' ';
    }
    cout << endl;
  } while (next_permutation(v.begin(), v.end()));
  
  return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> pt;
vector<bool> used;
vector<int> v;
void dfs(int d)
{
  if (d == n) {
    for (int i = 0; i < pt.size(); i++) {
      cout << pt[i] << ' ';
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < v.size(); i++) {
    if (!used[i]) {
      used[i] = true;
      pt.push_back(v[i]);
      dfs(d + 1);
      pt.pop_back();
      used[i] = false;
    }
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    used.push_back(false);
  }
  dfs(0);
  
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> pt;
vector<int> v;
void dfs(int d, int used)
{
  if (d == n) {
    for (int i = 0; i < pt.size(); i++) {
      cout << pt[i] << ' ';
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < v.size(); i++) {
    if (!((used >> i) & 1)) {
      pt.push_back(v[i]);
      dfs(d + 1, used | (1 << i));
      pt.pop_back();
    }
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  dfs(0, 0);
  
  return 0;
}


bool dfs(int i, int sum)
{
    // sumがKを超えてしまったら,遷移を打ち切る
    if (sum > k) return false;  
    // 0～N-1まで見終わったら,今の総和がkかどうかを判定する.
    if (i == N) return sum == K;

    // 選ぶ,選ばない場合を試してみて,Kになる状態が発見できればtrue返す
    if (dfs(i + 1, sum      )) return true;
    if (dfs(i + 1, sum + a[i])) return true;

    // 選んでも選ばなくても,Kとなる状態が発見できなかった
    return false;
}

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> a;
int K, N;
bool dfs(int i, int sum, int rest)
{
  //これ以降の候補を加えてもKにならないなら,遷移を打ち切る
  if (sum + rest < K) return false;
  // sumがKを超えてしまったら,遷移を打ち切る
  if (sum > K) return false; 

  // 0～N-1まで見終わったら,今の総和がKかどうかを判定する.
  if (i == N) return sum == K;
  // 選ぶ,選ばない場合を試してみて,Kになる状態が発見できればtrue返す
  if (dfs(i + 1, sum, rest - a[i])) return true;
  if (dfs(i + 1, sum + a[i], rest - a[i])) return true;

  // 選んでも選ばなくても,Kとなる状態が発見できなかった
  return false;
}

int main()
{
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    sum += x;
    a.push_back(x);
  }
  cin >> K;

  if (dfs(0, 0, sum)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
