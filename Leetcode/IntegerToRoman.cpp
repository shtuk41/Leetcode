#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        string finalResult = "";

        int thousand = num / 1000;

        for (int ii = 0; ii < thousand; ii++)
            finalResult += 'M';

        num -= thousand * 1000;

        int hundred = num / 100;

        if (hundred == 9)
        {
            finalResult += "CM";
        }
        else if (hundred == 4)
        {
            finalResult += "CD";
        }
        else 
        {
            int rem = hundred;
            if (hundred >= 5)
            {
                finalResult += 'D';
                rem -= 5;
            }

            for (int ii = 0; ii < rem; ii++)
                finalResult += "C";
        }

        num -= hundred * 100;

        int tenth = num / 10;

        if (tenth == 9)
        {
            finalResult += "XC";
        }
        else if (tenth == 4)
        {
            finalResult += "XL";
        }
        else
        {
            int rem = tenth;
            if (tenth >= 5)
            {
                finalResult += 'L';
                rem -= 5;
            }

            for (int ii = 0; ii < rem; ii++)
                finalResult += "X";
        }

        num -= tenth * 10;

        if (num == 9)
        {
            finalResult += "IX";
        }
        else if (num == 4)
        {
            finalResult += "IV";
        }
        else
        {
            int rem = num;
            if (num >= 5)
            {
                finalResult += 'V';
                rem -= 5;
            }

            for (int ii = 0; ii < rem; ii++)
                finalResult += "I";
        }

        return finalResult;
    }
};

int main()
{
    int case1 = 3749;
    
    Solution sol;
   
    string result = sol.intToRoman(case1);
    std::cout << result << std::endl;

    int case2 = 58;
    result = sol.intToRoman(case2);
    std::cout << result << std::endl;

    int case3 = 1994;
    result = sol.intToRoman(case3);
    std::cout << result << std::endl;

    return 0;
}