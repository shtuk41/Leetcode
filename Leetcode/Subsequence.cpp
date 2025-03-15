#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (t.empty() && s.empty())
            return true;
        else if (t.empty())
            return false;
        else if (s.empty())
            return true;

        int si = 0;
        int ti = 0;

        while (si < s.length() && ti < t.length())
        {
            if (s[si] == t[ti++])
            {
                si++;
            }
        }

        if (si == s.length())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;

    string s = "aaaaaa";
    string t = "bbaaaa";

    bool isSubsuequence = sol.isSubsequence(s, t);

    std::cout << isSubsuequence << std::endl;

    return 0;


}