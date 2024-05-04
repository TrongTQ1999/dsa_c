/*Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 4, sum = 18
Output: YES
Subarray = {4, 2, 10, 2}

Input: arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}
        k = 3, sum = 6
Output: YES*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkArray(int arr[], int n, int k, int sum)
{
    int i, j;
    for (i = 0; i < n - k; i++)
    {
        int recentSum = 0;
        for (j = 0; j < k; j++)
        {
            recentSum += arr[i + j];
        }
        if (recentSum == sum)
            return i;
    }

    return -1;
}

void printSubArray(int arr[], int k, int pos)
{
    int i;
    for (i = pos; i < pos + k; i ++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int sum = 18;

    int n = sizeof(arr) / sizeof(arr[0]);
    int subPos = checkArray(arr, n, k, sum);
    if (subPos == -1)
    {
        printf("no sub array\n");
    }
    printSubArray(arr, k, subPos);

    return 0;
}