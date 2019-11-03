#include <stdio.h>

int main(void)
{
	unsigned x, y;

	scanf("%u %u", &x, &y);
	printf("%u\n%u\n%u\n%u\n", ~x, x | y, x & y, x ^ y);

	return 0 0;
}

/*---------------------------------*/
unsigned TARO = 1 << 2; /*001を2ビット左シフトして100*/
unsigned JIRO = 1 << 1; /*001を2ビット左シフトして010*/
unsigned SABURO = 1;
X = TARO | SABURO;