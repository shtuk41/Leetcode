#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        set<multiset<int>> resultSet;

        if (nums.size() == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
                result.push_back(nums);
            
            return result;
        }

        int p1 = 0;
        int p2 = 1;
        int p3 = 2;

        for (int p3 = 2; p3 != nums.size(); p3++)
        {
            for (int p2 = 1; p2 != p3; p2++)
            {
                for (int p1 = 0; p1 != p2; p1++)
                {
                    if (nums[p1] + nums[p2] + nums[p3] == 0)
                    {
                        resultSet.insert({ nums[p1], nums[p2], nums[p3] });
                    }
                }
            }
        }

        for (const auto& ms : resultSet) {
            std::vector<int> newV(ms.begin(), ms.end());
            result.push_back(newV);
        }

        return result;

    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        set<vector<int>> resultSet;

        if (nums.size() == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
                result.push_back(nums);

            return result;
        }

        sort(nums.begin(), nums.end());

        if (nums[nums.size() - 1] < 0)
            return result;

        if (nums[0] == 0 && *prev(nums.end()) == 0 ||
            nums[nums.size() - 1] == 0 &&
            nums[nums.size() - 2] == 0 &&
            nums[nums.size() - 3] == 0)
        {
            result.push_back(vector<int>({ 0,0,0 }));
            return result;
        }

        int p1 = 0;
        int p2 = 1;
        int p3 = nums.size() - 1;

        while (p3 >= 2 && nums[p3] == nums[p3 - 1])
            p3--;

        for (; p3 >= 2; p3--)
        {
            while (p1 < p2 && nums[p2] == nums[p2 + 1])
                p2--;


            int p1 = 0;
            int p2 = p3 - 1;

            int sumCheck = nums[0] + nums[1] + nums[p3];

            if (sumCheck > 0)
            {
                continue;
            }

            while (p1 < p2)
            {
                int sum = nums[p1] + nums[p2] + nums[p3];

                if (sum == 0)
                {
                    resultSet.insert({ nums[p1], nums[p2], nums[p3] });
                    p1++;
                    p2--;

                    while (p1 < p2 && nums[p1] == nums[p1 - 1])
                        p1++;

                    while (p1 < p2 && nums[p2] == nums[p2 + 1])
                        p2--;


                }
                else if (sum > 0)
                    p2--;
                else
                    p1++;
            }
        }

        result.assign(resultSet.begin(), resultSet.end());

        return result;

    }
};





void print(vector<vector<int>>& nums)
{
    for (auto ii : nums)
    {
        for (auto jj : ii)
        {
            std::cout << jj << ';';
        }

        std::cout << '\n';
    }
    std::cout << '\n';
}

int main()
{
    Solution sol;

    vector<int> nums = { -1,0,1,2,-1,-4 };

    vector<vector<int>> result = sol.threeSum(nums);
    print(result);

    vector<int> nums2 = { 0,0,0 };

    result = sol.threeSum(nums2);
    print(result);

    vector<int> nums3 = { 0,0,0,0,0, };

    result = sol.threeSum(nums3);
    print(result);

    return 0;
}