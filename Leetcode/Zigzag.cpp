#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;

        vector<string> rows(numRows);

        int ii = 0;

        while (true)
        {
            for (int jj = 0; jj < numRows - 1; jj++)
            {
                rows[jj] += s[ii++];
                
                if (ii >= s.length())
                    goto END;
            }

            for (int jj = numRows - 1; jj > 0; jj--)
            {
                rows[jj] += s[ii++];
                if (ii >= s.length())
                    goto END;

            }
        }

    END:

        string finalResult;

        for (auto ii : rows)
            finalResult += ii;

        return finalResult;
    }
};

int main()
{
    Solution sol;

    string str1 = "PAYPALISHIRING";
    int rows = 3;
    string result = sol.convert(str1, rows);
    std::cout << result << std::endl;

    string str2 = "PAYPALISHIRING";
    rows = 4;
    result = sol.convert(str2, rows);
    std::cout << result << std::endl;

    string str3 = "A";
    rows = 1;
    result = sol.convert(str3, rows);
    std::cout << result << std::endl;

    return 0;
}