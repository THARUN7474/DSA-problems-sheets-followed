#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string ss)
    {
        int s = 0;
        int e = ss.size() - 1;
        while (s <= e)
        { // just checking or comapring when we find the actuall char not spacs not other chars
            if (!isalnum(ss[s]))
            {
                s++;
                continue;
            }
            if (!isalnum(ss[e]))
            {
                e--;
                continue;
            }
            if (tolower(ss[s]) != tolower(ss[e]))
                return false;
            else
            {
                s++;
                e--;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newStr = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                newStr += tolower(c);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        { // here we kept only < so inside loop we can check for i and j i>j or i<j all those everytime
            while (i < j && !isalnum(s[i]))
            {
                i++;
            }
            while (j > i && !isalnum(s[j]))
            {
                j--;
            }
            // cout<<s[i]<<"ff"<<s[j]<<endl;
            if (tolower(s[i++]) != tolower(s[j--]))
            {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(string ss) {
        int s=0;
       int e=ss.size()-1;
       while(s<=e){
           if(!isalnum(ss[s])){s++; continue;}
           if(!isalnum(ss[e])){e--;continue;}
           if(tolower(ss[s++])!=tolower(ss[e--]))return false;
       }
       return true;
    }
};