#include <stdio.h>
#include <math.h>

int main(void)
{
	int R0, W0, C, R;
	int ans;
	while(1) {
		ans = 0;
		scanf("%d %d %d %d", &R0, &W0, &C, &R);
		if(!(R0 | W0 | C | R)) break;
		
		printf("%f\n", ((double)C*W0 - R0)/R);
		printf("%f\n", ceil(((double)C*W0 - R0)/R));
		if(R0 / W0 < C)
			printf("%d\n", (C*W0 - R0 + R - 1)/R);
		else
			printf("0\n");
	}
	
	return 0;
}
