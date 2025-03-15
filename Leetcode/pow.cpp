#include <iostream>

class Solution2 {
public:
    double myPow(double x, int n) {

        if (n == 0)
            return 1.0;
        else if (n == 1)
            return x;
        else if (n == -1)
            return 1.0 / x;
        else if (x == 1.0)
            return 1.0;
        else if (x == -1)
        {
            if (n % 2 == 0)
                return 1.0;
            else
                return -1.0;
        }

        double result = x;

        if (n % 2 == 0)
        {


            for (int ii = 1; ii < abs(static_cast<long long int>(n) / 2); ii++)
            {
                result *= x;
            }

            result *= result;
        }
        else
        {
            for (int ii = 1; ii < abs((static_cast<long long int>(n) - 1) / 2); ii++)
            {
                result *= x;
            }

            result *= result;
            result *= x;
        }

        if (n < 0)
            return 1.0 / result;
        else
            return result;
    }
};

//this is chatgpt version
class Solution {
public:
    double myPow(double x, int n) {

        long long exp = n; // Convert n to long long to prevent INT_MIN issues
        if (exp < 0) {
            x = 1 / x;   // Invert x for negative exponent
            exp = -exp;  // Convert exponent to positive
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1)  // If exponent is odd, multiply result by x
                result *= x;
            x *= x;   // Square the base
            exp /= 2; // Reduce exponent by half
        }

        return result;
    }
};


void test(double x, int n)
{
    Solution sol;
    double result = sol.myPow(x, n);
    std::cout << result << std::endl;
}

int main()
{
    //test(2, 10);
    //test(2.1, 3);
    //test(2, -2);
    //test(2, -2147483648);
    //test(-1, -2147483648);
    test(34.00515, -3);
}