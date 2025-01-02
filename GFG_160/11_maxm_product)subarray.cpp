#include <bits/stdc++.h>

using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        int rr = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int r = 1;
            for (int j = i; j < n; j++)
            {
                r = r * arr[j];
                rr = max(r, rr);
            }
        }
        return rr;
    }

    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int lr = 1;
        int rl = 1;
        int ol = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (lr == 0)
            {
                lr = 1;
            }
            if (rl == 0)
            {
                rl = 1;
            }
            lr *= nums[i];

            int j = n - i - 1;
            rl *= nums[j];

            ol = max({lr, rl, ol});
        }
        return ol;
    }
};

// Function to find maximum product subarray
int maxProduct(vector<int> &arr)
{
    // Your Code Here
    int cr_max = arr[0];
    int cr_min = arr[0];
    int or_max = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int t = max({arr[i], cr_max * arr[i], cr_min * arr[i]});
        cr_min = min({arr[i], cr_max * arr[i], cr_min * arr[i]});
        cr_max = t;
        or_max = max({or_max, cr_max});
    }
    return or_max;
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends