#include <iostream>

//Newton's method
class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return 0;
        else if (x < 4)
            return 1;
        
        float  xF = x;
        float result = x;
        float oldResult = 0xffffffff;
        bool converged = false;
        const float delta = 0.1f;

        while (!converged)
        {
            result = (result + xF / result) / 2;

            if (fabs(oldResult - result) < delta)
            {
                int r = floor(result);
                if (r * r > x)
                    r = r - 1;

                return r;
            }

            oldResult = result;
        }
       
        return 0;
    }
};


void test(int x)
{
    Solution sol;

    int result = sol.mySqrt(x);

    std::cout << result << std::endl;
}

int main()
{
    test(4);
    test(8);
    test(2147483647);
    test(2147395599);
}