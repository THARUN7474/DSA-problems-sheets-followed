#include<bits/stdc++.h>

using namespace std;


// https://leetcode.com/problems/two-sum/

//my solution
// O(n^2) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            int a = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == a && i != j){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

vector<int> twoSum(vector<int>& nums, int target);

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

// 2 pointer solution
// O(n^2) time complexity
// O(1) space complexity
// HERE WE ARE JUST COMPARING  the sum of the two elements at the two pointers and if it is equal to the target then we return the indices of the two elements like all possible pairs --brute force solution , if it is 3sum we cant do brute force coz it will take O(n^3) time complexity 

// here we are using two pointers to find the two elements that sum up to the target
// 0 1 , 0 2, 0 3, 0 4,then 
// 1 2, 1 3, 1 4, then
// 2 3, 2 4, then
// 3 4, then
// so total pairs are n(n-1)/2 = O(n^2) time complexity

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


// sorting and two pointer solution
// O(n log n) time complexity
// O(1) space complexity
// here we are sorting the array and then using two pointers to find the two elements that sum  up to the target
// we are using a vector of pairs to store the original indices of the elements after sorting 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = A[i].first + A[j].first;
            if (cur == target) {
                return {min(A[i].second, A[j].second), 
                        max(A[i].second, A[j].second)};
            } else if (cur < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

// 1 pass solution
// O(n) time complexity
// O(n) space complexity
// here we are using a hash map to store the indices of the elements in the array
// in a single pass we are checking if the difference between the target and the current element is present in the hash map or not
// if it is present then we return the indices of the two elements --both chekcing and inserting in the map is O(1) time complexity
// so total time complexity is O(n) and space complexity is O(n) coz we are and we are doign both at the same time 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prevMap; 

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (prevMap.find(diff) != prevMap.end()) {
                return {prevMap[diff], i};
            }
            prevMap.insert({nums[i], i});
        }
        return {};
    }
};


//2 pass solution
// O(n) time complexity
// O(n) space complexity
// here we are using a hash map to store the indices of the elements in the array
// in the first pass we are storing the indices of the elements in the hash map and in the second pass we are checking if the difference between the target and the current element is present in the hash map or not
// if it is present then we return the indices of the two elements 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;  // val -> index

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};