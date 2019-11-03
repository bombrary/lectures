#include <stdio.h>

int main() {
	int N;
	int A[300];
	int ans = 0;
	int flag = 1;
	int i;

	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	while(flag) {
		for(int i = 0; i < N; i++) {
			if(A[i] % 2 == 1) {
				flag = 0;
				break;
			} else {
				A[i] /= 2;
			}
		}
		if(flag) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
