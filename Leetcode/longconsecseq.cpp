#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        set<int> mem;
        int size = nums.size();

        for (auto ii : nums)
            mem.insert(ii);

        int max_seq = 1;
        int count = 1;

        for (auto it = mem.begin(); it != std::prev(mem.end()); ++it)
        {
            int n = *next(it);
            if (*it + 1 == n)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > max_seq)
                max_seq = count;
        }

        return max_seq;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int count = 1;
        int max_seq = 1;
        
        for (auto it = nums.begin(); it != std::prev(nums.end()); ++it)
        {
            int n = *next(it);

            if (*it == n)
                continue;
            else if (*it + 1 == n)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > max_seq)
                max_seq = count;
        }

        return max_seq;
    }
};

void test(string name, vector<int>& num)
{
    Solution sol;

    int length = sol.longestConsecutive(num);

    std::cout << name << " : " << length << "\n";
}

int main()
{
    vector<int> num1 = { 100,4,200,1,3,2 };
    test("test1", num1);

    vector<int> num2 = { 0,3,7,2,5,8,4,6,0,1 };
    test("test2", num2);

    vector<int> num3 = {1, 2, 0, 1};
    test("test3", num3);


    return 0;
}
