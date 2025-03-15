#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution2 {
public:
    int rangeBitwiseAnd(int left, int right) {

        int result = left;

        int ii = left;

        for (;ii < right; ii++)
        {
            result &= ii;

            if (result == 0)
                return 0;
        }

        return result & right;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        int k = 0;

        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            k++;
        }

        return left <<= k;

    }
};


void test(int left, int right)
{
    Solution sol;
    int result = sol.rangeBitwiseAnd(left, right);

    std::cout << result << std::endl;
}

int main()
{
    test(5,7);
    test(0,0);
    test(1, 2147483647);
    test(1073741832, 2147483647);

    return 0;
}