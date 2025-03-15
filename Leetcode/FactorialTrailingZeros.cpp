#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//solved with hint
class Solution {
public:
    int trailingZeroes(int n) {

        int numberOfZero = 0;

        while (n >= 5)
        {
            numberOfZero += n / 5;
            n /= 5;
        }

        return numberOfZero;
    }
};


void test(int n)
{
    Solution sol;
    int result = sol.trailingZeroes(n);

    std::cout << n << " : " << result << std::endl;
}

int main()
{
    test(200);
    test(40);
    test(4);
    test(5);
    test(0);

    return 0;
}