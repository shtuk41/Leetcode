
#include <iostream>	
#include <string>
#include <map>

using namespace std;

class Solution {
    
    map<char, char> dictionary;

    bool valueExits(char val)
    {
        for (const auto& pair : dictionary) {
            if (pair.second == val) {
                return true;
            }
        }

        return false;
    }

public:
    bool isIsomorphic(string s, string t) {

        for (int ii = 0; ii < s.size(); ii++)
        {
            if (dictionary.find(s[ii]) != dictionary.end())
            {
                if (dictionary[s[ii]] == t[ii])
                    s[ii] = t[ii];
                else
                    return false;
            }
            else if (valueExits(t[ii]))
            {
                return false;
            }
            else
            {
                dictionary[s[ii]] = t[ii];
                s[ii] = t[ii];
            }
        }

        if (s == t)
            return true;
        else
            return false;
    }
};

void test(string s, string t)
{
    Solution sol;
    bool result = sol.isIsomorphic(s, t);
    std::cout << result << std::endl;

}

int main()
{
    Solution sol1;

    string s1 = "egg";
    string t1 = "add";

    test(s1, t1);

    string s2 = "foo";
    string t2 = "bar";

    test(s2, t2);

    string s3 = "paper";
    string t3 = "title";

    test(s3, t3);

    string s4 = "badc";
    string t4 = "baba";

    test(s4, t4);

    return 0;

}
