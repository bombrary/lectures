#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	if(a * b % 2 == 1) {
		printf("Odd\n");
	} else {
		printf("Even\n");
	}

	/*条件分岐の他の方法
	 * a % 2 == 0 || b % 2 == 0 */

	return 0;
}
