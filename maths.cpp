#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long num)
{
    for (long long i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
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
