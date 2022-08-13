/* Given an integer N. Write a program to print all prime numbers between 1 and N.

Sample input:
5

Sample output:
2 3 5
 */

#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n, count;
    cin >> n;
    count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (isPrimeNumber(i))
        {
            cout << i << " ";
            count++;
        }
    }

    cout << endl
         << "Total: " << count << endl;

    return 0;
}