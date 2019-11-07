#include <stdio.h>

int getIntArraySize(int *a)
{
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0]));
	return sizeof(a) / sizeof(a[0]);
}

int main(void)
{
	int a[5];
	printf("%d\n", getIntArraySize(a));

	return 0;
}
