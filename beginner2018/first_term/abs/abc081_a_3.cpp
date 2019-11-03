#include <stdio.h>

int main() {
	int s;
	int ans = 0;

	scanf("%d", &s);
	while(s) {
		ans += s % 10;
		s /= 10;
	}
	printf("%d\n", ans);

	return 0;
}
