<link rel="stylesheet" href="style.css">

# Segment Tree

---

## What is segment tree?

- The data structure for query of interval.
- It allows us to process data in time complexity $O(\log n)$, for an array.

1. Do something to a[i].
2. Get something from interval $[l,r)$;
  $a[l],a[l+1],\ldots ,a[r-2],a[r-1]$.

---

## Example

### Range Minimum Query

Process those query many times.
1. update(i,x): a[i] &larr; x.
2. getmin(l,r): 
 $\min(a[l],a[l+1],\ldots ,a[r-2],a[r-1])$.

---

### Range Sum Query

Process those query many times.
1. update(i,x): a[i] &larr; x.
2. getsum(l,r): get the value of
 $a[l]+a[l+1]+ \cdots +a[r-2]+a[r-1]$.

---

###  Both have a thing in common

- Segment Tree has elements and operator.

  e.g
- RMQ: integer and  operator of min.
- RSQ: integer and operator of add.

---

## What kind of elem and op can be used as a Segment Tree?

- Elements and operations satisfies monoid.

---

### What is monoid?

The algebric structure which has **associativity** and the existence of **identity element**.

Associativity: 
$\hspace{2em} (a \cdot b) \cdot c = a \cdot (b \cdot c)$
Identity element:
$\hspace{2em} e \cdot a = a \cdot e = a$

