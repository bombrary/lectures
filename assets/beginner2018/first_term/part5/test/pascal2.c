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
