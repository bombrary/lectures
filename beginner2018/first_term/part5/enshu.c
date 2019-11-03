#include <stdio.h>

int main(void)
{
    char c[10][10];
    int i;

    for(i = 0; i < 3; i++) scanf("%s", c[i]);
    printf("%c%c%c", c[0][0], c[1][1], c[2][2]);

    return 0;
}

/*-------------------------------------*/

#include <stdio.h>
 
int main() {
  char map[64][64];
  int i, j;
  int N;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
	scanf("%s", map[i]);
  }
  
  for(i = 0; i < N; i++) {
    for(j = N - 1; j >= 0; j--) {
      printf("%c", map[j][i]);
    }
    printf("\n");
  }
 
  return 0;
}

/*-------------------------------------*/

#include <stdio.h>
 
int sumOfDecimal(int n)
{
	int ret = 0;
	while(n != 0) { 
		ret += n % 10;
		n /= 10;
	}
 
	return ret;
}
 
int main(void)
{
	int N, A, B;
	int ans = 0;
  	int i;
  
	scanf("%d %d %d", &N, &A, &B);
	for(i = 1; i <= N; i++) {
		int tmp = sumOfDecimal(i);
		if(tmp >= A && tmp <= B) {
			ans += i;
		}
	}
 
	printf("%d\n", ans);
 
	return 0;
}

long long
/*-------------------------------------*/
#include <stdio.h>

double my_abs(double x) {
    if(x >= 0) return x;
    else return -x;
}

int main(void)
{
  double x;
  
  scanf("%lf", &x);
  printf("%f\n", my_abs(x));
  
  return 0;
}

/*-------------------------------------*/

#include <stdio.h>

int main(void) {
	int map[20][20];
	int N;
	int i, j;

	map[0][0] = 1;
	map[1][0] = map[1][1] = 1;
	for(i = 2; i <= 10; i++) {
		map[i][0] = map[i][i] = 1;
		for(j = 1; j <= i - 1; j++) {
			map[i][j] = map[i - 1][j] + map[i - 1][j - 1];
		}
	}

	scanf("%d", &N);
	for(i = 0; i <= N; i++) {
		for(j = 0; j <= i; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*-------------------------------------*/

#include <stdio.h>

int main(void) {
	int map[110][110];
	int N;
	int i, j;

	map[0][0] = 1;
	map[1][0] = map[1][1] = 1;
	for(i = 2; i <= 100; i++) {
		map[i][0] = map[i][i] = 1;
		for(j = 1; j <= i - 1; j++) {
			map[i][j] = (map[i - 1][j] + map[i - 1][j - 1]) % 2;
		}
	}

	scanf("%d", &N);
	for(i = 0; i <= N; i++) {
		for(j = 0; j <= i; j++) {
			if(map[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}

/*-------------------------------------*/
int map[20][20];
int N;
int i, j;

map[0][0] = 1;
map[1][0] = map[1][1] = 1;
for(i = 2; i <= 10; i++) {
	map[i][0] = map[i][i] = 1;
	for(j = 1; j <= i - 1; j++) {
		map[i][j] = map[i - 1][j] + map[i - 1][j - 1];
	}
}

scanf("%d", &N);
for(i = 0; i <= N; i++) {
	for(j = 0; j <= i; j++) {
		printf("%3d ", map[i][j]);
	}
	printf("\n");
}

return 0;

/*-------------------------------------*/
int map[110][110];
int N;
int i, j;

map[0][0] = 1;
map[1][0] = map[1][1] = 1;
for(i = 2; i <= 100; i++) {
	map[i][0] = map[i][i] = 1;
	for(j = 1; j <= i - 1; j++) {
		map[i][j] = (map[i - 1][j] + map[i - 1][j - 1]) % 2;
	}
}

scanf("%d", &N);
for(i = 0; i <= N; i++) {
	for(j = 0; j <= i; j++) {
		if(map[i][j]) printf("*");
		else printf(" ");
	}
	printf("\n");
}

return 0;
/*-------------------------------------*/
#include <stdio.h>
 
int main(void) {
  int A, B, C, X;
  int ans = 0;
  int a, b;
  
  scanf("%d %d %d %d", &A, &B, &C, &X);
  for(a = 0; a <= A; a++) {
    for(b = 0; b <= B; b++) {
      int c = (X - 500 * a - 100 * b) / 50;
      if(0 <= c && c <= C) ans++;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
/*-------------------------------------*/
#include <stdio.h>

int main(void) {
  int A, B, C;
  int sum = 0;
  int i;
  
  scanf("%d %d %d", &A, &B, &C);
  for(i = 0; i < B; i++) {
    sum += A;
    if(sum % B == C) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  
  return 0;
}


