#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {

        int m = max(a.length(), b.length()) + 1;

        string c;
        c.resize(m);

        int mem = 0;

        int acount = a.length() - 1;
        int bcount = b.length() - 1;
        int ccount = m - 1;

        while (acount >= 0 || bcount >= 0)
        {
            int an, bn;
           
             an = acount >= 0 ? a[acount] - '0' : 0;
             bn = bcount >= 0 ? b[bcount] - '0' : 0;

            int sum = an + bn + mem;
            mem = sum / 2;
            c[ccount] = sum % 2 + '0';

            acount--;
            bcount--;
            ccount--;
        }

        c[ccount] = mem + '0';

        c.erase(0, std::min(c.find_first_not_of('0'), c.size() - 1));
 

        return c;
    }
};



void test(string a, string b)
{
    Solution sol;
    string c = sol.addBinary(a, b);

    std::cout << c << std::endl;
}

int main()
{
    test("101111", "10");
    test("11", "1");
    test("1010", "1011");
    test("1", "10");
    test("0", "1");
    test("0", "0");
}

