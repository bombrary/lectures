#include <stdio.h>

int main(void)
{
  int a, b;
  int buf[10000];

  scanf("%d %d", &a, &b);
  for (int i = 0; i <= b - a; i++) {
    buf[i] = i + a;
  }

  for (int i = 0; i <= b - a; i++) {
    printf("%d ", buf[i]);
  }
  printf("\n");

  return 0;
}
