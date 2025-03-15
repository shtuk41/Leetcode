#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];

        unordered_map<int, int> counter;

        for (auto ii : nums)
        {
            counter[ii] += 1;
        }

        for (auto ii : counter)
        {
            if (ii.second == 1)
                return ii.first;
        }

        return -1;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int twos = 0, ones = 0;

        for (auto ii : nums)
        {
            twos |= ii & ones;
            ones ^= ii;
            int common_mask = ~(ones & twos);
            ones &= common_mask;
            twos &= common_mask;
        }

        return ones;
    }
};


void test(vector<int> nums)
{
    Solution sol;
    int result = sol.singleNumber(nums);

    std::cout << result << std::endl;
}

int main()
{
    test({ 2,2,3,2 });
    test({ 0,1,0,1,0,1,99 });
    test({ 1 });

    return 0;
}