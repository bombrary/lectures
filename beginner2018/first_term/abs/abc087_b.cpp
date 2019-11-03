#include <stdio.h>

int main() {
	int A, B, C, X;
	int ans = 0;
	int i;

	scanf("%d %d %d %d", &A, &B, &C, &X);
	for(i = 0; i <= A; i++) {
		for(int j = 0; j <= B; j++) {
			int k = X / 50 - i * 10 - j * 2;
			if(k >= 0 && k <= C) ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
