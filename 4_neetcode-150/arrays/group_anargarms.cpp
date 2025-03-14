#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/group-anagrams/description/


class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // unordered_map<unordered_map<char,int>,vector<string>> mp;--incorrect syntax --learned this today
        unordered_map<string, vector<string>> mp;

        for (auto s : strs)
        {
            // unordered_map<char, int> countS;
            // for (int i = 0; i < s.length(); i++)
            // {
            //     countS[s[i]]++;
            // }
            // mp[countS].append(s)
            string ss = s;
            sort(ss.begin(), ss.end());
            mp[ss].push_back(s);
        }
        vector<vector<string>> v;
        for (auto &i : mp)
        {
            v.push_back(i.second);
        }
        return v;
    }
};
// here time complexity is O(M*nlog(n))


//here we reduced time complexity by using char array instead of  sorting the string which takes  nlogn TC but now it is only n 
// now total time complexity is O(m * n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
