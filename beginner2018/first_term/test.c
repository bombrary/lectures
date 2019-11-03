#include <stdio.h>

int main(void)
{
	unsigned x, y;

	scanf("%u %u", &x, &y);
	printf("%u\n%u\n%u\n%u\n", ~x, x | y, x & y, x ^ y);

	return 0;
}
