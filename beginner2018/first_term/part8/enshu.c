#include <stdio.h>
 
struct Town {
  char name[32];
  int population;
};
 
int main(void)
{
  struct Town towns[1100];
  int N, i;
  int maxp = -1, maxi;
  int sum = 0;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%s %d", towns[i].name, &towns[i].population);
    sum += towns[i].population;
    if(towns[i].population > maxp) {
      maxp = towns[i].population;
      maxi = i;
    }
  }
  if(maxp > sum / 2)
    printf("%s\n", towns[maxi].name);
  else
    printf("atcoder\n");
  
  return 0;
}
/*-----------------------------------*/
#include <stdio.h>
 
int main(void) {
	int N, K;
	int i;
	int ans = 0;
 
	scanf("%d %d", &N, &K);
	for(i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if(x < K - x) ans += 2 * x;
		else ans += 2 * (K - x);
	}
 
	printf("%d\n", ans);
 
	return 0;
}
/*-----------------------------------*/
#include <stdio.h>

int sumOfArray(int *a, int n)
{
	int i;
	int sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i];

	return sum;
}

int main(void)
{
	int x[4] = {1, 2, 4, 6};

	printf("%d\n", sumOfArray(x, 4));

	return 0;
}
/*-----------------------------------*/
#include <stdio.h>
#include <string.h>

void revStr(char *str)
{
	int l = 0;
	int r = strlen(str) - 1;

	while(l < r) {
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
}

int main(void)
{
	char S[1000];

	scanf("%s", S);
	revStr(S);
	printf("%s\n", S);

	return 0;
}

/*-----------------------------------*/
#include <stdio.h>

int main(void)
{
	int x, y, s;
	while(1) {
		int i, j;
		int ans = -1;

		scanf("%d %d %d", &x, &y, &s);
		if(!(x | y | s)) break;

		for(i = 1; i <= s - 1; i++) {
			for(j = 1; j <= s - 1; j++) {
				int tx = i*(100+x)/100 + j*(100+x)/100;
				if(tx == s) {
					int ty = i*(100+y)/100 + j*(100+y)/100;
					if(ty > ans) ans = ty;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
/*-----------------------------------*/
