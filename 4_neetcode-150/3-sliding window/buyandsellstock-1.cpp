#include <bits/stdc++.h>

using namespace std;

// brute force approach we just check all the pairs of buy and sell prices and find the max profit
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                int sell = prices[j];
                res = max(res, sell - buy);
            }
        }
        return res;
    }
};

// 2 pointer approach
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1; // here l --> last buy price, r --> current sell price --and l is poisiton of our buying stock
        int maxP = 0;     // over all maxm profit we can make

        while (r < prices.size())
        { // iterate through the prices
            if (prices[l] < prices[r])
            {                                       // if we can make profit by selling at r
                int profit = prices[r] - prices[l]; // how much it is
                maxP = max(maxP, profit);           // we compare to update the overall max profit
            }
            else
            { // else we cannot make profit so we update the buy price to current price so that later we mght have better chances of making profit coz it is obviously better to buy at lower price , if we don get any day also , we have already stored so far maxm profit
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

// dp // we just keep track of the minimum price seen so far and calculate the profit at each step
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX; // to track minmimum price seen so far so that we can have better profits when we sell
        int maxProfit = 0;      // over all

        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice); // calculate profit at each step and we update as per max profit
        }
        return maxProfit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;
        int minBuy = prices[0];

        for (int &sell : prices)
        {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};