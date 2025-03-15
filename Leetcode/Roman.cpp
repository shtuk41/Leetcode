#include <iostream>
#include <string>

using namespace std;

class Solution {

    int convert(char first, char second)
    {

        if (first == 'I' && second == 'V')
            return 4;
        else if (first == 'I' && second == 'X')
            return 9;
        else if (first == 'I')
            return 1;
        else if (first == 'X' && second == 'L')
             return 40;
        else if (first == 'X' && second == 'C')
             return 90;
        else if (first == 'X')
             return 10;
        else if (first == 'C' && second == 'D')
             return 400;
        else if (first == 'C' && second == 'M')
             return 900;
        else if (first == 'C')
              return 100;
        else if (first == 'V')
            return 5;
        else if (first == 'L')
            return 50;
        else if (first == 'D')
            return 500;
        else if (first == 'M')
            return 1000;

        return 0;

    }

public:
    int romanToInt(string s) 
    {
        int number = 0;

        if (s.length() == 1)
        {
            number = convert(s[0], '\0');
            return number;
        }
        else
        {
            for (int ii = 1; ii < s.length(); ii++)
            {
                int result = convert(s[ii - 1], s[ii]);
                number += result;
                
                if (result == 4 || result == 9 || result == 40 || result == 90 || result == 400 || result == 900)
                    ii++;

                if (ii == s.length() - 1)
                {
                    result = convert(s[ii], '\0');
                    number += result;
                    return number;
                }

            }

            return number;
        }
    }
};

int main()
{
    string case1 = "III"; //3
    string case2 = "LVIII"; //58
    string case3 = "MCMXCIV"; //1994
    string case4 = "IX"; //9
    string case5 = "MI"; //1001

    Solution sol;
    int result = sol.romanToInt(case1);

    std::cout << result << std::endl;

    result = sol.romanToInt(case2);

    std::cout << result << std::endl;

    result = sol.romanToInt(case3);

    std::cout << result << std::endl;

    result = sol.romanToInt(case4);

    std::cout << result << std::endl;

    result = sol.romanToInt(case5);

    std::cout << result << std::endl;
}