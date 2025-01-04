#include <bits/stdc++.h>

using namespace std;

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int ans = 0;
        int f = prices[0];
        int p = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - f > p)
            {
                p = prices[i] - f;
            }
            if (prices[i] < f)
            {
                ans += p;
                p = 0;
                f = prices[i];
            }
        }
        ans += p;
        return ans; // this code fails coz of this wont handle that holding only stock at a day
        // here when we have a stcock we need to sell then only we can buy
        // so we will add all local minm and next local maxm difference while traversing in next code
    }

    int maximumProfit(vector<int> &prices)
    {
        // code here
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }

    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int lmin = p[0];
        int lmax = p[0];
        int i = 0;
        int res = 0;
        while(i < n-1){

            while(i< n-1 && p[i]>= p[i+1]){i++;}
            lmin = p[i];

            while(i< n-1 && p[i] <= p[i+1]){i++;}
            lmax = p[i];


            // cout<< lmax << "max" << lmin <<"min" << lmax - lmin << "mam"<<endl;
            res += lmax-lmin;
            // cout<<res<<"res"<<endl;
        }
        return res;
    }

    // another approach is brute forch ---using recursion --check out that ---exponential time complexity 
};

//{ Driver Code Starts.
int main()
{
    int t;

    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
