#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                newStr += tolower(c);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};



class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(j>i && !isalnum(s[j])){
                j--;
            }
            // cout<<s[i]<<"ff"<<s[j]<<endl;
            if(tolower(s[i++])!=tolower(s[j--])){
                return false;
            }
        }
        return true;

    }
};
