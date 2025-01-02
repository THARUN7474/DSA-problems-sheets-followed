//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int b = prices[0];
        int p = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - b > p)
            {
                p = prices[i] - b;
            }
            if (prices[i] < b)
            {
                b = prices[i];
            }
        }
        return p;
    }

    int maxProfit(vector<int> &prices)
    {

        int minSoFar = prices[0], res = 0;

        for (int i = 1; i < prices.size(); i++)
        {

            // Update the minimum value seen so
            // far if we see smaller
            minSoFar = min(minSoFar, prices[i]);

            // Update result if we get more profit
            res = max(res, prices[i] - minSoFar);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends