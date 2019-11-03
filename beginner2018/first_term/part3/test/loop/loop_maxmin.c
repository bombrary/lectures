#include <stdio.h>

int main(void) {
    int a[10];
    int i;
    int max = -1, min = 10000000;

    printf("input: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 10; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if(min > a[i]) {
            min = a[i];
        }
    }
    printf("max: %d, min: %d\n", max, min);
    
    return 0;
}
