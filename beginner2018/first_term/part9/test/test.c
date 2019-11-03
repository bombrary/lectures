#include <stdio.h>
#include <math.h>

int main(void)
{
	char S[1000];
	int n;
	
	scanf("%s %d", S, &n);
	n--;
	if(S[n] == '(') {
		int cnt = 1;
		while(cnt != 0) {
			n++;
			if(S[n] == '(') cnt++;
			else cnt--;
		}
		printf("%d\n", n + 1);
	} else {
		int cnt = -1;
		while(cnt != 0) {
			n--;
			if(S[n] == '(') cnt++;
			else cnt--;
		}
		printf("%d\n", n + 1);
	}

	return 0;
}
