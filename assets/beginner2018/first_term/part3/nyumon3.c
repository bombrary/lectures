#include<stdio.h>
int main(void){
int a;
scanf("%d", &a);
if(a%7==0) {
printf("7 divides %d.\n", a);
}else{
printf("7 doesn't devide %d.\n", a);
}
return 0;
}
/*---------------------------------*/
#include<stdio.h>
int main(void){
    int a;
    scanf("%d",&a);
    if(a%7==0) {
        printf("7 divides %d.\n",a);
    }else{
        printf("7 doesn't devide %d.\n",a);
    }
    return 0;
}
/*---------------------------------*/
#include<stdio.h>

int main(void){
    int a;

    scanf("%d",&a);
    if(a%7==0) {
        printf("7 divides %d.\n",a);
    }else{
        printf("7 doesn't devide %d.\n",a);
    }

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
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
2 * (A*B + B*C + C*A)   /* A, B, Cの間の*の間にスペースを入れていない */
-x
break;
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int x;

    scanf("%d", &x);
    if(x < 0) printf("%d\n", -x);
    else printf("%d\n", x);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>
#include <math.h>

int main(void) {
    int x;

    scanf("%d", &x);
    printf("%d\n", abs(x));

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

/* Helloと10回表示する(while版) */
#include <stdio.h>

int main() {
    int i;

    i = 0;
    do {
        printf("Hello.\n");
        i++;
    } while (i < 10);
}
/*---------------------------------*/

/* Hello, World[回数-1]をN回表示する */
#include <stdio.h>

int main() {
    int i, N;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        printf("Hello%d\n", i);
    }

    return 0;
}
/*---------------------------------*/
for (i = 0; i < N; i++) {
        printf("Hello%d\n", i);
}

i = 0;
while (i < N) {
    printf("Hello%d\n", i);
    i++;
}
/*---------------------------------*/

#include <stdio.h>

int main(void) {
    int i, j;

    for(i = 1; i <= 9; i++) {
        for(j = 1; j <= 9; j++) {
            printf("%3d", i * j);
        }
        printf("\n");
    }
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int i, N;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if (i == 7) break;
        printf("Hello%d\n", i);
    }

    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int i, N;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if(i % 3 == 0) continue;
        printf("Hello%d\n", i);
    }

    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main(void) {
    printf("%3d\n%3d\n\n", 64, 256);
    printf("%04d\n%04d\n", 64, 256);
    
    return 0;
}
/*---------------------------------*/
int a[5] = {2, 4};
int a[5] = {2, 4, 0, 0, 0};
int a[100] = {0};
/*---------------------------------*/
for(なんか書いてある) {
    for(なんか書いてある) {
        なんか処理...
        break;
        なんか処理...
    }
}
{
    int a; 

    ...
    なんかいろいろ処理
    ...

   
}
#include <stdio.h>

int a;

int main(void) {
    int b;

    なんか処理

    if(なんか書く) {
        int c;
        なんか処理
    }

    なんか処理

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