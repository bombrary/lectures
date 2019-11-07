#include <stdio.h>

int SumOfDigit(int n) {
	int ret = 0;
	while(n) {
		ret += n % 10;
		n /= 10;
	}

	return ret;
}

int main() {
	int N, A, B;
	int ans = 0;
	int i;

	scanf("%d %d %d", &N, &A, &B);
	for(i = 0; i <= N; i++) {
		int sod = SumOfDigit(i);
		if(sod >= A && sod <= B) {
			ans += i;
		}
	}
	printf("%d\n", ans);

	return 0;
}
