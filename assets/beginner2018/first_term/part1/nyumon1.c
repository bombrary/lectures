#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    printf("Good Bye, World.\n");
    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    printf("37 + 24 = %d\n", 37 + 24);
    return 0;
}

/*---------------------------------*/

printf("%d %c %d\n %f %s", 123, 'A', 128, 3.14, "ABC");

/*---------------------------------*/

#include <stdio.h>

int main() {
    int val1, val2;
    val1 = 10;
    val2 = val1 + 35;

    printf("val1 is %d\n", val1);
    printf("val2 is %d\n", val2);

    return 0;

}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int val1 = 10;
    int val2 = val1 + 35;

    printf("val1 is %d\n", val1);
    printf("val2 is %d\n", val2);

    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int a = 9;
    int b = 4;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a % b = %d\n", a % b);

    return 0; 
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int x = 0;
    printf("x: %d\n", x);
    
    x++;
    printf("x: %d\n", x);

    x += 5;
    printf("x: %d\n", x);

    x--;
    printf("x: %d\n", x);

    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int a, b;

    printf("input:");
    scanf("%d %d", &a, &b);

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);

    return 0;
}

/*---------------------------------*/

#include <stdio.h>

int main() {
    int a[5];
    int b[5] = {1, 2, 3, 4, 5};

    a[0] = b[0] + 1;
    a[1] = b[1] + 1;
    a[2] = b[2] + 1;
    a[3] = b[3] + 1;
    a[4] = b[4] + 1;

    printf("a[0]: %d\n", a[0]);
    printf("a[1]: %d\n", a[1]);
    printf("a[2]: %d\n", a[2]);
    printf("a[3]: %d\n", a[3]);
    printf("a[4]: %d\n", a[4]);

    return 0;
}

/*---------------------------------*/

char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char str[6] = "Hello";
char str[100] = "I like coffee and karaage and Precure."
/*---------------------------------*/

#include <stdio.h>

int main() {
    char a[100];

    printf("input: ");
    scanf("%s", a);
    printf("output: %s\n", a);

    return 0;
}

/*---------------------------------*/

int x;
scanf("%d", &x);
printf("%d", x);

char a[100];
scanf("%s", a);
printf("%s", a);