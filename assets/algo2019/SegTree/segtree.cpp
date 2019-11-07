#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template<typename T>
struct SegTree {
  int n;
  const T ID;
  vector<T> node;
  // 配列のサイズ, 単位元
  SegTree(int sz, T _ID): ID(_ID) {
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2*n - 1, ID);
  }
  T operate(T a, T b) {
    // 二項演算子をここに書く
    return a + b;
  }
  T update(T target, T val) {
    // set関数の時に呼び出される更新処理をここに書く
    // 例: 加算したいとき: return target + val;
    // 例: 値を書き換えたいとき: return val;
    return target + val;
  }
  T get(int tl, int tr, int k, int l, int r) {
    if (r <= tl || tr <= l) return ID;
    else if (tl <= l && r <= tr) return node[k];
    else {
      T nl = get(tl, tr, 2*k+1, l, (l+r)/2);
      T nr = get(tl, tr, 2*k+2, (l+r)/2, r);
      return operate(nl, nr);
    }
  }
  T get(int l, int r) {
    return get(l, r, 0, 0, n);
  }
  void set(int i, int x) {
    i += n - 1;
    node[i] = update(node[i], x);
    while (i) {
      i = (i - 1) / 2;
      node[i] = operate(node[2*i + 1], node[2*i + 2]);
    }
  }
};

void verifyRSQ()
{
  int n, q;
  cin >> n >> q;
  SegTree<int> st(n, 0);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) {
      x--;
      st.set(x, y);
    } else {
      x--, y--;
      cout << st.get(x, y + 1) << endl;
    }
  }
}

void verifyRMQ()
{
  // Verify AOJ DSL_2_A - RMQ
  int n, q;
  cin >> n >> q;
  SegTree<int> st(n, INT_MAX);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) {
      st.set(x, y);
    } else {
      cout << st.get(x, y + 1) << endl;
    }
  }
}
int main()
{
  verifyRSQ();
  return 0;
}
