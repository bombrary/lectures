#include <stdio.h>

void showBit(unsigned x)
{
  int i;
  for(i = 31; i >= 0; i--) {
    if((x >> i) & 1) printf("1");
    else printf("0");
  }
  printf("\n");
}

unsigned leftRotate(unsigned x, int n)
{
	unsigned tmp = x >> (32 - n);
	unsigned ret = (x << n) | tmp;
	
	return ret;
}
int main(void)
{
	showBit(938109);
	showBit(leftRotate(938109, 30));

	return 0;
}
