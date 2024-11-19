#include<bits/stdc++.h>

using namespace std;


// https://leetcode.com/problems/two-sum/

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