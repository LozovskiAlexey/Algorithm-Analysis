#include "sort.h"

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}


void buble_sort(int arr[], int n)
{
    if (n > 1)
    {
        bool swapped = true;

        while (swapped)
        {
            swapped = false;

            for (int i=0; i+1<n; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    swap(arr[i], arr[i+1]);
                    swapped = true;
                }
            }
            n--;
        }
    }
}


void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
        for(int j=i; j>0 && arr[j-1]>arr[j]; j--)
                swap(arr[j-1], arr[j]);
}


void selection_sort(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        int tmp_ind = i;
        int tmp_val = arr[i];

        for (int j = i+1; j<n; j++)
            if (arr[j] < tmp_val)
            {
                tmp_ind = j;
                tmp_val = arr[j];
            }

        swap(arr[i], arr[tmp_ind]);
    }
}
