#include <stdio.h>
#define マクロ名 値
#define PI 3.14
#define INF 1000000000
#define HELLO printf("Hello!\n");

#define ADD(a, b) a + b
#define SHOW(str) printf(str)
/*-----------------------------------*/
#include <stdio.h>

#define PI 3.14
#define INF 1000000000
#define HELLO printf("Hello!\n")
#define MAX_N 1000

int main(void)
{
    int a[MAX_N];
    double d;

    d = PI;
    a[0] = INF;

    HELLO;
    printf("%d %f", a[0], d);

    return 0;
}
/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
    int a[1000];
    double d;

    d = 3.14;
    a[0] = 1000000000;

    printf("Hello!\n");
    printf("%d %f", a[0], d);

    return 0;
}
/*-----------------------------------*/
#include <stdio.h>

#define MUL(a, b) ((a) * (b))
#define SHOW(str) printf(str)

int main(void)
{
    printf("%d\n", MUL(-3, 2));
    SHOW("Hello\n");
    return 0;
}
/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
    printf("%d\n", ((-3) * (2)));
    printf("Hello\n");
    return 0;
}
/*-----------------------------------*/
sizeof(型/変数/配列);
/*-----------------------------------*/
#include <stdio.h>

#define MAX_N 1000

int main(void)
{
    int a[MAX_N];

    printf("int: %d\n", sizeof(int));
    printf("char: %d\n", sizeof(char));
    printf("long long: %d\n\n", sizeof(long long));

    printf("a[0]: %d\n", sizeof(a[0]));
    printf("a: %d\n", sizeof(a));
    printf("a_size: %d\n", sizeof(a) / sizeof(a[0]));

    return 0;
}
/*-----------------------------------*/
int getArraySize(int *a)
{
    return sizeof(a) / sizeof(a[0]);
}
/*-----------------------------------*/
printf("%d", a = 5);
/* nは配列の要素数、kは適当な数 */
if(a[i] > k && i < n) ...


/* nは配列の要素数、kは適当な数 */
/* checkは配列に対して何かの走査をする関数 */
if(i < n && check() == 1 ) ...

/*-----------------------------------*/
a = 0, b = 0, a++, b += a, printf("%d %d\n", a, b);
/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
	int i;

	for(int i = 0; i < 100; i++) {
		if(i <= 50) printf("%d\n", 50 * i);
		else printf("%d\n", -(i - 50)*(i - 50) + 2500);
	}

	return 0;
}
/*-----------------------------------*/
char *str = "Hello";
char str[16] = "Hello, World!";
/*-----------------------------------*/
'H' 'e' 'l' 'l' 'o' ',' ' ' 'W' 'o' 'r' 'l' 'd' '!' '\0'
0 0
/*-----------------------------------*/
{
    なんか処理
}
if(条件)
    なんか処理;
if(条件) なんか処理;
/*-----------------------------------*/
while (条件)
if (条件) { ... }
int a, b, c, d, e, f;
if(条件) { 
    ...
} else {

}
/*-----------------------------------*/
x = a + b;
y = 2 * x;
c >= 6 - d
A*B + B*C + C*A
/*-----------------------------------*/
if(条件) {

}

/*-----------------------------------*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;

	for(i = 0; i < 1000; i++) {
		printf("%f,%f\n", i / 10.0, sqrt(i / 10.0));
	}

	return 0;
}
/*-----------------------------------*/
double d;
for(d = 0; d < 100; d += 0.1) {
    ...
}
/*-----------------------------------*/
l++; r--;
while(i < n) { i++; j++; a[i] = i + j; }