#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &i: nums){
            if(m[i]>=(nums.size()/2)){
                return i;
            }
            m[i]++;
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};


// Algorithm:

// Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value.
// Iterate through the array nums:
// a. If count is 0, assign the current element as the new candidate and increment count by 1.
// b. If the current element is the same as the candidate, increment count by 1.
// c. If the current element is different from the candidate, decrement count by 1.
// After the iteration, the candidate variable will hold the majority element.
// Explanation of Correctness:
// The algorithm works on the basis of the assumption that the majority element occurs more than n/2 times in the array. This assumption guarantees that even if the count is reset to 0 by other elements, the majority element will eventually regain the lead.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int ans = 0;
        for (int x :nums){
            if(i==0){
                ans = x;
            }
            if(x == ans){
                i++;
            }
            else{
                i--;
            }
        }
        return ans;
    }
};