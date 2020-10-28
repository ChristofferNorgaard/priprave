#include <bits/stdc++.h>
using namespace std;
#define mx 10001
#define mxs 10000000
int s[mx];
int a[mx];
int b[mx];

int main()
{
    /*
    cin.tie(nullptr);
    cin.sync_with_stdio(false);*/
    int m, n;
    cin >> m >> n;
    int af[m];
    for (int i = 0; i < m; i++)
    {
        cin >> af[i];
    }
    int bf[n];
    for (int i = 0; i < n; i++)
    {
        cin >> bf[i];
    }
    /*
    memset(s, 0, mx);
    memset(a, 0, mx);
    memset(b, 0, mx);
    */
    s[0] = 1;
    s[1] = 1;
    for (int i = 2; i < mx; i++)
    {
        if (s[i] == 0)
        {
            for (int j = i; j < mx; j += i)
            {
                s[j] = i;
            }
        }
    }
    /*
    for (int i = 0; i < 100; i++)
    {
        cout << i << " " << s[i] << endl;
    }
    //cout << "here" << endl;*/
    for (int i = 0; i < m; i++)
    {
        int res = af[i];
        //cout << res << endl;
        while (res > 1)
        {
            a[s[res]]++;
            //cout << s[res] << endl;
            res /= s[res];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int res = bf[i];
        while (res > 1)
        {
            b[s[res]]++;
            res /= s[res];
        }
    }
    //cout << "here" << endl;
    for (int i = 0; i < mx; i++)
    {
        int l = min(a[i], b[i]);
        a[i] -= l;
        b[i] -= l;
    }
    /*
    for (int i = 0; i < 20; i++)
        cout << b[i] << " ";
    */
    //cout << endl;
    vector<int> fa;
    vector<int> fb;
    long long res = 1;
    for (int i = 1; i < mx; i++)
    {
        if (a[i] != 0)
        {
            for (int j = 0; j < a[i]; j++)
            {
                if (res * i <= mx)
                {
                    res *= i;
                    //cout << i * a[i] << " " << res << endl;
                }
                else
                {
                    fa.push_back(res);
                    res = i;
                    //cout << res << endl;
                }
            }
        }
    }
    fa.push_back(res);
    //cout << res << endl;
    res = 1;
    for (int i = 0; i <= mx; i++)
    {
        if (b[i] != 0)
        {
            for (int j = 0; j < b[i]; j++)
            {
                if (res * i <= mx)
                {
                    res *= i;
                }
                else
                {
                    fb.push_back(res);
                    res = i;
                    //cout << res << endl;
                }
            }
        }
    }
    fb.push_back(res);
    //cout << res << endl;
    cout << fa.size() << " " << fb.size() << endl;
    for (int i = 0; i < fa.size() - 1; i++)
    {
        cout << fa[i] << " ";
    }
    cout << fa[fa.size() - 1] << endl;
    for (int i = 0; i < fb.size() - 1; i++)
    {
        cout << fb[i] << " ";
    }
    cout << fb[fb.size() - 1] << endl;
}