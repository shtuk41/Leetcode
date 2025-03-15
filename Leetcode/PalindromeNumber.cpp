#include <iostream>
#include <string>

using namespace std;

class Solution2 {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;
        if (x >= 0 && x < 10)
            return true;

        string s = to_string(x);
        int j = s.length();

        for (int ii = 0; ii < j / 2; ii++)
        {
            if (s[ii] != s[j - ii - 1])
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;
        if (x >= 0 && x < 10)
            return true;

        int number = x;
        unsigned int newNumber = 0;

        while (number != 0)
        {
            newNumber *= 10;
            int rem = number % 10;
            newNumber += rem;
            number /= 10;
        }


        return unsigned int(x) == newNumber;
    }
};


void test(int x)
{
    Solution sol;
    bool result = sol.isPalindrome(x);

    std::cout << x  << ':' << result << std::endl;
}

int main()
{
    test(1234567899);
    test(121);
    test(-121);
    test(10);
    test(4224);
    test(4242);

    return 0;
}