#include <stdio.h>

int main(void) {
	int w, h;
	int i, j;

	scanf("%d %d", &w, &h);
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if((i + j) % 2 == 1) printf("+");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}
