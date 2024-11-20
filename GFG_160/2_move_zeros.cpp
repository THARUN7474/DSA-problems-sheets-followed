// C++ Program to move all zeros to end using two traversals

#include <bits/stdc++.h>
using namespace std;

// Function which pushes all zeros to end
void pushZerosToEnd(vector<int> &arr)
{

    // Count of non-zero elements
    int count = 0;

    // If the element is non-zero, replace the element at
    // index 'count' with this element and increment count
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    // Now all non-zero elements have been shifted to
    // the front. Make all elements 0 from count to end.
    while (count < arr.size())
        arr[count++] = 0;

    // void pushZerosToEnd(vector<int> & arr)
    // {
    //     stable_partition(arr.begin(), arr.end(), [](int n)
    //                      { return n != 0; });
    // }

    // Function which pushes all zeros to end of array
    // void pushZerosToEnd(vector<int> & arr)
    // {

    //     // Pointer to track the position for next non-zero element
    //     int count = 0;

    //     for (int i = 0; i < arr.size(); i++)
    //     {

    //         // If the current element is non-zero
    //         if (arr[i] != 0)
    //         {

    //             // Swap the current element with the 0 at index 'count'
    //             swap(arr[i], arr[count]);
    //             // Move 'count' pointer to the next position
    //             count++;
    //         }
    //     }
    // }
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}