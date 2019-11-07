#include <stdio.h>

using namespace std;

int main() {
	char s[10];
	int ans = 0;

	scanf("%s", s);
	if(s[0] == '1') ans++;
	if(s[1] == '1') ans++;
	if(s[2] == '1') ans++;
	printf("%d", ans);

	return 0;
}
