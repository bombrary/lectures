#include <stdio.h>

int main(void)
{
    printf("%d %d %d", 'A', 'B', 'C');
    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void)
{
    int i;
    for(i = 0; i < 26; i++) {
        printf("%c", 'A' + i);
    }
    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);
    printf("%d\n", c - 'A');
    return 0;
}
/*---------------------------------*/
#include <stdio.h>

int main(void)
{
    char S[5];
    int ans;

    scanf("%s", S);
    ans = (S[0] - '0') + (S[1] - '0') + (S[2] - '0');
    printf("%d\n", ans);

    return 0;
}
/*---------------------------------*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int flag = 1;
    int l, r;
    scanf("%s", str);
    
    l = 0;
    r = strlen(str);
    while(l < r) {
        if(str[l] != str[r]) {
            flag = 0;
            break;
        }
        l++;
        r--;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");

    return 0;
}
''
/*---------------------------------*/
if('A' <= c && c <= 'Z') {
    ...
}
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
/*---------------------------------*/
