#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int prev = 0, ans = 0;
        for (int i = 0; i < a; ++i)
        {
            int a;
            cin >> a;
            ans = max(ans, a - prev);
            prev = a;
        }
        ans = max(ans, 2 * (b - prev));
        cout << ans << '\n';
        // vector<int> c;
        // for (int i = 0; i < a; i++)
        // {
        //     int x;
        //     cin >> x;
        //     c.push_back(x);
        // }
        // if ((c[0] - 0) > (b - c[a - 1])*2)
        // {
        //     cout << c[0] - 0 << endl;
        // }
        // else
        // {
        //     cout << (b - c[a - 1])*2 << endl;
        // }
        // max(a1,a2−a1,…,an−an−1,2(x−an))
    }
}