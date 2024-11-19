//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/chocolate-distribution-problem/---in notion too(( explanation)


// } Driver Code Ends
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int mn = INT_MAX;
        for(int i = 0; i<= a.size()-m;i++){
            if(a[i+m-1]-a[i]<=mn){
                mn = a[i+m-1]-a[i];
            }
        }
        return mn;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int m;
        cin >> m;
        cin.ignore();
        Solution ob;
        cout << ob.findMinDiff(arr, m) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends