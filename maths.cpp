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

int main()
{
    return 0;
}
