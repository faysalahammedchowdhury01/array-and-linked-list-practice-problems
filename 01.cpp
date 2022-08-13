/* Given an integer array A with size N and an integer K,where 0< N, K <10^5 . Write a program for getting Kth minimum and Kth maximum number from the given array.

Sample input:
6 3
1 13 20 4 15 17
Sample output:
13 15
Explanation: 1st minimum: 1, 2nd minimum: 4, third minimum: 13
 1st maximum: 20, 2nd maximum: 17, 3rd maximum: 15

 */

#include <bits/stdc++.h>
using namespace std;

void printKthMaximum(int arr[], int n, int k)
{
    int copyArr[n];
    for (int i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }

    int maxIndex;
    for (int i = 0; i < k; i++)
    {
        maxIndex = 0;
        for (int j = 0; j < n; j++)
        {
            if (copyArr[j] > copyArr[maxIndex])
            {
                maxIndex = j;
            }
        }
        copyArr[maxIndex] = -1;
    }

    cout << arr[maxIndex] << " ";
}

void printKthMinimum(int arr[], int n, int k)
{
    int copyArr[n];
    for (int i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }

    int minIndex;
    for (int i = 0; i < k; i++)
    {
        minIndex = 0;
        for (int j = 0; j < n; j++)
        {
            if (copyArr[j] < copyArr[minIndex])
            {
                minIndex = j;
            }
        }
        copyArr[minIndex] = pow(10, 6);
    }
    cout << arr[minIndex] << " ";
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printKthMinimum(arr, n, k);
    printKthMaximum(arr, n, k);

    return 0;
}