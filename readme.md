# Вычисление чисел Фибоначчи на матрицах

Ряд можно порождать матрицей $2 \times 2$. Назовём эту матрицу порождающей. Обозначим её $B$. Любые элементы любой степени $B$ являются числами Фибоначчи. Я подобрал $B$. Я так и не смог математически её вывести.

$$
B = \begin{pmatrix}
0 & 1 \\
1 & 1
\end{pmatrix}
$$

Числа Фибоначчи нумеруются с $0$. $F_0 = 0, F_1 = 1$.
Для поиска $N$-ого, $N \ge 1$ числа Фибоначчи понадобится возвести матрицу $B$ в степень $N-1$.

$$
F_n = (B^{N-1})_{2, 2}
$$
