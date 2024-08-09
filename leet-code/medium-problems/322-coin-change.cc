/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

 

Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 23^1 - 1
    0 <= amount <= 10^4

*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

struct CoinChange {
  int coins = 0;
  int total = 0;
  CoinChange() {}
  CoinChange(int c, int t): coins(c), total(t) {}
};

int coinChange(std::vector<int>& coins, int amount) {
  if (amount == 0)
    return 0;

  std::vector<int> coinsToValMap(amount + 1, amount + 1);
  coinsToValMap[0] = 0;

  for (int i  = 0; i < amount + 1; ++i) {
    for (int j = 0; j < coins.size(); ++j)
      if (i - coins[j] >= 0)
        coinsToValMap[i] = std::min(coinsToValMap[i], 1 + coinsToValMap[i - coins[j]]);
  }

  return coinsToValMap[amount] == amount + 1 ? -1 : coinsToValMap[amount];
}

int main(int argc, char** argv) {
  return 0;
}