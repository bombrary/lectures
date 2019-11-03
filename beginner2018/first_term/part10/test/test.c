#include <stdio.h>

int main(void)
{
	int data[30000] = { 0 };
	int dp = 0, ip;
	char S[1000];
	char trash;

	while(1) {
		scanf("%s", S);
		for(ip = 0; S[ip] != '\0'; ip++) {
			switch(S[ip]) {
			case '>':
				dp++;
				break;
			case '<':
				dp--;
				break;
			case '+':
				data[dp]++;
				break;
			case '-':
				data[dp]--;
				break;
			case '.':
				printf("%c", data[dp]);
				break;
			case ',':
				scanf("%c", &trash);
				scanf("%c", &data[dp]);
				break;
			case '[':
				if(data[dp] == 0) {
					int cnt = 1;
					while(cnt != 0) {
						ip++;
						if(S[ip] == '[') cnt++;
						else if(S[ip] == ']') cnt--;
					}
				}
				break;
			case ']':
				if(data[dp] != 0) {
					int cnt = 1;
					while(cnt != 0) {
						ip--;
						if(S[ip] == ']') cnt++;
						else if(S[ip] == '[') cnt--;
					}
				}
				break;
			}
		}
		printf("\n");
	}

	return 0;
}
