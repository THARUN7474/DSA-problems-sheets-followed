// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         string temp;
//         cin >> temp;
//         int c1, c2, c3;
//         c1 = c2 = c3 = 0;
//         // cout << "Input String: " << temp << endl;
//         for (int i = 1; i < n - 1; i++) // Start from 1 and go to n-2 to avoid boundary issues
//         {
//             if (temp[i - 1] == temp[i] && temp[i] == temp[i + 1])
//             {
//                 // cout << "Triple match at indices " << i - 1 << ", " << i << ", and " << i + 1 << ": "
//                 //      << temp[i - 1] << temp[i] << temp[i + 1] << endl;
//                 c1 = 1;
//                 break;
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (temp[i] == '.')
//             {
//                 c2 = 1;
//                 c3++;
//             }
//         }
//         // cout << "Flags: c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << endl;
//         if (c2 != 1)
//         {
//             cout << 0 << endl;
//         }
//         else if (c1 != 1)
//         {
//             cout << c3 << endl;
//         }
//         else
//         {
//             cout <<2 << endl;
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string temp;
        cin >> temp;
        int dotCount = 0;
        bool hasTripleDot = false;

        for (int i = 0; i < n; i++)
        {
            if (temp[i] == '.')
            {
                dotCount++;
            }
            if (i < n - 2 && temp[i] == '.' && temp[i + 1] == '.' && temp[i + 2] == '.')
            {
                hasTripleDot = true;
            }
        }

        if (hasTripleDot)
        {
            cout << 2 << endl;
        }
        else if (dotCount == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << dotCount << endl;
        }
    }
    return 0;
}
