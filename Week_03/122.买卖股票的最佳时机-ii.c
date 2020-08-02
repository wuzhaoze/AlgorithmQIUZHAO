/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i-1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}


// @lc code=end

