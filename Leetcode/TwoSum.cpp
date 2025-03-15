#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    unordered_map<int, int> table;

public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for (int ii = 0; ii < nums.size(); ii++)
        {
            int diff = target - nums[ii];

            auto it = table.find(diff);

            if (it != table.end())
            {
                return {it->second, ii};
            }
            else
            {
                table[nums[ii]] = ii;
            }
        }

        return { -1, -1 };
    }
};

void test(string name, vector<int>& nums, int target)
{
    Solution sol;

    vector<int> result = sol.twoSum(nums, target);

    std::cout << name << std::endl;

    for (auto ii : result)
    {
        std::cout << ii << ' ';
    }

    std::cout << '\n';
}

int main()
{
    vector<int> nums1 = { 2,7,11,15 };
    test("test1", nums1, 9);

    vector<int> nums2 = { 3,2,4 };
    test("test2", nums2, 6);

    vector<int> nums3 = { 3,3 };
    test("test3", nums3, 6);
}



