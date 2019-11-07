#include <stdio.h>

using namespace std;

int main() {
	char s[10];
	int ans = 0;
	int i;

	scanf("%s", s);
	for(i = 0; i < 3; i++) {
		if(s[i] == '1') {
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}
