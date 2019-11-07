#include <stdio.h>

int main() {
  char s[10];
  
  scanf("%s", s);
  if(s[0] == '1' && s[1] == '1' && s[2] == '1')
    printf("3\n");
  else if(s[0] == '0' && s[1] == '0' && s[2] == '0')
    printf("0\n");
  else if((s[0] == '1' && s[1] == '0' && s[2] == '0')
        ||(s[0] == '0' && s[1] == '1' && s[2] == '0')
        ||(s[0] == '0' && s[1] == '0' && s[2] == '1'))
    printf("1\n");
  else
    printf("2\n");
  
  return 0;
}
   

/* ここは日本。私たちの、母なる国。 */
#include <stdio.h>

int main(void) {
  int N, M;
  int a[55][55], b[55][55];
  int i, j;
  
  scanf("%d %d", &N, &M);
  for(i = 0; i < N; i++)
    scanf("%s", a[i]);
  for(i = 0; i < M; i++)
    scanf("%s", b[i]);
  
  for(i = 0; i < (N-M+1); i++) {
    for(j = 0; j < (N-M+1); j++) {
      int k,l;
      int flag = 0;
      /*for(k = 0; k < M; k++) {
        for(l = 0; l < M; l++) {
          if(a[k + i][l + j] != b[k][l]) {
            flag = 1;
            break;
          }
        }
        if(flag == 1) break;
      }
      if(flag == 0) {
        printf("Yes\n");
        return 0;
      }*/
    }
  }
  printf("No\n");
  return 0;
}
      
/*---------------------------------*/
A == B;
A != B;
A < B;
A <= B;
A > B;
A >= B;
〇 && △
〇 || △
!〇 
/*---------------------------------*/
/* 関係演算子・条件演算子 */
#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("a == b                   : %d\n", a == b);
    printf("a > b                    : %d\n", a > b);
    printf("a + b <= 10              : %d\n", a + b <= 10);
    printf("a %% 3 == 0 || b %% 3 == 0 : %d\n", a % 3 == 0 || b % 3 == 0);
    printf("a %% 4 != 0 && b %% 4 != 0 : %d\n", a % 4 != 0 && b % 4 != 0);

    return 0;
}

/*---------------------------------*/
if(1) なんか処理
else なんか処理

if(0) なんか処理
else なんか処理

if(x <= y) なんか処理
else なんか処理

if(条件1) {
    中身A
    中身B
    中身C
    ...
}

/*---------------------------------*/

/* if文 入力した値の大小比較 */
#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("%d is equal to %d.\n", a, b);
    } else if (a > b) {
        printf("%d is bigger than %d.\n", a, b);
    } else {
        printf("%d is smaller than %d.\n", a, b);
    }

    return 0;
}

/*---------------------------------*/

/* 入力した値aについて、aが7の倍数であるかを調べる */
#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);
    if (a % 7 == 0) {
        printf("7 divides %d.\n", a);
    } else {
        printf("7 doesn't devide %d.\n", a);
    }

    return 0;
}

/*---------------------------------*/
switch (0) {
    case 0:
        中身
        break;
    
    ...

    default:
        中身
}
#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);
    switch (a % 3) {
        case 0:
            printf("X\n");
            break;
        case 1:
            printf("Y\n");
            break;
        case 2:
            printf("Z\n");
            break;
        default: 
            printf("N\n");
    }

    return 0;
}


/*---------------------------------*/

/* Helloと10回表示する(while版) */
#include <stdio.h>

int main() {
    int i;

    i = 0;
    while (i < 10) {
        printf("Hello.\n");
        i++;
    }
}

/*---------------------------------*/

/* Hello, World[回数-1]をN回表示する */
#include <stdio.h>

int main() {
    int i, N;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        printf("Hello, World%d\n", i);
    }
}

/*---------------------------------*/

/* 10個の入力値から最大値・最小値を探して表示 */
#include <stdio.h>

int main() {
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

/* 入力されたN個の数値の総和を求める */
#include <stdio.h>

int main() {
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

/*(要検証)各桁の和を足した値を表示*/
#include <stdio.h>

int main() {
    int N, sum = 0;
    
    scanf("%d", &N);

    while (N != 0) {
        sum += N % 10;
        N /= 10;
    }
    printf("%d\n", sum);

    return 0;
}

/*---------------------------------*/

/*文字数を数える*/
#include <stdio.h>

int main() {
    char str[1000];
    int N;

    scanf("%s", str);
    for (N = 0; str[N] != '\0'; N++) ;
    printf("%d\n", N);

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
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
