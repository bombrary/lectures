#include <stdio.h>

int main(void) {
	int i, j;
	int flag = 0;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			int p = i * j;
			if (p >= 70) {
				flag = 1;
				break;
			} else {
				printf("%3d", i * j);
			}
		}
		printf("\n");
		if(flag) break;
	}
	
	return 0;
}

