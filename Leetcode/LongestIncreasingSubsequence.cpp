#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//this is brilliant implementation provided by "Donald Knuth"
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // stores the smallest tail for increasing subsequences

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num); // find the position

            if (it == tails.end()) {
                tails.push_back(num); // num extends the largest subsequence
            }
            else {
                *it = num; // replace with smaller value to maintain optimal subsequence
            }
        }

        return tails.size(); // the length of the longest subsequence
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);

        for (int ii = 0; ii < nums.size(); ii++)
        {
            for (int jj = 0; jj < ii; jj++)
            {
                if (nums[jj] < nums[ii])
                    dp[ii] = max(dp[ii], dp[jj] + 1);
            }
        }

        int mvalue = *max_element(dp.begin(), dp.end());

        return mvalue;
    }
};

void test(vector<int> nums)
{

    Solution sol;
    int answer = sol.lengthOfLIS(nums);

    std::cout << answer << std::endl;
}

int main()
{
    test({ 10,9,2,5,3,7,101,18 });
    test({ 0,1,0,3,2,3 });
    test({ 7,7,7,7,7,7,7 });
}

