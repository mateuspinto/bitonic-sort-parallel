#ifndef BITONIC_SORT_H
#define BITONIC_SORT_H

#include <pthread.h>
#include <stdlib.h>

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

void _bitonicSortRecursive(int *a, int low, int cnt, int dir)
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

// Parallel

// Como a função de ordenação bitônica requer mais de um argumento, é necessário criar uma estrutura pra conter esses dados
typedef struct
{
    int *a;
    int low;
    int cnt;
    int dir;
} _bitonicSortParallelArgs;

void *_bitonicSortRecursiveParallel(void *args)
{
    // Fazendo cópia dos argumentos da função anterior

    int *a = ((_bitonicSortParallelArgs *)args)->a;
    int low = ((_bitonicSortParallelArgs *)args)->low;
    int cnt = ((_bitonicSortParallelArgs *)args)->cnt;
    int dir = ((_bitonicSortParallelArgs *)args)->dir;

    _bitonicSortParallelArgs args0, args1;
    pthread_t t0, t1;

    if (cnt > 1)
    {
        int k = cnt / 2;

        // Criando os dados para a próxima função
        args0.a = a;
        args0.low = low;
        args0.cnt = k;
        args0.dir = 1;

        args1.a = a;
        args1.low = low + k;
        args1.cnt = k;
        args1.dir = 0;

        // Cria os dois threads para dividir o processamento
        pthread_create(&t0, NULL, _bitonicSortRecursiveParallel, &args0);
        pthread_create(&t1, NULL, _bitonicSortRecursiveParallel, &args1);

        pthread_join(t0, NULL);
        pthread_join(t1, NULL);

        _bitonicMerge(a, low, cnt, dir);
    }

    return 0;
}

// Função simples que facilita a chamada do algorítmo paralelo em C
void bitonicSortParallel(int a[], int N, int up)
{
    _bitonicSortParallelArgs args0;
    pthread_t t0;

    args0.a = a;
    args0.low = 0;
    args0.cnt = N;
    args0.dir = up;

    pthread_create(&t0, NULL, _bitonicSortRecursiveParallel, &args0);
    pthread_join(t0, NULL);
}

#endif