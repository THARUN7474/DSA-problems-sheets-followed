#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int k = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[k-1]* nums[k-2] * nums[k-3], nums[0]*nums[1]*nums[k-1]);
    }
};


class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int first_max = INT_MIN ;
        int second_max = INT_MIN ;
        int third_max = INT_MIN ;

        int first_min = INT_MAX ;
        int second_min = INT_MAX ;

        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if( nums[i] < first_min )
            {
                second_min = first_min ;
                first_min = nums[i] ;
            }
            else if( nums[i] < second_min )
                second_min = nums[i] ;
            if( nums[i] > first_max )
            {
                third_max = second_max ;
                second_max = first_max ;
                first_max = nums[i] ;
            }
            else if( nums[i] > second_max )
            {
                third_max = second_max ;
                second_max = nums[i] ;
            }
            else if( nums[i] > third_max )
                third_max = nums[i] ;
        }
        return max ( first_max * second_max * third_max , first_min * second_min * first_max );
    }
};

// Complexity
// Time complexity: O(n), where n is the size of the input array. We iterate through the array once.
// Space complexity: O(1), as we use only a constant amount of extra space regardless of the size of the input array.
