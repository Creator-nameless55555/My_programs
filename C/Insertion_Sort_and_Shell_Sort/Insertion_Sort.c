#include <stdio.h>
#include <stdlib.h>

//сортировка вставками
void InsertionSort(int n, int mass[])
{
    int pass, j, hold;

    for (pass = 0; pass < n - 1; pass++) {
        for (j = pass + 1; j < n; j++) {
            if (mass[pass] > mass[j]) {
                hold = mass[j];
                mass[j] = mass[pass];
                mass[pass] = hold;
            }
        }
    }
}

int main()
{
    //ввод N
    int N;
    //printf("Input N: ");
    scanf("%d", &N);
    //выделение памяти под массив
    int* mass;
    mass = (int*)malloc(N * sizeof(int));
    //ввод элементов массива
    //printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mass[i]);
    }
    //сортировка вставками
    InsertionSort(N, mass);
    //вывод отсортированного массива на экран
    //printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", mass[i]);
        printf("\n");
    }
    //освобождение памяти
    free(mass);
    return 0;
}