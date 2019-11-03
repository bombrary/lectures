
#include <stdio.h>

int main(void) {
    int a[1000];
    int N, i, sum = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < N; i++) {
        sum += a[i];
    }

    printf("%d\n", sum);

    return 0;
}
