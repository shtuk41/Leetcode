#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left;
        vector<int> right;
        vector<int> output;

        left.resize(nums.size());
        right.resize(nums.size());
        output.resize(nums.size());

        int size = nums.size();

        left[0] = nums[0];
        right[nums.size() - 1] = nums[nums.size() - 1];

        for (int ii = 1; ii < nums.size() - 1; ii++)
        {
            left[ii] = left[ii - 1] * nums[ii];
            right[size - 1 - ii] = right[size - ii] * nums[size - 1 - ii];
        }

        output[0] = right[1];
        output[size - 1] = left[size - 2];

        for (int ii = 1; ii < nums.size() - 1; ii++)
        {
            output[ii] = left[ii - 1] * right[ii + 1];
        }

        return output; 
    }
};

int main()
{
    std::vector<int> nums = { 1,2,3,4 };

    Solution sol;
    auto result = sol.productExceptSelf(nums);

    for (auto ii : result)
    {
        std::cout << ii << std::endl;
    }

    return 0;
}