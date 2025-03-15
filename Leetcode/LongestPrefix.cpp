#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for (auto s : strs)
        {
            if (s.length() == 0)
                return "";
        }

        string lastMatch;

        for (int ii = 0; ii < strs[0].length(); ii++)
        {
            char toFind = strs[0][ii];

            for (int jj = 1; jj < strs.size(); jj++)
            {
                if (strs[jj].length() - 1 < ii || strs[jj][ii] != toFind)
                {
                    return lastMatch;
                }
            }

            lastMatch += toFind;
        }

        return lastMatch;
    }
};

int main()
{
    vector<string> case1 = { "flower", "flow", "flight" };
    vector<string> case2 = { "dog", "racecar", "car" };

    Solution sol;
    string prefix = sol.longestCommonPrefix(case1);

    std::cout << "Prefix \"" << prefix << "\"\n";

    prefix = sol.longestCommonPrefix(case2);

    std::cout << "Prefix \"" << prefix << "\"\n";


}

