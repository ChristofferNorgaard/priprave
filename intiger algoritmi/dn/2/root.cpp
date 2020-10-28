#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1000; i >= -1000; i--)
    {
        int r = a;
        for (int j = 0; j < n; j++)
        {
            r *= i;
            if (abs(r) > 1000)
            {
                break;
            }
        }
        if (r == b)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "No solution" << endl;
    return 0;
}