#include <stdio.h>

int main(void)
{
  char X;
  
  scanf("%c", &X);
  printf("%d\n", X - 'A' + 1);
  
  return 0;
}
/*---------------------------------*/
#include <stdio.h>

void showBit(unsigned x)
{
	unsigned mask = 1 << 31;
	for(int i = 0; i < 32; i++) {
		if((x << i) & mask) printf("1");
		else printf("0");
	}
	printf("\n");
}

int main(void)
{
	showBit(7);
	return 0;
}
/*---------------------------------*/
void showBit(unsigned x)
{
  int i;
  for(i = 31; i >= 0; i--) {
    if((x << i) & 1) printf("1");
    else printf("0");
  }
  printf("\n");
}

/*---------------------------------*/

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

/*---------------------------------*/

unsigned leftRotate(unsigned x, int n)
{
	unsigned tmp = x >> (32 - n);
	unsigned ret = (x << n) | tmp;
	
	return ret;
}

/*---------------------------------*/
#include <stdio.h>

int main(void)
{
  unsigned X;
  int i, n, sum = 0;
  int a[30];
  
  scanf("%d %u", &n, &X);
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  
  for(i = 0; i < n; i++) {
    if((X >> i) & 1) sum += a[i];
  }
  printf("%d\n", sum);
  
  return 0;
}

#include <stdio.h>
#include <string.h>
 
int main() {
  char s[210000];
  int ap, zp;
  int ans = -1;
  int ssize;
  
  scanf("%s", s);

  ap = 0;
  zp = strlen(s);
  while(s[ap] != 'A') ap++;
  while(s[zp] != 'Z') zp--;
  
  printf("%d\n", zp - ap + 1);
  
  return 0;
}
/*---------------------------------*/
#include <stdio.h>
 
int main(void)
{
  char S[20], T[20];
  
  scanf("%s %s", S, T);
  for(int i = 0; S[i] != '\0'; i++) {
    if(S[i] != '@' && T[i] != '@' && S[i] != T[i]) {
      printf("You will lose\n");
      return 0;
    } else {
      if((S[i] == '@' 
         && T[i] != 'a' 
         && T[i] != 't' 
         && T[i] != 'c' 
         && T[i] != 'o' 
         && T[i] != 'd' 
         && T[i] != 'e' 
         && T[i] != 'r'
         && T[i] != '@')
      || (T[i] == '@'
         && S[i] != 'a' 
         && S[i] != 't' 
         && S[i] != 'c' 
         && S[i] != 'o' 
         && S[i] != 'd' 
         && S[i] != 'e' 
         && S[i] != 'r'
         && S[i] != '@')) {
        printf("You will lose\n");
        return 0;
      }
    }
  }
  printf("You can win\n");
  return 0;
}

#include <stdio.h>
 
int main(void)
{
  char S[20];
  char T[20];
  char pat[] = "atcoder";
  int i, j;
  
  scanf("%s %s", S, T);
  for(i = 0; S[i] != '\0'; i++) {
    int flag = 0;
    if(S[i] == T[i]) flag = 1;
    if(S[i] == '@' || T[i] == '@') {
      for(j = 0; j < 7; j++) {
        if(S[i] == pat[j] || T[i] == pat[j]) {
          flag = 1;
          break;
        }
      }
    }
    if(flag == 0) {
      printf("You will lose\n");
      return 0;
    }
  }
  printf("You can win\n");
  return 0;
}