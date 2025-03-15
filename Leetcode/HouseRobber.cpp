#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int dp2 = nums[1];
        int dp1 = nums[0];
        int dp3;

        for (int ii = 2; ii < nums.size(); ii++)
        {
            dp3 = max(dp2, dp1 + nums[ii]);

            dp1 = max(dp1, dp2);
            dp2 = dp3;
        }

        return dp3;

    }
};

void test(vector<int> nums)
{
    Solution sol;
    int number = sol.rob(nums);
    std::cout<< number << std::endl;
}

int main()
{
    test({1,2,3,1});
    test({2,7,9,3,1});
    test({2,1,1,2});
}