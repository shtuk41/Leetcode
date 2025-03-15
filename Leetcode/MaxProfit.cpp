#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 1)
            return 0;

        auto sellP = prices.begin();


        int totalProfit = 0;


        while (sellP != prices.end())
        {
            auto buy = sellP;
            auto sell = sellP + 1;

            int profit = 0;

            while (sell != prices.end())
            {
                if (*sell > *buy)
                {
                    int p = *sell - *buy;

                    if (p > profit)
                    {
                        profit = p;
                        sellP = sell + 1;
                    }
                }
                else
                {
                    buy = sell;
                }

                sell++;
            }

            if (profit == 0)
                break;

            totalProfit += profit;
        }

        return totalProfit;

    }
};
int main()
{
    std::vector<int> input = { 7,1,5,3,6,4 };

    Solution sol;
    int maxProfit = sol.maxProfit(input);

    std::cout << maxProfit << std::endl;

    return 0;
}



