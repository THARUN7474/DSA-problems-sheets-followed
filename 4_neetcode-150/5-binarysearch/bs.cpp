#include <bits/stdc++.h>

using namespace std;

// my solution using binary search

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            int m = i + (j - i) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
        return -1;
    }
};

// iterative solution using binary search
// time complexity is O(log n) and space complexity is O(1) as we are not using any extra space
// this is the most optimal solution for this problem
// for time complexity we can use daa method called "Master Theorem" to analyze the time complexity of divide and conquer algorithms like binary search like we divide the space into two halves and we solve the problem in each half recursively like 100-50-25-12.5-6.25 and so on and we can see that the time complexity is logarithmic in nature
// this is the basic idea of binary search --we are just checking the middle element and if it is equal to the target then we return the index of that element otherwise we check if the target is less than the middle element then we search in the left half of the array otherwise we search in the right half of the array
// this is the most efficient way to search in a sorted array

// so its like n -> n/2 -> n/4 -> n/8 and so on , using this n/2^k = 1 , so k = log(n) , so time complexity is O(log n)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + ((r - l) / 2); // better than (l + r) / 2 to avoid overflow of large numbers like INT_MAX or INT_MIN
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};

// recursive solution using binary search
// time complexity is O(log n) and space complexity is O(log n) as we are using recursion stack space
// this is the same idea as above but we are using recursion to implement the binary search 
class Solution
{

public:
    int binarySearch(vector<int> &nums, int target, int l, int r)
    {
        if (l > r)
            return -1; // base case when the range is invalid

        int m = l + (r - l) / 2; // to avoid overflow
        if (nums[m] == target)
        {
            return m;
        }
        else if (nums[m] < target)
        {
            return binarySearch(nums, target, m + 1, r);
        }
        else
        {
            return binarySearch(nums, target, l, m - 1);
        }
    }

    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
/// its like shiotign which part to check ---discarding the half of the array which is not needed to be checked
// this is the basic idea of binary search --- here using recursive function to implement the binary search we can use the same idea to solve other problems like finding the first or last occurrence of an element in a sorted array
// or finding the square root of a number or finding the peak element in an array etc. ---recurisive usefull for other med hard qns handy 


// upper bound solution using binary search
// this is used to find the index of the first element that is greater than the target 
//time complexity is O(log n) and space complexity is O(1) as we are not using any extra space
// this is useful when we want to find the index of the first element that is greater than the target or when we want to find the index of the first element that is greater than or equal to the target
// this is also known as lower bound in some languages like C++ STL and that is why we use the name upper_bound here
// we can use the same idea to find the index of the first element that is greater than
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (l > 0 && nums[l - 1] == target) ? l - 1 : -1;// return the index of the first element that is greater than the target or -1 if not found
    }
};


// lower bound solution using binary search 
// this is used to find the index of the first element that is greater than or equal to the target
// time complexity is O(log n) and space complexity is O(1) as we are not using any extra space
// this is useful when we want to find the index of the first element that is greater than or equal to the target
// we can use the same idea to find the index of the first element that is greater than
// this is also known as upper bound in some languages like C++ STL and that is why we use the name lower_bound here`

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (l < nums.size() && nums[l] == target) ? l : -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};

// this is a more concise way to implement the lower bound using C++ STL
// it uses the lower_bound function from the C++ STL which returns an iterator to the first element that is not less than the target
// if the element is found then we return the index of that element otherwise we return -1 


// this is a more concise way to implement the upper bound using C++ STL
// it uses the upper_bound function from the C++ STL which returns an iterator to the first
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(), nums.end(), target);
        return (it != nums.begin() && *(--it) == target) ? it - nums.begin() : -1;
    }
};


//binary search stl
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};