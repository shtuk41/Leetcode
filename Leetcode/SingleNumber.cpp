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

        if (nums.size() == 1)
            return nums[0];

        int result = 0;

        for (auto ii : nums)
        {
            result ^= ii;
        }

        return result;
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
    test({ 2,2,1 });
    test({ 4,1,2,1,2 });
    test({1});

    return 0;
}