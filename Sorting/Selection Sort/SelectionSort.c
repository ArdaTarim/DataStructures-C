#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selecSort(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {   
        int currenIdx = i;
        int current_min = arr[i];
        for (int j = i; j < arr_len; j++)
        {
            if (arr[j] < current_min) {
                currenIdx = j;
                current_min = arr[j];
            }
        }
        swap(&arr[i], &arr[currenIdx]);
    }
}

int main()
{
    int arr[] = {3, 7, 1, 34, 2, 86, 34, 83, 80, 0, 12, 3};
    int arr_len = 12;

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }

    selecSort(arr, arr_len);
    printf("\n");

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
}