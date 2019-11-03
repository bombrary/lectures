#include <stdio.h>

int main(void)
{
	int n;
	int max, min, sum;
	int i;
	
	while(1) {
		scanf("%d", &n);
		if(!n) break;

		max = -1;
		min = 10000;
		sum = 0;
		for(i = 0; i < n; i++) {
			int s;
			scanf("%d", &s);
			sum += s;
			if(max < s) max = s;
			if(s < min) min = s;
		}
		printf("%d\n", (sum - max - min) / (n - 2));
	}

	return 0;
}
/*-------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	int R0, W0, C, R;
	int ans;
	while(1) {
		ans = 0;
		scanf("%d %d %d %d", &R0, &W0, &C, &R);
		if(R0 == 0 && W0 == 0 && C == 0 && R == 0) break;

		while((R0 + ans*R)/W0 <C) ans++;
		printf("%d\n", ans);
	}
	
	return 0;
}
/*-------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	int R0, W0, C, R;
	int ans;
	while(1) {
		ans = 0;
		scanf("%d %d %d %d", &R0, &W0, &C, &R);
		if(!(R0 | W0 | C | R)) break;
		
		if(C*W0 >= R0)
			printf("%d\n", (C*W0 - R0 + R - 1)/R);
		else
			printf("0\n");
	}
	
	return 0;
}
/*-------------------------------------------------*/
#include <stdio.h>

int sumDigit(int n) {
	if(n / 10 == 0)
		return n;
	else
		return sumDigit(n / 10) + (n % 10);
}


int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d\n", sumDigit(N));
	
	return 0;
}


/*-------------------------------------------------*/
#include <stdio.h>

int main(void)
{
  int N = 1;
  int X;
  
  scanf("%d", &X);
  while(N*N*N*N <= X) N++;
  printf("%d\n", i);
  
  return 0;
} 
/*-------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	int N, X;

	scanf("%d", &X);
	for(N = 1; N < 200; N++) {
		if(N*N*N*N == X) {
			printf("%d\n", X);
			reutrn 0;
		}
	}

	return 0;
}