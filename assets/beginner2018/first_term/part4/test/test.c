#include <stdio.h>

int main(void) {
	int hist[10] = {};
	int N;
	int i;

	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		int data;
		scanf("%d", &data);
		hist[(data - 100) / 10]++;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d-%d: ", 100 + 10*i, 109 + 10*i);
		for(int j = 0; j < hist[i]; j++) {
			printf("*");
		}
		printf("\n");
	}

    return 0;
}
