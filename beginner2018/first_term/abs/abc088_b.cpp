#include <stdio.h>

int main() {
	int N;
	int a[200];
	int i, j, p = 0;
	int P[2] = {0};

	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N; i++) {
		int max = 0;
		int mi = -1;
		for(j = 0; j < N; j++) {
			if(max < a[i]) {
				max = a[i];
				mi = i;
			}
		}
		P[p] += max;
		printf("%d\n", max);
		a[mi] = -1;
		p = 1 - p;
	}

	printf("%d %d\n", P[0], P[1]);

	return 0;
}
