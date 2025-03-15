
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() < 2)
            return s.length();

        int mem[200] = { 0 };
        
        int start = 0;
        int end = 0;
        mem[(int)s[start]] = 1;
        int length = 1;
        int maxLength = 1;

        while (end + 1 < s.length())
        {
            end += 1;
            length += 1;

            while (mem[(int)s[end]] > 0)
            {
                mem[(int)s[start++]] = 0;
                length--;
            }

            mem[(int)s[end]] = 1;

            if (length > maxLength)
                maxLength = length;
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    string test1 = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(test1);

    std::cout << result << std::endl;

    string test2 = "bbbb";
    result = sol.lengthOfLongestSubstring(test2);

    std::cout << result << std::endl;

    return 0;
}
