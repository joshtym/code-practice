/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^4

*/

#include <vector>
#include <iostream>

int maxProfitBrute(std::vector<int>& prices) {
  int maxProfit = 0;
  
  for (int i = 0; i < prices.size() - 1; ++i)
    for (int j = i + 1; j < prices.size(); ++j)
      maxProfit = std::max(maxProfit, prices[j] - prices[i]);

  return maxProfit;
}

int maxProfitSmart(std::vector<int>& prices) {
  int currBuyPrice = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] < currBuyPrice)
      currBuyPrice = prices[i];

    maxProfit = std::max(maxProfit, prices[i] - currBuyPrice);
  }

  return maxProfit;
}

int main(int argc, char** argv) {
  std::vector<int> prices;

  for (int i = 1; i < argc; ++i)
    prices.push_back(std::stoi(argv[i]));

  std::cout << maxProfitSmart(prices) << std::endl;

  return 0;
}