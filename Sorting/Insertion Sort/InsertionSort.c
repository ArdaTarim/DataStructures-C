#include <stdio.h>

void insertSort(int arr[], int arr_len)
{
    int i, j;
    int element;
    for (int i = 1; i < arr_len; i++)
    {   
        element = arr[i];
        j = i -1;

        while(j >= 0 && arr[j] > element)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = element;
        
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

    insertSort(arr, arr_len);
    printf("\n");

    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
}