Source: [Wikipedia](https://en.wikipedia.org/wiki/Monoid)

---

### Are segment tree on RMQ and RSQ really satisfies monoid ?

RMQ: Identity element is $\text{INF}$.
- $\min(\min(a,b),c) = \min(a,\min(b,c))$
- $\min(\text{INF},a)=\min(a,\text{INF})=a$

RSQ: Identity element is $0$.
- $(a+b)+c=a+(b+c)$
- $0+a=a+0=a$

---

## How to process queries by segment tree?

- Segment tree is a binary tree.
- Parent nodes have their child nodes' information.

![w:650px center](img/binary_tree2.svg)

---

### Image of interval.

To think interval overlapping, we represent segment tree as this image.
Here, node[0] is a root of the tree, and the children is node[1] and node[2], and so on.

![w:700px center](img/binary_tree_interval.png)

---

### Example: RMQ

- Plane data are leaves in segment tree.
- Parent nodes have minimum of their child nodes.

![w:900px center](img/RMQ_example.png)

---

### Example: RSQ

- Plane data are leaves in segment tree.
- Parent nodes have sum of their child nodes.

![w:900px center](img/RSQ_example.png)

---

### Supplement: How to construct binary tree. 

By use of an array.

- There are $2^d$ nodes in depth $d$
- If the size of an array is $n$, the whole size of array is $2n-1$.
  - The raw data of array is node[n-1] to node[2n-2].

---

### Supplement: How to use binary tree. 

- Access to child of $\text{node}[k]$: $\text{node}[2k+1],\text{node}[2k+2]$

![w:800px center](img/parent_to_child_idx.svg)

---

- Access to patent of $\text{node}[k]$: $\text{node}[(k-1)/2]$

![w:800px center](img/child_to_parent_idx.svg)

---

# Case study: RMQ

---

- Initiation: fill the identity element
  Note thet the time complexity is $O(n)$

```cpp
#define INF 1100000000

int n;
vector<int> node;

void init(int sz) {
  n = 1;
  while (n < sz) n *= 2;
  node.resize(2*n - 1, INF);
}
```

---

- If you initiate by an array $a$:

```cpp
void init(int sz, vector<int>& a) {
  n = 1;
  while (n < sz) n *= 2;
  node.resize(2*n - 1, INF);

  for (int i = 0; i < a.size(); i++) {
    node[i+n-1] = a[i];
  }
  for (int i = n-2; i >= 0; i--) {
    node[i] = min(node[2*i + 1], node[2*i + 2]);
  }
}
```

---

- update(i, val):
  After updating a[i+n-1],
  update its child, and repeat this.

- I use bottom-up approach, but in some case, it is good to use top-down.

```cpp
void update(int i, int val) {
  i += n - 1;
  node[i] = val;
  while (i > 0) {
    // Go up to parant
    i = (i - 1) / 2;
    node[i] = min(node[2*i + 1], node[2*i + 2]);
  }
}
```

---

- getmin(l,r):
  Look up intetval \[l,r) from root, by top-down approach. 
 - Consider overlap of intetval

![w:800px center](img/RMQ_exapmle_getmin.svg)

---

#### Overlap

I will write target-l, target-r as $\textit{tl},\textit{tr}$

1. $r \le \textit{tl} \lor \textit{tr} \le l$ : outer.
2. $\textit{tl} \le l \land r \le \textit{tr}$ : inner.
3. $\text{Others}$ : partly overlapped.


![w:800px center](img/overlap.svg)

---

1. $r \le \textit{tl} \lor \textit{tr} \le l$
   return the identity element.
2. $\textit{tl} \le l \land r \le \textit{tr}$
   return the value of this interval.
3. $\text{Others}$
   split the interval to [l, mid) and [mid, r), and check overlap for each.

---

```cpp
// I want to get min of [tl, tr)
// Now I look at node[k], whose interval is [l, r)
int getmin(int tl, int tr, int k, int l, int r) {
  if (r <= tl || tr <= l) return INF;
  else if (tl <= l && r <= tr) return node[k];
  else {
    int mid = (l + r) / 2;
    int vl = getmin(tl, tr, 2*k + 1, l, mid);
    int vr = getmin(tl, tr, 2*k + 2, mid, r);
    return min(vl, vr);
  }
}
int getmin(int tl, int tr) {
  return getmin(tl, tr, 0, 0, n);
}
```

---

### Sum up to struct

```cpp
struct SegTree {
  int n;
  vector<int> node;
  SegTree(int sz) {
    n = 1;
    while (n < sz) n *= 2;
    node.resize(n, INF);
  }
  void update(int i, int val) {
    i += n - 1;
    node[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      node[i] = min(node[2*i + 1], node[2*i + 2]);
    }
  }
  void getmin(int tl, int tr, int k, int l, int r) {
    if (r <= tl || tr <= l) return INF;
    else (tl <= l && r <= tr) return node[k];
    else {
      int vl = getmin(tl, tr, 2*k + 1, l, (l + r) / 2);
      int vr = getmin(tl, tr, 2*k + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
}
```

---

### Abstruction

```cpp
template<typename T>
struct segtree {
  int n;
  const T ID;
  vector<T> node;
  segtree(int sz, T _ID): ID(_ID) {
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2*n - 1, ID);
  }
  T operate(T a, T b) {
    // Write the operation
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
```

---

```cpp
  T get(int l, int r) {
    return get(l, r, 0, 0, n);
  }
  void set(int i, int x) {
    i += n - 1;
    // Note = or +=.
    node[i] = x;
    while (i) {
      i = (i - 1) / 2;
      node[i] = operate(node[2*i + 1], node[2*i + 2]);
    }
  }
};
```

---

## How to use abstruct segment tree

```cpp
// RMQ
...
operate(int a, int b) {
  return min(a, b);
}
...
void set(int i, int x) {
  i += n - 1;
  // Note = or +=.
  node[i] = x;
  while (i) {
    i = (i - 1) / 2;
    node[i] = operate(node[2*i + 1], node[2*i + 2]);
  }
}
...

SegTree<int> st(N, INF);
```

---


```cpp
// RSQ
...
operate(int a, int b) {
  return a + b;
}
...
void set(int i, int x) {
  i += n - 1;
  // Note = or +=.
  node[i] += x;
  while (i) {
    i = (i - 1) / 2;
    node[i] = operate(node[2*i + 1], node[2*i + 2]);
  }
}
...

SegTree<int> st(N, 0);
```

---

# POJ 2991 Crane

---

## Statement

クレーンがあります。クレーンは、N個の線分が端点で接続されたものと考えます。
$i$番目の線分の長さは$L_i$です。はじめはすべての線分がまっすぐ接続され、上を向いています。

$C$個のクレーンを動かす命令が来ます。命令は以下の書式で書かれます。
- $S_i\ A_i$ : 線分$S_i$と線分$S_{i+1}$の間の角度を$A_i$度にする
角度は線分$S_i$から反時計回りに$S_{i+1}$を見たときの角度で、最初は180度です。

各命令に対し、それが終わったときのクレーンの先端の座標を出力してください。

---

## Constraint

- $1 \le N \le 10^4$
- $1 \le C \le 10^4$
- $1 \le L_i \le 10^2$
- $1 \le S_i \lt N
- $0 \le A_i \lt 359

---

## Example

![w:900px center](img/crane_example.svg)

---

![w:800px center](img/vector_review.svg)

---


![w:900px center](img/crane_data.png)

---

- 子のベクトル2つを用いて親のベクトルを作る

![w:800px center](img/crane_segtree.svg)

---

- 赤丸を軸に回転したいなら赤枠のベクトルを回転

![w:800px center](img/crane_segtree2.svg)

---

- 赤丸を軸に回転したいなら赤枠のベクトルを回転

![w:800px center](img/crane_segtree3.svg)

---

- 赤丸を軸に回転したいなら赤枠のベクトルを回転

![w:800px center](img/crane_segtree4.svg)

---

- update: 今見ている区間が軸よりRight &rArr; 回転角を更新
  区間の情報が欲しいのでTop Downがやりやすい

---

# 転倒数

---

数列$\{a_1, a_2, ... , a_n\}$がある。
次の操作を任意の回数行うことができる

- ある$i$を選び、$a_i$と$a_{i+1}$を入れ替える。ただし、$1 \le i \le n$である。
  入れ替えた数列を新たに$\{a_1, a_2, ... , a_n\}$とする。

このとき、数列を昇順に並び変えるために必要な操作回数の最小値を出力せよ

---

## Importance

![w:800px center](img/inversion_number.png)

---

## 余事象で見たほうがやりやすい

- $a_1, a_2, ... a_n$と順に見ていく。
- $\textit{num}[x] :=$ 今まで数$x$をいくつ見てきたか？ 
  初めは全部$0$で初期化

- $\textit{num}[0] + \textit{num}[1] + \cdots + \textit{num}[a_i]$ : 自分以下の数がいくつあるか

---

![w:800px center](img/inversion_number2.png)

---

というわけで
- $\textit{num}$の1点を決めて1加えたい
- $\textit{num}$のある区間の総和を求めたい

&rArr; これ正にRSQ。セグ木で解ける

---

## 実は

- RSQはオーバーキル
- もっと定数倍軽いデータ構造があります
  &rArr; BIT(Binary Indexed Tree)
- 資料作り間に合いませんでしたごめんなさい
