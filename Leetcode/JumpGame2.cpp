#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int index = nums.size() - 1;
        int candidateIndex = index;
        int goal = index;
        bool goalReached = false;
        int steps = 0;


        while (index > 0)
        {
            while (candidateIndex > 0)
            {
                if (nums[--candidateIndex] + candidateIndex >= goal)
                {
                    index = candidateIndex;
                }
            }

            goal = index;
            candidateIndex = index;

            steps++;

        }

        return steps;

    }
};

int main()
{
    std::vector<int> input = { 2,3,0,1,4 };

    Solution sol;
    int steps = sol.jump(input);

    std::cout << steps << std::endl;

    return 0;
}



