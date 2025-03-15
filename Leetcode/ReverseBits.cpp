#include <iostream>


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t result = 0;

        for (int ii = 0; ii < 32; ii++)
        {
            unsigned int t1 = (n & (1 << ii));

            if (t1 > 0)
                result |= (t1 >> ii) << (31 - ii);
        }

        return result;

    }
};

void test(uint32_t t)
{
    Solution sol;
    uint32_t result = sol.reverseBits(t);

    std::cout << result << std::endl;

    uint32_t n = 1 << 31;

    for (int ii = 0; ii < 32; ii++)
    {
        std::cout << (((result & n) >> (31 - ii)) & 0x1);
        n >>= 1;
    }

    std::cout << std::endl;
}

int main()
{
    test(0b00000000000000000000000000000011);
    test(0b00000010100101000001111010011100);
    test(0b11111111111111111111111111111101);
}