#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

public:
    string minWindow(string s, string t) {

        if (s.length() < t.length())
            return string("");
        else if (s == t)
            return s;
           

        int tmap[256] = {0};

        for (auto ii : t)
        {
            tmap[ii] += 1;
        }

        int dynamicCounter = t.length();
        int start = 0;
        int end = 0;
        int minLength = 0;
        int startMem = 0;

        int smap[256] = { 0 };
        smap[s[end]] += 1;

        if (tmap[s[end]] > 0)
        {
            dynamicCounter--;
        }

        while (end < s.length())
        {
            std::cout << s.substr(start, end - start + 1) << std::endl;

            if (dynamicCounter == 0)
            {
                int length = end - start + 1;

                if (length < minLength || minLength == 0)
                {
                    minLength = length;
                    startMem = start;
                }
            }

            if (dynamicCounter == 0 && start < end)
            {
                if (smap[s[start]] <= tmap[s[start]])
                {
                    dynamicCounter++;
                }

                smap[s[start++]] -= 1;
            }
            else
            {
                end++;

                if (smap[s[end]] < tmap[s[end]]) 
                {
                    dynamicCounter--;
                }

                smap[s[end]]++;
            }
        }

        return s.substr(startMem, minLength);
    }
};

int main()
{
	Solution sol;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";

    string result1 = sol.minWindow(s1, t1);

    std::cout << "Result: " << result1 << std::endl;

    string s2 = "a";
    string t2 = "a";

    string result2 = sol.minWindow(s2, t2);

    std::cout << "Result: " << result2 << std::endl;

    string s3 = "a";
    string t3 = "b";

    string result3 = sol.minWindow(s3, t3);

    std::cout << "Result: " << result3 << std::endl;

    return 0;

}