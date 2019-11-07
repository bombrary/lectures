#include <stdio.h>

int main(void) {
	char str[100];
	int N;

	scanf("%s", str);
	for (N = 0; str[N] != '\0'; N++) {
		printf("%c\n", str[N]);
	}
	printf("%d\n", N);

	return 0;
}
