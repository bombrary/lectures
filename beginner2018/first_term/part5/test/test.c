#include <stdio.h>
 
int main() {
	int N;
	int i;
	int min;
 
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		int A;
		int cnt;
		scanf("%d", &A);
		while(A % 2 == 0) {
			cnt++;
			A /= 2;
		}
		if(min > cnt) min = cnt;
	}
 
	printf("%d\n", min);
 
	return 0;
}
