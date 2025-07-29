#include <stdio.h>
#include <stdlib.h>
//сортировка методом Шелла
void ShellSort(int n, int mass[])
{
    int step, i, j, tmp; // Выбор шага 
    for (step = n / 2; step > 0; step /= 2)
    {
        // Перечисление элементов, которые сортируются на определенном шаге 
        for (i = step; i < n; i++) // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован 
        {
            for (j = i - step; j >= 0 && mass[j] > mass[j + step]; j -= step)
            {
                tmp = mass[j];
                mass[j] = mass[j + step];
                mass[j + step] = tmp;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int* mass;
    mass = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &mass[i]);
    //сортировка методом Шелла
    ShellSort(N, mass);
    //вывод отсортированного массива на экран   
    for (int i = 0; i < N; i++)
    {
        printf("%d", mass[i]);
        printf("\n");
    }
    //освобождение памяти
    free(mass);
    return 0;
}