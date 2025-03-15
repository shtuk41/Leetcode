#include <iostream>


class Solution {
public:
    int hammingWeight(int n) {

        int result = 0;

        for (int ii = 0; ii < 32; ii++)
        {
            result += ((n & (1 << ii)) >> ii);
        }

        return result;
    }
};

void test(int t)
{
    Solution sol;
    uint32_t result = sol.hammingWeight(t);

    std::cout << result << std::endl;
}

int main()
{
    test(0b00000000000000000000000000000011);
    test(0b00000010100101000001111010011100);
    test(0b11111111111111111111111111111101);
}