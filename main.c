#include <stdio.h>
#include "bitonicSort.h"

int main()
{
    int a[] = {149, 18, 169, 63, 51, 156, 13, 196, 46, 240, 68, 204, 225, 167, 121, 159, 172, 135, 118, 175, 214, 241, 248, 251, 192, 43, 107, 91, 31, 161, 202, 20, 85, 1, 157, 88, 199, 201, 106, 101, 53, 152, 40, 77, 60, 128, 65, 219, 215, 145, 238, 108, 7, 24, 180, 209, 244, 126, 168, 0, 119, 207, 23, 55, 14, 227, 151, 134, 99, 243, 50, 25, 191, 8, 142, 246, 173, 102, 239, 162, 226, 236, 15, 80, 140, 83, 32, 33, 187, 137, 130, 44, 38, 66, 216, 131, 59, 89, 129, 92, 198, 49, 189, 230, 250, 48, 139, 183, 39, 185, 171, 17, 64, 70, 184, 30, 73, 190, 124, 148, 67, 249, 71, 165, 47, 193, 154, 186, 36, 122, 141, 229, 115, 233, 114, 212, 164, 21, 153, 62, 6, 222, 78, 223, 224, 160, 110, 206, 147, 27, 45, 176, 218, 90, 254, 252, 208, 237, 155, 81, 103, 144, 72, 2, 220, 123, 109, 97, 100, 166, 11, 26, 117, 86, 75, 34, 234, 35, 98, 74, 29, 170, 52, 210, 125, 177, 105, 228, 93, 181, 9, 247, 253, 158, 79, 200, 116, 194, 54, 10, 22, 136, 16, 87, 217, 178, 104, 146, 127, 96, 58, 28, 232, 69, 188, 5, 245, 84, 12, 94, 112, 37, 203, 211, 255, 61, 56, 57, 133, 179, 132, 4, 150, 242, 197, 19, 213, 205, 195, 41, 120, 42, 138, 3, 143, 111, 113, 221, 82, 182, 174, 163, 95, 76, 235, 231};
    int N = sizeof(a) / sizeof(a[0]);

    int up = 1; // 1 = means sort in ascending order, 2 = descending

    bitonicSortParallel(a, N, up);

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
