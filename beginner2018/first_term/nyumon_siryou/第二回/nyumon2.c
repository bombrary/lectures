#include <stdio.h>
 
int main() {
  int X, A, B;
  
  scanf("%d %d %d", &X, &A, &B);
 
  if(B<=A) printf("delicious\n");
  else if(A<B && B<=X+A) printf("safe\n");
  else printf("dangerous\n");
  
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
