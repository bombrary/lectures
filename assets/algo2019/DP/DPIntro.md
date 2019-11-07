
# Introduction to Dynamic Programming

---

## What is Dynamic Programming(DP)?

- The tequnique to reduce time complexity of brute-forth search.
- **Memoization** is important (not memolization!).

---

4 processes are important.

The array for memoization of states is called DP table.
We have to make the formula of transition of state with DP table.
It is almost the same as recurrence relation in mathematics.

1. Definiton of state with DP table
2. Initiation of DP table
3. Transition of DP table
4. Getting answer from DP table.

---

- What is good definition of state depends on problems.
- There are many DP tequniques
  - bit DP, digit DP, inline DP, Convex Hull Trick, interal DP, ... 
  - That confuces many beginners.
- I will introduce famous DP problems in this slide.

---

## Outline

1. My promise in this slide
2. Subset sum problem
3. Knapsack problem
4. LCS, LIS
5. bit DP

---

## My promise1/2

I write
- $\text{definition}$ as $\text{Def.}$
- $\text{initiation}$ as $\text{Init.}$
- $\text{transition}$ as $\text{Trans.}$
- $\text{answer}$ as $\text{Ans.}$

- $\underline{A = A \circ B}$ as $\underline{A = src \circ B}$ (for all operator $\circ$)
- $\underline{A = f(A, B)}$ as $\underline{A = f(src, B)}$ (for all mapping $f$)

---

### Example

I am tired to write:
$dp[i + 1][j + a[i]] = \min(dp[i + 1][j + a[i]], dp[i][j])$

So, I will write:
$dp[i + 1][j + a[i]] = \min(src, dp[i][j])$


---

## My promise2/2

- At least in japanese community of competitive programming, it seems that there is two concept of DP:
  - DP with collection (貰うDP)
  - DP with distribution (配るDP)

  (I don't know what foreign community call them.)
  Both ability to solve a problem are the same.
- In this slide, I unified the method to DP with distribution.
[This page](https://qiita.com/drken/items/a5e6fe22863b7992efdb) is based on DP with collection.

---

## Addition: curse of dimention

You should not take "the curse of dimention on DP".
e.g.
"I understand the two-dimentioned DP such as knapsack problem, but I can't understand more than tree-dimentioned DP!"

**Why?** I think you should understand more than three-dimentioned DP if you really understand two-dimentioned DP.
Relation of DP and dimention does not make difference.
What's important is the fact that dimention indicates the number of condition to describe the state.

---

## Reuse of dp table

I'm sorry, I will write it later.

---

## Reconstruction from DP

I'm sorry, I will write it later.

---

## Hint: time complexitye of DP 

### "I want to decrease a time complexity on DP!"

- You may reconsider the definition of DP.
- You may reconsider the transition of DP
  - decrease of the number of transition
    - only the nearest state
    - using binary_search
    - using segment-tree
  - calculation for transition in advance
    - partial sum

---

## Exercises

- yukicoder No.458: 異なる素数の和
  You can login by Twitter, or create yukicoder acount.
  Statement:
  If you write $N$ as $p_1+p_2+...+p_n$ ($p_i$: prime number and they are mutually distinct), print maximum of $n$.
 
