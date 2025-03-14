// C++ Program to left rotate the array by d positions
// by rotating one element at a time

#include <bits/stdc++.h>
using namespace std;

// Function to left rotate array by d positions
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
      
        // Left rotate the array by one position
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}


// C++ Program to left rotate the array by d positions
// using temporary array

#include <bits/stdc++.h>
using namespace std;

// Function to rotate vector
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();

    // Handle case when d > n
    d %= n;
  
    // Storing rotated version of array
    vector<int> temp(n);

    // Copy last n - d elements to the front of temp
    for (int i = 0; i < n - d; i++)
        temp[i] = arr[d + i];

    // Copy the first d elements to the back of temp
    for (int i = 0; i < d; i++)
        temp[n - d + i] = arr[i];

    // Copying the elements of temp in arr
    // to get the final rotated vector
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    // Print the rotated vector
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}


// C++ Code to left rotate an array using Reversal Algorithm

#include <bits/stdc++.h>

using namespace std;

// Function to rotate an array by d elements to the left
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    // Handle the case where d > size of array
    d %= n;
  
    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());
  
    // Reverse the entire array
    reverse(arr.begin(), arr.end());


    // orelse 
    // int n = arr.size();
    //     d = d%n;
    //     reverse(arr.begin(),arr.begin()+d);
    //     reverse(arr.begin(),arr.end());
    //     reverse(arr.begin(),arr.begin()+n-d);
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;
    
      rotateArr(arr, d);
  
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


// [Expected Approach 1] Using Juggling Algorithm - O(n) Time and O(1) Space
// The idea is to use Juggling Algorithm which is based on rotating elements in cycles. Each cycle is independent and represents a group of elements that will shift among themselves during the rotation. If the starting index of a cycle is i, then next elements of the cycle can be found at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n ... and so on till we return to the original index i.

// So for any index i, we know that after rotation, the element that will occupy this position is arr[(i + d) % n]. Consequently, for every index in the cycle, we will place the element that should be in that position after the rotation is completed.

// Please refer Juggling Algorithm for Array Rotation to know more about the implementation.

// Time Complexity: O(n)
// Auxiliary Space: O(1) 

// [Expected Approach 2] Using Reversal Algorithm - O(n) Time and O(1) Space
// The idea is based on the observation that if we left rotate the array by d positions, the last (n - d) elements will be at the front and the first d elements will be at the end.

// Reverse the subarray containing the first d elements of the array.
// Reverse the subarray containing the last (n - d) elements of the array.
// Finally, reverse all the elements of the array.