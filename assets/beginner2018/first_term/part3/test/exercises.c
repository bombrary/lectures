#include <stdio.h>

int main(void) {
    int N;
    int i;
    char S[110];

    scanf("%d", &N);
    scanf("%s", S);
    for(i = 0; i < N; i++) {
        printf("%s\n", S);
    }

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int N;
    int i;

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        printf("%d", i % 2);
    }

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int N;
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if(i % 2 == 1) printf("1");
        else printf("0");
    }
    printf("\n");

    return 0;
}

/*---------------------------------*/
#include <stdio.h>

int main(void) {
	int n;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	char S[110];
	int cnt = 0;
	int i;

    scanf("%s", S);
    for(i = 0; S[i] != '\0'; i++) {
		if(S[i] == 'o') cnt++;
    }
	printf("%d\n", cnt);


    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
	int a, n;
	int i;
	int ans = 1;

	scanf("%d %d", &a, &n);
	for(i = 0; i < n; i++) ans *= a;
	printf("%d\n", ans);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    int N;
    int i;
    int min = 1000;

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        int T;
        scanf("%d", &T);
        if(min > T) min = T;
    }
    printf("%d\n", min);

    return 0;
}
    
/*---------------------------------*/
#include <stdio.h>
 
int main(void) {
	int N;
	int A[210];
	int i;
	int cnt = 0;
	int flag = 0;
 
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
 
	while(flag != 1) {
		for(i = 0; i < N; i++) {
			if(A[i] % 2 == 0) {
				A[i] /= 2;
			} else {
				flag = 1;
				break;
			}
		}
		if(flag == 0) cnt++;
	}
 
	printf("%d\n", cnt);
 
	return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
  int a, b, c;
  
  scanf("%d %d", &a, &b);
  c = 0;
  while((a + c) % b) c++;
  
  printf("%d\n", c);
  
  return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
  int a, b, c;
  
  scanf("%d %d", &a, &b);
  printf("%d\n", b * ((a + b - 1) / b) - a);
  
  return 0;
}
/*---------------------------------*/
#include <stdio.h>
 
int main(void) {
  int N, K;
  int ans;
  int i;
  
  scanf("%d %d", &N, &K);
  ans = K;
  K--;
  
  for(i = 0; i < N - 1; i++)
    ans *= K;
  
  printf("%d\n", ans);
  
  return 0;
}
/*---------------------------------*/
if (a % b > 0) m = a / b + 1
printf("%d\n", b*m - a);
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
