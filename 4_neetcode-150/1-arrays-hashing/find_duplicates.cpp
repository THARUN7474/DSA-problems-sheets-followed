#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/contains-duplicate/

// my solution
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        for (auto i : nums)
        {
            if (mp[i] > 1)
            {
                return true;
            }
        }
        return false;
    }

    // we can use ---set ----> set<int>(nums.begin(),nums.end()).size() < nums.size() then true --better use unordered_set<> coz of internal implementation
    //  we can use 2 loops---O(n^2) so it s not optimal

    // bool containsDuplicate(vector<int>& nums) {
    //     unordered_set<int> seen;
    // for (int num : nums) {
    //     if (seen.count(num)) {
    //         return true;  // Duplicate found
    //     }
    //     seen.insert(num);
    // }
    // return false;  // No duplicates
    // }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {

        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return true;                }
        //     }
        // }
        // return false;

        // unordered_map<int,int> v;
        // for(auto i: nums){
        //     v[i]++;
        // }
        // for(auto i : v){
        //     if(i.second != 1){
        //         return true;
        //     }
        // }
        // return false;

        unordered_map<int, int> v;
        for (auto i : nums)
        {
            if (v[i] == 1)
            {
                return true;
            }
            v[i]++;
        }
        return false;
    }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};


// using unordered_set solution it uses hashing internally which is O(1) time complexity for insert and search operations but it uses O(n) space complexity
// O(n) time complexity
// O(n) space complexity
// here we are creating an unordered_set from the vector and then checking if the size of the set is less than the size of the vector
// if it is then we have a duplicate element in the vector and we return true else we return false
// this is a very efficient way to check for duplicates in a vector but here we are creatign and checking so it is not optimal coz it will take O(n) time complexity to create the set and then O(1) time complexity to check the size of the set
class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;// same like map but only stores keys
         // unordered_set<int> seen; // same like map but only stores keys
         // unordered_set<int> seen(nums.begin(), nums.end()); // this is not optimal coz it will create a new set and then check size
         // we can use count() method to check if the element is present in the set or not
         // we can use insert() method to add elements to the set
        for (int num : nums)
        {
            if (seen.count(num))
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

//brute force solution
// O(n^2) time complexity
// O(1) space complexity

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};


// sorting solution
// O(n log n) time complexity
// O(1) space complexity (if we sort in place) like sorting algo like quicksort or heapsort which uses O(1) space complexity
// O(n) space complexity (if we use a new array to store the sorted elements) like in this case we are using sort() function which uses O(n) space complexity internally like quicksort or mergesort
// but it is not optimal coz it will take O(n log n) time complexity

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};


// using unordered_set solution it uses hashing internally which is O(1) time complexity for insert and search operations but it uses O(n) space complexity 
// O(n) time complexity
// O(n) space complexity

// here we are using unordered_set to store the elements of the array and then checking if the element is already present in the set or not
// if it is present then we return true else we insert the element in the set and continue the process until we reach the end of the array
// if we reach the end of the array and we have not found any duplicate element then we return false

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};