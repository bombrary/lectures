#include <stdio.h>

int main(void)
{
	int a;
	printf("%p", &a);
	
	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
	int a;
	double b;
	int *ip = &a;
	double *dp = &b;

	printf("ip-1: %p\n", ip - 1);
	printf("ip  : %p\n", ip);
	printf("ip+1: %p\n", ip + 1);

	printf("dp-1: %p\n", dp - 1);
	printf("dp  : %p\n", dp);
	printf("dp+1: %p\n", dp + 1);

	return 0;
}
ip-1: 0060FEA0
ip  : 0060FEA4
ip+1: 0060FEA8
dp-1: 0060FE90
dp  : 0060FE98
dp+1: 0060FEA0
/*-----------------------------------*/
#include <stdio.h>

struct Div {
	int q;
	int r;
};

struct Div divide(int a, int b)
{
	struct Div ret;
	ret.q = a / b;
	ret.r = a % b;
	return ret;
}

int main(void)
{
	int a = 16;
	int b = 3;
	struct Div x;

	x = divide(a, b);
	printf("%d %d\n", x.q, x.r);

	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

void divide(int a, int b, int *pq, int *pr) {
	*pq = a / b;
	*pr = a % b;
}

int main(void)
{
	int a = 16;
	int b = 3;
	int q, r;

	divide(a, b, &q, &r);
	printf("%d %d\n", q, r);

	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void)
{
	int a = 16;
	int b = 3;

	printf("after: %d %d\n", a, b);
	swap(&a, &b);
	printf("after: %d %d\n", a, b);

	return 0;
}

/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
	int x = 1;
	int y = 10;
	int tmp;

	printf("before... x: %d, y: %d\n", x, y);

	tmp = x;
	x = y;
	y = tmp;

	printf("after... x: %d, y: %d\n", x, y);

	return 0;
}
/*-----------------------------------*/

void swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
/*-----------------------------------*/
#include <stdio.h>

void showArray(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int x[5] = {2, 4, 6, 8, 10};
	showArray(x, 5);
	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

void showArray(int a[][3], int n)
{
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int x[4][3] = {{1, 2, 3}, {5, 6, 7}, {12, 11, 10}, {-1, -3, -7}};
	showArray(x, 4);
	return 0;
}

/*-----------------------------------*/
struct Human a;
struct Human *p;
p = &a;
(*p).x = 2;
(*p).y = 10;
/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
	int a[3] = {81, 24, 68};

	printf("a    : %p, &a[0]: %p\n",   a    , &a[0]);
	printf("a + 1: %p, &a[1]: %p\n",   a + 1, &a[1]);
	printf("a + 2: %p, &a[2]: %p\n\n", a + 2, &a[2]);

	printf("*a      : %d, a[0]: %d\n",   *a      , a[0]);
	printf("*(a + 1): %d, a[1]: %d\n",   *(a + 1), a[1]);
	printf("*(a + 2): %d, a[2]: %d\n\n", *(a + 2), a[2]);

	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

void changeWM(char *p)
{
	while(*p != '\0') {
		if(*p == 'W') *p = 'M';
		else if(*p == 'M') *p = 'W';
		else if(*p == 'w') *p = 'm';
		else if(*p == 'm') *p = 'w';
		p++;
	}
}

int main(void)
{
	char str[1000];

	scanf("%s", str);
	changeWM(str);
	printf("%s\n", str);

	return 0;
}

/*-----------------------------------*/

#include <stdio.h>

void changeWM(char p[])
{
	int i;

	for(i = 0; p[i] != '\0'; i++) {
		if(p[i] == 'W') p[i] = 'M';
		else if(p[i] == 'M') p[i] = 'W';
		else if(p[i] == 'w') p[i] = 'm';
		else if(p[i] == 'm') p[i] = 'w';
	}
}

int main(void)
{
	char str[1000];

	scanf("%s", str);
	changeWM(str);
	printf("%s\n", str);

	return 0;
}

/*-----------------------------------*/
scanf("%d", &x);
scanf("%d", str);
/*-----------------------------------*/
func(〇, □)

int func(int x, int y) {
	...
}
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
