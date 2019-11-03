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

X &= ~TARO;
X = X & ~TARO;
X &= ~(TARO | SABURO);

(X >> 2) & 1
if ((X >> 2) & 1) {
    三郎が出席していた場合の処理
}
/*---------------------------------*/
#include <stdio.h>

int main(void) {
    unsigned x;
    int i;

    scanf("%u", &x);
    for(i = 0; i < 3; i++) {
        if((x >> i) & 1) printf("o ");
        else printf("x ");
    }
    printf("\n");

    return 0;
}

for(i = 0; i < 3; i++) {
    if(x & (1 << i)) printf("o ");
    else printf("x ");
}

tmp = x;
x = y;
y = tmp;

x ^= y;
y ^= x;
x ^= y;

x = x ^ y;
y = x ^ y;
x = x ^ y;

x = a
y = b
x = x ^ y = a ^ b
y = x ^ y = (a ^ b) ^ b = a
x = x ^ y = (a ^ b) ^ a = b