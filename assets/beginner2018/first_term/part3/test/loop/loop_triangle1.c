#include <stdio.h>

int main(void) {
	int h;
	int i, j;

	scanf("%d", &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
