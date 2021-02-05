#include<cstring>
#include<iostream>
using namespace std;

#define MAX 100000000

bool prime[MAX + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MAX; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}

void print_primes(int n)
{
    int count = 0, num = 2;
    while (count < n)
    {
        if (prime[num])
        {
            cout << num << " ";
            count++;
        }
        num++;
    }
}

int main()
{
    SieveOfEratosthenes();
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "First " << n << " prime numbers are: ";
    print_primes(n);
    cout << endl;
    return 0;
}