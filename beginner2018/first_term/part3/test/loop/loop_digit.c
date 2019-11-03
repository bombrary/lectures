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
