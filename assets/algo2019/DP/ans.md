[ yukicoder No. 458 異なる素数の和 ]
20000までの素数を列挙して配列pに格納しておく。
その後部分和問題っぽいDP式を立てる。
$$
\text{Def. }dp[i][j] := i個目までみたときにjを作るための最大個数(作れなければ-1)
$$
$$
\begin{aligned}
&\text{Init.}\\
&&dp[0][0] &= 0\\
&&\text{others} &= -1
\end{aligned}
$$
$$
\begin{aligned}
&\text{Trans.}\\
&&dp[i + 1][j] &= \max(src, dp[i][j])\\
&&dp[i + 1][j + p[i]] &= \max(src, dp[i][j] + 1)
\end{aligned}
$$

$$
Ans: dp[p\text{.size()}][N]
$$