/*幅w, 高さhの長方形を描画する*/
#include <stdio.h>

int main(void) {
	int w, h;
	int i, j;

	scanf("%d %d", &w, &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*---------------------------------*/
/*幅w, 高さhの長方形を描画する(2)*/
#include <stdio.h>

int main(void) {
	int w, h;
	int i, j;

	scanf("%d %d", &w, &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if((i + j) % 2 == 1) printf("+");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*---------------------------------*/
/*高さhの直角二等辺三角形を描画する*/
#include <stdio.h>

int main(void) {
	int h;
	int i, j;

	scanf("%d", &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/*---------------------------------*/
/*高さhの直角二等辺三角形を描画する(2)*/
#include <stdio.h>

int main(void) {
	int h;
	int i, j;

	scanf("%d", &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < h - i - 1; j++) {
			printf(" ");
		}
		for(j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/*---------------------------------*/

/*入力された整数値の最大値、再小値を求める*/
#include <stdio.h>

int main(void) {
    int a[10];
    int i;
    int max = -1, min = 10000000;

    printf("input: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 10; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if(min > a[i]) {
            min = a[i];
        }
    }
    printf("max: %d, min: %d\n", max, min);
    
    return 0;
}

/*---------------------------------*/

/*入力されたn個の整数の総和を求める*/
#include <stdio.h>

int main(void) {
    int a[1000];
    int N, i, sum = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < N; i++) {
        sum += a[i];
    }

    printf("%d\n", sum);

    return 0;
}

/*---------------------------------*/

/*入力された文字列の文字数を数える*/
#include <stdio.h>

int main(void) {
	char str[100];
	int N;

	scanf("%s", str);
	for (N = 0; str[N] != '\0'; N++) {
		printf("%c\n", str[N]);
	}
	printf("%d\n", N);

	return 0;
}

/*---------------------------------*/

/*入力された文字列の文字数を数える(2)*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int N;

    scanf("%s", str);
    N = strlen(str);
    printf("%d\n", N);

    return 0;
}
/*---------------------------------*/

/*各桁の和を求める*/
#include <stdio.h>

int main(void) {
	int N;
	int sum = 0;

	scanf("%d", &N);
	while(N) {
		sum += N % 10;
		N /= 10;
	}
	printf("%d\n", sum);

	return 0;
}

125 -> 5
12 -> 2
1 -> 1

/*---------------------------------*/

/*掛け算九九表について、70以上の数が出てきた時点で表示を切りやめる。*/
#include <stdio.h>

int main(void) {
	int i, j;
	int flag = 0;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			int p = i * j;
			if (p >= 70) {
				flag = 1;
				break;
			} else {
				printf("%3d", i * j);
			}
		}
		printf("\n");
		if(flag) break;
	}
	
	return 0;
}
/*---------------------------------*/

/*無限ループって怖くね？*/
#include <stdio.h>

int main(void) {
	
	while(1) {
		printf("HAHAHA!!!\n");
	}

	return 0;
}

/*---------------------------------*/

/*while(1)をあえて指定し、if文で途中break*/
#include <stdio.h>

int main(void) {
	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);
		if(a < 0 || b < 0) break;

		printf("%d\n", a + b);
	}

	return 0;
}


/*---------------------------------*/
			

/*---------------------------------*/

/* 入力されたN(1≦N≦1000)個の自然数のうち最大値を求める */
#include <stdio.h>

int main(void) {
    int a[1000];
    int i;
    int max = -1;

	/* 入力部分 */
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

	/* 最大値を求める部分 */
    for (i = 0; i < N; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

	/* 出力部分 */
    printf("max: %d", max);
    
    return 0;
}

/*---------------------------------*/
/*各桁を改行区切りで出力*/
#include <stdio.h>

int main(void) {
	int N;

	/* 入力部分 */
	scanf("%d", &N);
	/* 各桁を取り出して出力する部分 */
	while(N) {
		printf("%d\n", N % 10);
		N /= 10;
	}

	return 0;
}
/*---------------------------------*/
/*入力されたn個の整数の総和を求める*/
#include <stdio.h>

int main(void) {
    int a[1000];
    int N, i, sum = 0;

	/* 入力部分 */
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
	/* 総和を求める部分　*/
    for (i = 0; i < N; i++) {
        sum += a[i];
    }
	/* 出力する部分 */
    printf("%d\n", sum);

    return 0;
}
/*---------------------------------*/
/*---------------------------------*/