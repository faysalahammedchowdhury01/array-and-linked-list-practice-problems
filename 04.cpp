/* Given an integer array A with size N and an integer Q for queries, where 0< N,Q < 10^6.
Write a program using prefix sum concept to find the sum of a given range L to R for each query. (1 <= L,R <= N and L <= R)
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
1 2 3 4 5 6
3
1 3
4 6
2 4

Sample output:
6
15
9
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, left, right, sum;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int prefixSum[n];

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> left >> right;
        left--, right--;
        if (left == 0)
        {
            sum = prefixSum[right];
        }
        else
        {
            sum = prefixSum[right] - prefixSum[left - 1];
        }

        cout << "SUM: " << sum << endl;
    }

    return 0;
}