#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int ii = 1; ii <= amount; ii++)
        {
            for (int jj = 0; jj < coins.size(); jj++)
            {
                int diff = ii - coins[jj];
                if (diff >= 0 && dp[diff] != INT_MAX)
                {
                    dp[ii] =  min(dp[ii], dp[diff] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

void test(vector<int> coins, int amount)
{

    Solution sol;
    int answer = sol.coinChange(coins, amount);

    std::cout << answer << std::endl;
}

int main()
{
    test({1,2,5}, 11);
    test({2}, 3);
    test({1}, 0);
    test({ 1 }, 2);
}

