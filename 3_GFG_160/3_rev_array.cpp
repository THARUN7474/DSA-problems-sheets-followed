// C++ Program to reverse an array using Recursion

#include <iostream>
#include <vector>
using namespace std;

// recursive function to reverse an array from l to r
void reverseArrayRec(vector<int> &arr, int l, int r) {
    if(l >= r)
        return;
  
    // Swap the elements at the ends
    swap(arr[l], arr[r]);
  
    // Recur for the remaining array
    reverseArrayRec(arr, l + 1, r - 1);
}

// function to reverse an array
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    reverseArrayRec(arr, 0, n - 1);
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Iterate over the first half and for every index i,
    // swap arr[i] with arr[n - i - 1]
    for(int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}


void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Temporary array to store elements in reversed order
    vector<int> temp(n);
  
    // Copy elements from original array to temp in reverse order
    for(int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];
  
    // Copy elements back to original array
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int i = 0;
        int j = arr.size() -1;
        while(j>i){
            swap(arr[j--],arr[i++]);
        }
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

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends