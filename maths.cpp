#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Get the prime factors of a number (unique primes only).
 *
 * @param n The integer to factorize (n > 1).
 * @return vector<int> A vector of unique prime factors of n.
 *
 * @note Example: getPrimeFactors(36) → {2, 3}
 */
vector<int> getPrimeFactors(int n)
{
    vector<int> factors;
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            factors.push_back(d);
            while (n % d == 0)
                n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

/**
 * @brief Get all factors (divisors) of a number.
 *
 * @param n The integer to find factors of (n > 0).
 * @return vector<long long> A sorted vector containing all divisors of n.
 *
 * @note Example: getFactors(36) → {1, 2, 3, 4, 6, 9, 12, 18, 36}
 */
vector<long long> getFactors(long long n)
{
    vector<long long> factors;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

/**
 * @brief Check if a number is prime.
 *
 * @param num The integer to check.
 * @return true If num is prime.
 * @return false If num is not prime.
 *
 * @note Example: isPrime(7) → true, isPrime(9) → false
 */
bool isPrime(long long num)
{
    if (num < 2)
        return false;
    if (num % 2 == 0)
        return num == 2;
    for (long long i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

/**
 * @brief Check if a number is a power of two.
 *
 * @param n The integer to check (n > 0).
 * @return true If n is a power of two.
 * @return false Otherwise.
 *
 * @note Uses bitwise trick: n & (n-1) == 0
 * @note Example: isPowerOfTwo(8) → true, isPowerOfTwo(10) → false
 */
bool isPowerOfTwo(long long n)
{
    return (n > 0) && (n & (n - 1)) == 0;
}

/**
 * @brief Compute Euler's Totient function φ(n) for a single number.
 *
 * @param n The integer to evaluate (n > 0).
 * @return int The number of integers from 1 to n that are coprime with n.
 *
 * @note Example: phi_single(36) → 12
 * @note Complexity: O(√n)
 */
int phi_single(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

/**
 * @brief Compute Euler's Totient function φ(n) for all numbers up to N.
 *
 * @param N The upper limit (inclusive).
 * @return vector<int> A vector where phi[i] = φ(i) for 1 <= i <= N.
 *
 * @note Example: phi_sieve(10) →
 *       {0,1,1,2,2,4,2,6,4,6,4}
 *       (phi[1]=1, phi[2]=1, phi[3]=2, etc.)
 * @note Complexity: O(N log log N)
 */
vector<int> phi_sieve(int N)
{
    vector<int> phi(N + 1);
    iota(phi.begin(), phi.end(), 0); // phi[i] = i
    for (int p = 2; p <= N; p++)
    {
        if (phi[p] == p)
        { // p is prime
            for (int k = p; k <= N; k += p)
            {
                phi[k] -= phi[k] / p;
            }
        }
    }
    return phi;
}

int main()
{
    int n = 36;

    cout << "Prime factors of " << n << " : ";
    for (int p : getPrimeFactors(n))
        cout << p << " ";
    cout << "\n";

    cout << "All factors of " << n << " : ";
    for (long long f : getFactors(n))
        cout << f << " ";
    cout << "\n";

    cout << n << (isPrime(n) ? " is prime\n" : " is not prime\n");
    cout << n << (isPowerOfTwo(n) ? " is power of two\n" : " is not power of two\n");

    cout << "Euler's Totient φ(" << n << ") = " << phi_single(n) << "\n";

    auto phi = phi_sieve(10);
    cout << "Euler's Totient values up to 10:\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "φ(" << i << ") = " << phi[i] << "\n";
    }

    return 0;
}