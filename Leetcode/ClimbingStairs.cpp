#include <iostream>

class Solution {
public:
    int climbStairs(int n) {

        //dp[1] = 1
        //dp[2] = 2
        //dp[i] = dp[i - 1] + dp[i - 2]

        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        int dp1 = 1;
        int dp2 = 2;
        int dp3;

        for (int ii = 2; ii < n; ii++)
        {
            dp3 = dp2 + dp1;
            dp1 = dp2;
            dp2 = dp3;
        }

        return dp3;
    }
};

void test(int n)
{
    Solution sol;
    int number = sol.climbStairs(n);
    std::cout << n << " -> " << number << std::endl;
}

int main()
{
    test(5);
}