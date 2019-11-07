/*Practice A*/
#include <stdio.h>
 
int main() {
	int a, b, c;
	char s[128];
 
	scanf("%d", &a);
	scanf("%d %d", &b, &c);
	scanf("%s", s);
 
	printf("%d %s\n", a + b + c, s);
 
	return 0;
}
/*ABC068_A*/
#include <stdio.h>
 
int main() {
  int N;
  
  scanf("%d", &N);
  printf("ABC%d\n", N);
  
  return 0;
}