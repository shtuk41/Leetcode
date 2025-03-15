
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_set<int> memory;

public:
    bool isHappy(int n) {
        
        int count = 0;

        while (memory.find(n) == memory.end())
        {
           int total = 0;

           int num = n;

           while (num > 9)
           {
               int v = num % 10;

               total += v * v;
               num = num / 10;
           }

           total += num * num;

            if (total == 1)
                return true;
            else if (total == 0)
                return false;
            else
                memory.insert(n);

            n = total;
        }

        return false;
    }
};

void test(string name, int n)
{
    Solution sol;
    bool result = sol.isHappy(n);

    std::cout << name << " is " << result << std::endl;
}

int main()
{
    test("test1", 19);
    test("test2", 2);
    test("test3", 1111111);
    return 0;
}

