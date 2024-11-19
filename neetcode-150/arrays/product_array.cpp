#include<bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/


class Solution {
public://not works for all cases as ---there could be a chance of same numbers repeatedly
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        for(int i : nums){
            int a = 1;
            for(int j : nums){
                if(j != i){
                    a = a * j;
                }
            }
            v.push_back(a);
        }
        return v;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    prod *= nums[j];
                }
            }
            res[i] = prod;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCount = 0;
        for (int num : nums) {
            if (num != 0) {
                prod *= num;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0); 
        }

        vector<int> res(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                res[i] = (nums[i] == 0) ? prod : 0;
            } else {
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};


/*

    Time Complexity : O(N^2), Where N is the size of the Array(nums). Here Two nested loop creates the time 
    complexity.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

*/

// https://leetcode.com/problems/product-of-array-except-self/solutions/3186745/best-c-3-solution-dp-space-optimization-brute-force-optimize-one-stop-solution
/***************************************** Approach 1 *****************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};






/*

    Time Complexity : O(N), As we iterate the Array(nums) thrice. Where N = size of the array.

    Space complexity : O(N), Array(left_Product and right_Product) space. 

    Solved using Dynamic Programming Approach(tabulation).

*/


/***************************************** Approach 2 *****************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};






/*

    Time Complexity : O(N), As we iterate the Array(nums) twice. Where N = size of the array.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.

*/


/***************************************** Approach 3 *****************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};