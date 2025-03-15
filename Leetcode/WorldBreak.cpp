#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> segments(s.length() + 1, false);
        segments[0] = true;

        for (int ii = 0; ii < s.length(); ii++)
        {
            for (int jj = 0; jj < segments.size(); jj++)
            {
                if (jj <= ii && segments[jj])
                {
                    string segment = s.substr(jj, ii - jj + 1);

                    if (words.find(segment) != words.end())
                    {
                        segments[ii + 1] = true;
                        break;
                    }

                }
            }
        }

        return segments[s.length()];
    }
};

void test(string s, vector<string> wordDict)
{
    Solution sol;
    bool itCan = sol.wordBreak(s, wordDict);

    std::cout << s << ":" << itCan << std::endl;

}

int main()
{
    test("leetcode", { "leet", "code" });
    test("applepenapple", { "apple", "pen" });
    test("catsandog", { "cats", "dog", "sand", "and", "cat" });
    test("a", { "a" });
}

