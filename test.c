#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Integer one\n");
    scanf("%d", &a);
    printf("Integer two");
    scanf("%d", &b);
    printf("%d", a + b);

    return 0;
}