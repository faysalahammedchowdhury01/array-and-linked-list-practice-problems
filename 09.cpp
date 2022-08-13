/* Given an integer array A with size N and k. Write a program to find out how many pairs exist in array A whose sum is equal to k.

          Sample input:


          Sample output:
          3
        [Here, 1+7=8, 2+6=8, 3+5=8 ]
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == k)
            {
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}