#include <stdio.h>

int main(void)
{
  char s[1100];
  int i = 0;
  int cnt = 1;
  
  scanf("%s", s);
  for(i = 1; s[i] != '\0'; i++) {
    if(s[i] != s[i - 1]) {
      printf("%c%d", s[i - 1], cnt);
      cnt = 1;
    } else {
    	cnt++;
    }
  }
  printf("%c%d\n", s[i - 1], cnt);
  
  return 0;
}
