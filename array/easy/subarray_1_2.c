/*Input : Arr[] = { 1 , 2 , 3 , 4 , 5 , 5  }
Output :  { 1 2 3 4 }
          { 5 , 5 }

Input : Arr[] = { 4, 1, 2, 3 }
Output : {4 1}
         {2 3}

Input : Arr[] = { 4, 3, 2, 1}
Output : Not Possible*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitArray(int arr[], int n)
{
    int leftSum = 0;
    int rightSum = 0;
    int i;

    for (i = 0; i < n; i++)
        leftSum += arr[i];

    for (i = n - 1; i > 0; i--)
    {
        rightSum += arr[i];
        leftSum -= arr[i];
        if (leftSum == rightSum)
            return i;
    }

    return -1;
}

void printArray(int arr[], int n, int pos)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i == pos)
            printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int splitPos = splitArray(arr, n);
    if (splitPos == -1 || splitPos == n)
    {
        printf("no split file\n");
        return -1;
    }
    printArray(arr, n, splitPos);

    return 0;
}