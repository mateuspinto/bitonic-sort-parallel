#include <stdio.h>
#include "bitonicSort.h"

int main()
{
    int a[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int N = sizeof(a) / sizeof(a[0]);

    int up = 1; // 1 = means sort in ascending order, 2 = descending

    bitonicSort(a, N, up);

    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d", a[i]);
        if (i != N - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
