#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (k == 0)
            return;

        vector<int> newNumps;
        newNumps.resize(nums.size());

        vector<int>::iterator it = nums.begin();

        int pos = 0;

        while (it != nums.end())
        {
            int newPos = (pos + k) % nums.size();
            newNumps[newPos] = *it;
            pos++;
            it++;
        }

        nums = newNumps;
    }
};

int main()
{
    std::vector<int> input = { 1,2,3,4,5,6,7 };
    int k = 3;

    Solution sol;
    sol.rotate(input, k);

    for (auto ii : input)
    {
        std::cout << ii << std::endl;
    }


    return 0;
}



