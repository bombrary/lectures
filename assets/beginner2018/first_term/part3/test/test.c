#include <stdio.h>

int main(void) {
	int a, n;
	int i;
	int ans = 1;

	scanf("%d %d", &a, &n);
	for(i = 0; i < n; i++) ans *= a;
	printf("%d\n", ans);

    return 0;
}
