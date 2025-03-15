
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        if (nums.size() == 1)
        {
            if (nums[0] >= target)
                return 1;
            else
                return 0;
        }

        int length = 0;
        int total = 0;

        for (int ii = 0; ii < nums.size(); ii++)
        {
            total += nums[ii];

            length += 1;

            if (total >= target)
                break;
        }

        if (total < target)
            return 0;

        int start = 1;
        int resultLength = length;

        for (; start < nums.size(); start++)
        {
            total -= nums[start - 1];

            if (start + length - 1 < nums.size())
                total += nums[start + length - 1];
            else
                length--;

            while (total - nums[start + length - 1] >= target)
            {
                total -= nums[start + length - 1];
                length--;
            } 

            if (total >= target && length < resultLength)
                resultLength = length;
        }

        return resultLength;
    }
};

int main()
{
    Solution sol;
    vector<int> test1 = { 2,3,1,2,4,3 };
    int length = sol.minSubArrayLen(7, test1);
    std::cout << length << std::endl;

    vector<int> test2 = { 12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12 };
    length = sol.minSubArrayLen(213, test2);
    std::cout << length << std::endl;



}