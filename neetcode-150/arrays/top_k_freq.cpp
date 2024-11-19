#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/description/ 

class Solution
{
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        vector<int> v;
        for (auto i : nums)
        {
            m[i]++;
        }
        // sort(m.begin(),m.end());
        vector<pair<int, int>> vv(m.begin(), m.end());
        sort(vv.begin(), vv.end(), cmp);

        // sort(vv.begin(),vv.end(),[](pair<int,int> &a,pair<int,int> &b){
        //     return a.second>b.second;
        // })

        // int n = k;
        for (auto i : vv)
        {
            if (k)
            {
                v.push_back(i.first);
                k--;
            }
        }
        return v;
    }
};

class Solution
{
public:
    // Making cmp a static function so it can be used directly in sort
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;

        // Count frequencies
        for (auto i : nums)
        {
            m[i]++;
        }

         // sort(m.begin(),m.end());--maps direcrtly cant sort cozz no indexing or perfect ordere so we convert them to vector

        // Move elements from map to a vector of pairs
        vector<pair<int, int>> vv(m.begin(), m.end());

        // Sort the vector by frequency in descending order
        sort(vv.begin(), vv.end(), cmp);

        // Alternatively, you could remove cmp entirely and use a lambda function
        sort(vv.begin(), vv.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });

        // Extract the top k elements
        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            v.push_back(vv[i].first);
        }

        return v;
    }
};


class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> v;
        for(auto i : nums){
            m[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;//min priority heap --as we used greater<pair<int,int>> it keeps minimum element at top 

        for(auto i : m){
            pq.push({i.second,i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop( );
        }

        return v;
    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        // Count the frequency of each element
        for (int n : nums) {
            count[n]++;
        }

        // Group elements by frequency
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        // Gather the top k frequent elements
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        
        return res;
    }
};
