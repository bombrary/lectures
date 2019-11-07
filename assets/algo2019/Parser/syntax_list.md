$$
\begin{align}
\langle \text{expr} \rangle &=
\langle \text{term} \rangle \mid
\langle \text{expr} \rangle+\langle \text{expr} \rangle\mid
\langle \text{expr} \rangle-\langle \text{expr} \rangle\\

\langle \text{term} \rangle &=
\langle \text{factor} \rangle \mid
\langle \text{term} \rangle+\langle \text{term} \rangle\mid
\langle \text{term} \rangle-\langle \text{term} \rangle\\

\langle \text{factor} \rangle &=
(\langle \text{expr} \rangle )\mid
\langle \text{number} \rangle\\

\langle \text{number} \rangle &=
0 \mid 1 \mid 2 \mid 3 \mid 4 \mid 5 \mid 6 \mid 7 \mid 8 \mid 9 \mid
\langle \text{number} \rangle \langle \text{number} \rangle
\end{align}
$$


$$
\begin{aligned}
\langle \text{expr} \rangle &= \langle \text{term} \rangle \pm \langle \text{term} \rangle \pm \cdots \\ 

\langle \text{expr} \rangle &= \langle \text{term} \rangle \times \div \langle \text{term} \rangle \pm \cdots \\

\langle \text{factor} \rangle &=
(\langle \text{expr} \rangle )\mid
\langle \text{number} \rangle\\

\langle \text{number} \rangle &=
0 \mid 1 \mid 2 \mid 3 \mid 4 \mid 5 \mid 6 \mid 7 \mid 8 \mid 9 \mid 10 \mid 11 \mid \cdots
\end{aligned}
$$

$$
\begin{aligned}
a\\
b
\end{aligned}
$$

$$
\begin{aligned}\langle\operatorname{expr}\rangle &=\langle\operatorname{term}\rangle \pm \langle\operatorname{term}\rangle \pm \cdots \\\langle\operatorname{term}\rangle &=\langle\operatorname{factor}\rangle \times\div \langle\operatorname{factor} \rangle \pm\cdots \\\langle\text {factor}\rangle &=(\langle\operatorname{expr}\rangle)|\langle\text{number}\rangle \\\langle\text {number}\rangle &= 0|1|2|3|4|5|6|7|8|9| 10|11| \cdots\end{aligned}
$$

$$
\begin{aligned}\langle\operatorname{expr}\rangle &=\langle\operatorname{term}\rangle|\langle\operatorname{expr}\rangle+\langle\operatorname{expr}\rangle|\langle\operatorname{expr}\rangle-\langle\operatorname{expr}\rangle \\\langle\operatorname{term}\rangle &=\langle\text {factor}\rangle|\langle\operatorname{term}\rangle\ast\langle\operatorname{term}\rangle|\langle\operatorname{term}\rangle/\langle\operatorname{term}\rangle \\\langle\text {factor}\rangle &=(\langle\operatorname{expr}\rangle) |\langle\text {number}\rangle \\\langle\text {number}\rangle &= 0|1| 2|3| 4|5| 6|7| 8|9|\langle\text {number}\rangle\langle\text {number}\rangle \end{aligned}
$$