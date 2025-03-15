#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> result;

        if (nums.size() == 0)
        {
            return result;
        }

        int first = nums[0];
        int prev = first;

        vector<int>::iterator it = next(nums.begin());

        for (; it != nums.end(); ++it)
        {
            if (*it - 1 == prev)
                prev = *it;
            else
            {
                if (first == prev)
                {
                    result.push_back(std::to_string(first));
                    
                }
                else
                {
                    result.push_back(std::to_string(first) + "->" + std::to_string(prev));
                }

                prev = first = *it;
            }
        }

        if (first == prev)
        {
            result.push_back(std::to_string(first));

        }
        else
        {
            result.push_back(std::to_string(first) + "->" + std::to_string(prev));
        }

        return result;
    }
};

void test(string name, vector<int>& num)
{
    Solution sol;

    vector<string> result = sol.summaryRanges(num);

    std::cout << name << "\n";

    for (string& ii : result)
    {
        std::cout << ii << std::endl;
    }

    std::cout << '\n';


}

int main()
{
    vector<int> num1 = { 0,1,2,4,5,7 };
    test("test1", num1);

    vector<int> num2 = { 0,2,3,4,6,8,9 };
    test("test2", num2);

    vector<int> num3 = { 1, 2, 0, 1 };
    test("test3", num3);


    return 0;
}
