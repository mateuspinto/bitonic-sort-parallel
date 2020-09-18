#ifndef BITONIC_SORT_H
#define BITONIC_SORT_H

// Common

void _swap(int *a, int *b)
{
    int temp = *a;
    (*a) = (*b);
    (*b) = temp;
}

void _compAndSwap(int a[], int i, int j, int dir)
{
    if (dir == (a[i] > a[j]))
    {
        _swap(&(a[i]), &(a[j]));
    }
}

void _bitonicMerge(int a[], int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
        {
            _compAndSwap(a, i, i + k, dir);
        }

        _bitonicMerge(a, low, k, dir);
        _bitonicMerge(a, low + k, k, dir);
    }
}

// Sequential

void _bitonicSortRecursive(int a[], int low, int cnt, int dir)
{

    if (cnt > 1)
    {
        int k = cnt / 2;

        _bitonicSortRecursive(a, low, k, 1);
        _bitonicSortRecursive(a, low + k, k, 0);

        _bitonicMerge(a, low, cnt, dir);
    }
}

void bitonicSort(int a[], int N, int up)
{
    _bitonicSortRecursive(a, 0, N, up);
}

// TODO: Parallel

#endif