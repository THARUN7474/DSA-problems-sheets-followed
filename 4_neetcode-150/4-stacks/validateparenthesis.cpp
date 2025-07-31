#include<bits/stdc++.h>

using namespace std; 



// brute force approach --here we are belivong that atleast () or {} or [] will be there an uppon clearing that we will keep on getting and finaly storng will be empty if not it means we got invalid string 
// this approach is not optimal as it will take O(n^2) time complexity
// space complexity is O(n) as we are using string to store the result 
class Solution {
public:
    bool isValid(string s) {
        while(true){
            size_t pos = string::npos;
             if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            break;
        }
        return s.empty();
    }
};



class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {// not got closign but we got open bracket 
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {// checkign as we got clsoing means last input one must be same but open one so we check stack top (last ele that pushed to it)
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();       
    }
};


// simpler version of the above code using map to store the closing to opening brackets
// this is more readable and understandable
// stack is used to keep track of the opening brackets
// time complexity is O(n) and space complexity is O(n) --better optimization
// we are using stack to keep track of the opening brackets and we are using map to store the closing to opening brackets
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};