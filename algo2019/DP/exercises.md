## Part6

- [yukicoder No.458 異なる整数の和](https://yukicoder.me/problems/no/458)

---

## Part7

- [AOJ 2254 Fastest Route](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2254&lang=jp)
- [ABC 006 D トランプ挿入ソート](https://atcoder.jp/contests/abc006/tasks/abc006_4)

English statement is next page.

---

### AOJ 2254 Fastest Route

You've found the game, and want to clear it.

There are $N$ stage in this game. You can clear them in arbitary order.
If you clear the $i$-th stage, you get the $i$-th equipment.
Once you get, you can use this in any stage many times.

For $i$-th stage numbered $1, 2, \ldots , N$,
- If you don't use any equipments, you spent times $t_{i0}$ to clear this stage.
- If you use $j$-th equipments, you spent times $t_{ij}$ to clear this stage.

Please minimize the time to clear all stage.

---

#### Supplement of AOJ

- The input of this problem is different from AtCoder's.
- Templete is here.

```cpp

int solve(int N)
{
  // You write a program to solve here.
}

int main()
{
  int N;
  cin >> N
  while (cin >> N, N) {
    cout << solve(N) << endl;
  }
  return 0;
}

```

---

### ABC 006 D トランプ挿入ソート

There are $N$ cards, numbered $1, 2, \ldots, N$.
You can perform this operation on cards:

- **Operation**: Remove a card, and insert it in arbitary position.

Minimize the number of operation to make cards in ascending order.

