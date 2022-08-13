/* Given a sorted integer array A with size N integers and an integer k. Write a program to find out the position of k from array A using binary search.
Sample input:
7 9
1 2 3 4 7 8 9
Sample output:
7
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int val)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == val)
            return mid;
        else if (arr[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
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

    int index, pos;
    index = binarySearch(arr, n, k);
    if (index != -1)
    {
        pos = index + 1;
        cout << pos << endl;
    }
    else
    {
        cout << "Not Found\n";
    }

    return 0;
}