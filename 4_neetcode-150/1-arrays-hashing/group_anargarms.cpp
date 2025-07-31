#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/group-anagrams/description/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs)
        {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end()); // its like unquie key but multiple qeries for that key
            res[sortedS].push_back(s);            // like all these users(like s) can access someting using common key SortedS
        } // O(n*nlog(n))--loop in that sorting of string so --so we can right our own tht unique key logic
        vector<vector<string>> r;
        for (auto &p : res)
        {
            r.push_back(p.second);
        }
        return r;
    }
};

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // unordered_map<unordered_map<char,int>,vector<string>> mp;--incorrect syntax --learned this today we cant use unordered_map as key and inside another unordered_map
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

// here we reduced time complexity by using char array instead of  sorting the string which takes  nlogn TC but now it is only n
//  now total time complexity is O(m * n)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs)
        {
            vector<int> count(26, 0);
            for (char c : s)
            {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i)
            {
                key += ',' + to_string(count[i]); // its like creating a unique key for each anagram group and using it to group them ---> 0,1,0,2,3,12,0,000000001....26char --string each char is represented by its count in the string but thing , is we can use any separator here like # or $ or anything else its for bypassing 2digit and 1 digit count problem
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto &pair : res)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
