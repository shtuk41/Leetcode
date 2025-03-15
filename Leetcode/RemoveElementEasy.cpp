#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        std::vector<int>::iterator it = nums.begin();

        int count = nums.size();


        while (it != nums.end())
        {
            if ((*it) == val)
            {
                count--;
                it = nums.erase(it);
            }
            else
            {
                it++;
            }
        }

        return count;
    }
};

int main()
{
    std::vector<int> input = { 3,2,2,3,2, 4, 3};

    Solution sol;
    int numLeft = sol.removeElement(input, 3);

    std::cout << numLeft << std::endl;


    return 0;
}



