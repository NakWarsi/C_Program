#include <stdio.h>
#include <stdarg.h>
float average(int n, ...)
{
    va_list x;
    float sum = 0;
    float avg;
    va_start(x, n);

    for (int i = 0; i < n; i++)
        sum = sum + va_arg(x, int);
    va_end(x);
    avg = sum / n;

    return avg;
}

int main()
{
    printf("average of 1,2,3,4,5,=%.2f\n", average(5, 1, 2, 3, 4, 5));
    printf("average of 1,2,3,4,5,6,7,8,9,10=%f \n", average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    int y = average(20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);

    printf("%d\n", y);
    return 0;
}
