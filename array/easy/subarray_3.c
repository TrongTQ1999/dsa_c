/*Input: a[] = {3, 4, 5, 6, 7, 2, 10, 11}, K = 5
Output: 6
The possible subarrays are {6}, {7}, {6, 7}, {10}, {11} and {10, 11}.

Input: a[] = {8, 25, 10, 19, 19, 18, 20, 11, 18}, K = 13
Output: 12  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkElement(int arr[], int n, int k)
{
    int i;
    int count = 0;
    int number = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > k)
            count++;
        else
        {
            number += count * (count + 1) / 2;
            count = 0;
        }
    }
    if (count)
        number += count * (count + 1) / 2;
    return number;
}

int main()
{
    int a[] = {8, 25, 10, 19, 19, 18, 20, 11, 18};
    int k = 13;
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d \n", checkElement(a, n, k));

    return 0;
}