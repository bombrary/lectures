#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
	char s[1005];
	scanf("%s",s);
	
	char new_s[3000] = "";
	int cnt = 0;
	for(int i=0;i<1000;i++){
		if(s[i]>'z'||s[i]<'a')break;
		char a = s[i];
		new_s[cnt]=s[i];
		cnt++;
		int new_cnt = 1;
		while(1){
			i++;
			if(s[i]==a){
				new_cnt ++;
			}
			else{
				int tmp_cnt = new_cnt;
				if(tmp_cnt >= 1000){
					new_s[cnt]=new_cnt/1000+'0';
					new_cnt -= new_cnt/1000*1000;
					cnt++;
				}
				if(tmp_cnt >= 100){
					new_s[cnt]=new_cnt/100+'0';
					new_cnt -= new_cnt/100*100;
					cnt++;
				}
				if(tmp_cnt >= 10){
					new_s[cnt]=new_cnt/10+'0';
					new_cnt -= new_cnt/10*10;
					cnt++;
				}
				new_s[cnt]=new_cnt/1+'0';
				cnt++;
				
				break;
			}
		}
		i--;
	}
	
	printf("%s\n",new_s);
	
	return 0;
}
