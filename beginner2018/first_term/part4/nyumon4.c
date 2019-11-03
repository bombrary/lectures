(int)値 int double char
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int x, y, z;

    printf("%d %d %d\n", x, y, z);
    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    double x;
    int y;

    scanf("%lf", x);
    y = (int)x;
    printf("x: %f\n", x);
    printf("y: %d\n", y);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    double x;
    int y;

    scanf("%lf", x);
    y = x;
    printf("x: %f\n", x);
    printf("y: %d\n", y);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int a, b;
    double c1, c2;

    scanf("%d %d", a, b);
    c1 = (a + b) / 2;
    c2 = (a + b) / 2.0;
    printf("%f\n%f\n", c1, c2);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	double x;
	int y;

	scanf("%lf", &x);
	y = (int)(x + 0.5);
	printf("%d\n", y);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	double x;

	scanf("%lf", &x);
	if(x - (int)x > 0) printf("%d\n", (int)x + 1);
	else printf("%d\n", (int)x);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>
#include <math.h>

int main(void) {
	double x;

	scanf("%lf", &x);
	printf("%d\n", (int)ceil(x));

    return 0;
}
/*---------------------------------*/
ceil(a / b);
if(a % b > 0) c = a / b + 1;
else c = a / b;
c = (a + b - 1) / b; 
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("Method1: ");
	if(a % b > 0) printf("%d\n", a / b + 1);
	else printf("%d\n", a / b);

	printf("Method2: ");
	printf("%d\n", (a + b - 1) / b);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	int hist[10] = {};
	int N;
	int i;

	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		int H;
		scanf("%d", &H);
		hist[(H - 100) / 10]++;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d-%d: ", 100 + 10*i, 109 + 10*i);
		for(int j = 0; j < hist[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

    return 0;
}

/*---------------------------------*/
#include <stdio.h>

int main(void) {
	int a, b;
	
	scanf("%d %d", &a, &b);
	if(a % b == 0) printf("0\n");
	else printf("%d\n", b - a%b);

	return 0;
}
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/