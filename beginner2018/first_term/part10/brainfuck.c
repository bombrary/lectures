#include <stdio.h>

#define S_SIZE 1100
#define D_SIZE 31000

int main(void)
{
	char S[S_SIZE];
	char data[D_SIZE] = { 0 };
	int dp = 0;
	int ip;

	while(1) {
		scanf("%s", S);
		if(S[0] == 'q') break;
		
		for(ip = 0; S[ip] != 0; ip++) {
			if(S[ip] == '>' && dp < D_SIZE) {
				dp++;
			} else if(S[ip] == '<' && dp > 0) {
				dp--;
			} else if(S[ip] == '+') {
				data[dp]++;
			} else if(S[ip] == '-') {
				data[dp]--;
			} else if(S[ip] == '.') {
				printf("%c", data[dp]);
			} else if(S[ip] == ',') {
				scanf("%c", &data[dp]);
			} else if(S[ip] == '[' && data[dp] == 0) {
				int cnt = 1;
				while(cnt != 0) {
					ip++;
					if(S[ip] == '\0') {
						printf("Error\n");
						return 0;
					}

					if(S[ip] == '[') cnt++;
					else if(S[ip] == ']') cnt--;
				}
			} else if(S[ip] == ']' && data[dp] != 0) {
				int cnt = -1;
				while(cnt != 0) {
					ip--;
					if(ip < 0) {
						printf("Error\n");
						return 0;
					}

					if(S[ip] == '[') cnt++;
					else if(S[ip] == ']') cnt--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
