/*--------------------------------------------*/
#include <stdio.h>

int main() {
    int A[4][3], B[3][5], C[4][5] = { 0 };
    int i, j, k;

    /*入力部分*/
    printf("A:\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    /*積を計算する部分*/
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 5; j++) {
            for(k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    /*出力部分*/
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*--------------------------------------------*/
int i, j;
char c[10][10];

/*5×5個の文字を入力(配列の要素は多めにとっている)*/
for(i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        scanf("%c", &c[i][j]);
    }
}
/*--------------------------------------------*/
int i, j;
char c[10][10];

/*5×5個の文字を入力(配列の要素は多めにとっている)*/
for(i = 0; i < 5; i++) {
    scanf("%s", c[i]);
}
/*--------------------------------------------*/
#include <stdio.h>

int main() {
	int i, j;
	char c[10][10];

	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			scanf("%c", c[i][j]);
		}
	}

	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*--------------------------------------------*/
char str[100];
char stra[5][100];
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
    int a[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 6, 9, 12}}
}

int main(void) {

    ...

}

func(9, 1);
/*--------------------------------------------*/
double func(int a, int b) {
    なんか色々処理
        
}
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
    int a[5][5];
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", a[i][j] + 2);
        }
        printf("\n");
    }

    return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", c * (2 * a + (c - 1) * b) / 2);

    return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int sumtousa(int a, int d, int n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

int main(void) {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", sumtousa(a, b, c));

    return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
    int n;
    int sum = 0;

    scanf("%d", &n);
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);

    return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int sumdigit(int num) {
    int sum = 0;
    while(num < 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d\n", sumdigit(n));

    return 0;
}
/*--------------------------------------------*/
void showdiv(double a, double b) {
    printf("a / b = %f", a / b);
    return;
}
/*--------------------------------------------*/
int suc(int num) {
    return num + 1;
}
/*--------------------------------------------*/
#include <stdio.h>

int suc(int num) {
    return num + 1;
}

int main(void) {
    int four;
    four = suc(suc(suc(suc(0))));
    printf("%d\n", four);
    return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
	int i, j;
	char c[10][10];

	for(i = 0; i < 5; i++) {
		scanf("%s", c[i]);
	}


	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*--------------------------------------------*/
#include <stdio.h>

int main(void) {
    int pan[3][3];
    int i, j;

    for(i = 0; i < 4; i++) {
       for(j = 0; j < 3; j++) {
           scanf("%d", &pan[i][j]);
        }
    }

    printf("Ichiro:\n")
    printf("Anpan: %d, Shokupan: %d, Currypan: %d\n", pan[0][0], pan[0][1], pan[0][2]);
    printf("Jiro:\n")
    printf("Anpan: %d, Shokupan: %d, Currypan: %d\n", pan[1][0], pan[1][1], pan[1][2]);
    printf("Saburo:\n")
    printf("Anpan: %d, Shokupan: %d, Currypan: %d\n", pan[2][0], pan[2][1], pan[2][2]);

    return 0;   
}
/*--------------------------------------------*/
#include <stdio.h>
 
int main() {
	int N;
	int i;
	int min;
 
	scanf("%d", &N)
	for(i = 0: i < N; i++) {
		int A;
		int cnt;
		scanf("%d", &A);
		while(A % 2 = 0) {
			cnt++;
			A /= 2;
		}
		if(min > cnt) min = cnt;
	}
 
	printf("%d\n", min);
 
	return 0;
}
/*--------------------------------------------*/
#include <stdio.h>
 
int main() {
	int N;
	int i;
	int min;
 
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		int A;
		int cnt;
		scanf("%d", &A);
		while(A % 2 == 0) {
			cnt++;
			A /= 2;
		}
		if(min > cnt) min = cnt;
	}
 
	printf("%d\n", min);
 
	return 0;
}

/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/
/*--------------------------------------------*/