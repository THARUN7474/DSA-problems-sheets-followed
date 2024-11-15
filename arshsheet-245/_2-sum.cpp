#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = target - nums[i];
            if (mp.find(a) != mp.end())
            {
                return {mp[a], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int num : result)
        cout << num << " ";
    return 0;
}