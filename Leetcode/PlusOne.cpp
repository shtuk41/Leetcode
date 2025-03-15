#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<int> result;
        result.reserve(digits.size() + 1);

        int ii = digits.size() - 1;
        int rem = 1;

        while (ii >= 0)
        {
            int dig = digits[ii];
            result.push_back((dig + rem) % 10);
            rem = (dig + rem) / 10;
            ii--;
        }

        if (rem > 0)
            result.push_back(rem);

        std::reverse(result.begin(), result.end());

        return result;
    }
};


void test(vector<int> digits)
{
    Solution sol;
    vector<int> result = sol.plusOne(digits);

    for (auto ii : result)
    {
        std::cout << ii << ',';
    }

    std::cout << std::endl;
}

int main()
{
    test({1,2,3});
    test({ 4,3,2,1 });
    test({9});

    return 0;
}