/* badcount.c -- некорректное количество аргументов */
#include <stdio.h>
int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;

    printf("%d\n", n, m);     /* слишком много аргументов */
    printf("%d %d %d\n", n);  /* аргументов недостаточно */
    printf("%d %d\n", f, g);  /* неправильные типы значений */

    return 0;
}
