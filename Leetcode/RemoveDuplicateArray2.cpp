#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        vector<int>::iterator testIt = nums.begin();
        vector<int>::iterator updateIt = nums.begin();

        testIt++;
        int count = 1;
        int memCount = 1;

        while (testIt != nums.end())
        {
            if (*testIt == *updateIt)
            {
                if (memCount < 2)
                {
                    updateIt++;
                    *updateIt = *testIt;
                    testIt++;
                    memCount++;
                    count++;
                }
                else
                {
                    testIt++;
                }
            }
            else
            {
                updateIt++;
                *updateIt = *testIt;
                testIt++;
                memCount = 1;
                count++;
            }
        }

        return count;
    }
};

int main()
{
    std::vector<int> input = { 1,1,1,2,2,3 };

    Solution sol;
    int numLeft = sol.removeDuplicates(input);

    std::cout << numLeft << std::endl;

    int count = 0;

    for (auto ii : input)
    {
        std::cout << ii << std::endl;
        count++;
        
        if (count >= numLeft)
            break;
    }


    return 0;
}



