#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/valid-anagram/description/


// here i used unordered_map to store the count of each character in the string and then checked if the count of each character in both strings is equal or not
// like in a 2 pass way  but with same unordered_map for both strings
// 1st loop i used to count the characters in the first string and 2nd loop i used to check if the characters in the second string are present in the first string or not
//then i checked if the count of each character in the unordered_map is equal to 0 or not
// if it is equal to 0 then we have an anagram else we don't have an anagram
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;

        for (auto i : s)
        {
            mp[i]++;
        }
        for (auto i : t)
        {
            if (mp[i] == 0)
            {
                return false;
            }
            mp[i]--;
        }
        for (auto i : mp)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 1. Sorting
// O(n log n) time complexity
// O(1) space complexity (if we sort in place) like sorting algo like quicksort or heapsort which uses O(1) space complexity
// O(n) space complexity (if we use a new array to store the sorted elements)
// we can compare stirngs after sorting them directly using == operator 

// O(nlog n + mlog m) time complexity
// O(n + m) space complexity
// where n is the length of the first string and m is the length of the second string  
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// Sorting/


// 2. Hash Table
// O(n + m) time complexity
// O(n + m) space complexity ---> but we can say it is O(1) as atmost only 26 unique characters can be present in the string 
// where n is the length of the first string and m is the length of the second string
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT; // so i can directly compare the two maps how? // because unordered_map has an overloaded operator== that compares the key-value pairs in the maps and returns true if they are equal and false otherwise // so this is a very efficient way to compare two maps in C ++ 
    }
};


//3. Hash Table (Optimal)
// O(n + m) time complexity
// O(1) space complexity ---> but we can say it is O(1) as atmost only 26 unique characters can be present in the string
// where n is the length of the first string and m is the length of the second string
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        vector<int> count(26, 0); // here 0 can become +ve or -ve if s has more of a character than t or vice versa
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count)
        {
            if (val != 0)
            {
                return false;
            }
        }
        return true;
    }
};


