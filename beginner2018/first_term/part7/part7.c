#include <stdio.h>

int sum1toN(int n) {
    if(n == 1) return 1;
    return sum1toN(n - 1) + n;
}

int main(void)
{
    printf("%d\n", sum1toN(N));
    return 0;
}
/* --------------------------------------------- */
#include <stdio.h>

int kaijo(int n) {
    if(n == 1) return 1;
    return kaijo(n - 1) * n;
}

int main(void)
{
    printf("%d\n", kaijo(7));
    return 0;
}
/* --------------------------------------------- */
#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b);)
}
/* --------------------------------------------- */
#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
}
/* --------------------------------------------- */
#include <stdio.h>

int memo[40];

int fib(int n)
{
    if(memo[n] != 0) return memo[n];
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    memo[n] = fib(n - 2) + fib(n - 1);
    return memo[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}

/* --------------------------------------------- */

sum1toN(10);

return sum1toN(9) + 10;


return sum1toN(8) + 9;


return sum1toN(7) + 8;


return sum1toN(6) + 7;


return sum1toN(5) + 6;


return sum1toN(4) + 5;


return sum1toN(3) + 4;


return sum1toN(2) + 3;


return sum1toN(1) + 2;


return 1;

55

return 45 + 10;


return 36 + 9;


return 28 + 8;


return 21 + 7;


return 15 + 6;


return 10 + 5;


return 6 + 4;


return 3 + 3;


return 1 + 2;

/* --------------------------------------------- */
int sum1toN(int N) {
    int i;
    int ret = 0;
    for(i = 1; i <= N; i++) ret += i;
    return ret;
}
/* --------------------------------------------- */
int kaijo(int n) {
    int i;
    int ret = 1;
    for(i = 1; i <= N; i++) ret *= i;
    return ret;
}
/* --------------------------------------------- */
int fib(int n) {
    int i;
    int f[40];
    f[0] = 0;
    f[1] = 1;
    for(i = 2; i < 40; i++) f[i] = f[i - 2] + f[i - 1];
    return f[n];
}
/* --------------------------------------------- */
struct 構造体名 {
    メンバ型 メンバ変数名;
    メンバ型 メンバ変数名;
    メンバ型 メンバ変数名;
    ...
}
/* --------------------------------------------- */
struct Human {
    char name[1000];
    int x;
    int y;
}
/* --------------------------------------------- */
struct 構造体名 変数名;
変数名.メンバ変数名;
struct Human a;
/* --------------------------------------------- */
scanf("%s %d %d", a.name, &a.x, &a.y);
double d = sqrt(a.x*a.x+a.y*a.y);
/* --------------------------------------------- */
typedef 型名 新しい型名;
typedef long long ll;
typedef struct Human Hm;
ll x;
Hm a;
typedef struct Human {
    char name[1000];
    int x;
    int y;
} Hm;
/* --------------------------------------------- */
#include <stdio.h>
#include <math.h>

struct Human {
    char name[1000];
    int x;
    int y;
};

int main(void)
{
    struct Human a;
    double dist;
    scanf("%s%d%d", a.name, &a.x, &a.y);
    
    dist = sqrt(a.x*a.x + a.y*a.y);
    printf("%s: %f\n", a.name, dist);

    return 0;
}
/* --------------------------------------------- */
#include <stdio.h>
#include <math.h>

typedef struct Human {
    char name[1000];
    int x;
    int y;
} Hm;

int main(void)
{
    Hm a;
    double dist;
    scanf("%s%d%d", a.name, &a.x, &a.y);
    
    dist = sqrt(a.x*a.x + a.y*a.y);
    printf("%s: %f\n", a.name, dist);

    return 0;
}
/* --------------------------------------------- */
#include <stdio.h>

int main(void) {
    int a, b;
    while(1) {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0) break;
        printf("%d\n", a * b);
    }
    return 0;
}
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */
/* --------------------------------------------- */

