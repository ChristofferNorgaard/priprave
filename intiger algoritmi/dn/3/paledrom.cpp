#include <bits/stdc++.h>
using namespace std;
#define mx 10000000
int s[mx];
int main()
{
    int p, q;
    cin >> p >> q;
    memset(s, 1, sizeof(s));
    s[0] = 0;
    s[1] = 0;
    long long primes = 0;
    long long palindrome = 0;
    int m = 0;
    for (int i = 1; i < mx; i++)
    {
        if (s[i])
        {
            primes++;
            for (int j = i * 2; j < mx; j += i)
            {
                s[j] = 0;
            }
            //cout << i << " is a prime" << endl;
        }
        int rev = 0;
        int n = i;
        do
        {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        } while (n > 0);
        if (rev == i)
        {
            palindrome++;
            //cout << i << endl;
        }

        if (q * primes <= p * palindrome)
        {
            m = i;
        }
    }
    if (m)
    {
        cout << m << endl;
    }
    else if (m == mx - 1)
    {
        cout << "Palindromic tree is better than splay tree" << endl;
    }
    else
    {
        cout << "Palindromic tree is better than splay tree" << endl;
    }
}