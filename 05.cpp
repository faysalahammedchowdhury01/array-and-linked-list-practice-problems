/* Given an integer array A with size N and an integer Q for queries, where
(0 <  N < 10^5) , (-10^7 < Ai  < 10^7) and (0 < Q < 10^7) .
Write a program using prefix sum concept to find the sum of positive integers from a given range L to R for each query. (1 <= L,R <= N)

N
A1 A2 A3…….AN
Q
L1  R1
L2  R2
.    .
.     .
LQ  RQ
Sample input:
6
1 -2 3 -4 5 6
3
1 3
4 6
2 4

Sample output:
4
11
3
 */

// unsolved
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int positiveArr[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            positiveArr[i] = 0;
        }
        else
        {
            positiveArr[i] = arr[i];
        }
    }

    int prefixSum[n];
    prefixSum[0] = positiveArr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + positiveArr[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int left, right;
        cin >> left >> right;
        left--, right--;
        if (left == 0)
        {
            cout << "ANS: " << prefixSum[right] << endl;
        }
        else
        {
            cout << "ANS: " << prefixSum[right] - prefixSum[left - 1] << endl;
        }
    }

    return 0;
}