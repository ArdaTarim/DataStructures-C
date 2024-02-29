#include <stdio.h>

// swaps the values of 2 elements
void swap(int *a, int *b) //takes 2 pointers as parameters
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubbleSort(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (*(p+j) > *(p+j+1))
            {
                swap((p+j), (p+j+1));
            }
        }
    }
}

int main()
{
    // array of shuffled numbers
    int arr[] = {5, 3, 4, 2, 1, 8, 7, 6};
    int arr_len = 8;

    // pointer showing the first element of the array
    int *p_arr = &arr[0];

    // print the shuffled array
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }

    // sort the array
    bubbleSort(p_arr, arr_len);
    printf("\n\n");

    // print the sorted array
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    return 0;
}