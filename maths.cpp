#include <bits/stdc++.h>

using namespace std;

void getFactors(long long n)
{
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                cout << i << " " << (n / i) << endl;
            }
            else
            {
                cout << i << endl;
            }
        }
    }
}

bool isPrime(long long num)
{
    for (long long i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return num > 1;
}

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    double logVal = log2(n);
    return floor(logVal) == logVal; // check if it's an integer
}

int main()
{
    return 0;
}
