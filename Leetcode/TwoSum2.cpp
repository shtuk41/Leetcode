#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int p1 = 0;
        int p2 = numbers.size() - 1;

        while (p1 != p2)
        {
            int sum = numbers[p1] + numbers[p2];
            if (sum == target)
                break;
            else if (sum > target)
                p2--;
            else if (sum < target)
                p1++;
        }

        vector<int> result = { p1 + 1, p2 + 1 };

        return result;
    }
};

int main()
{
    Solution sol;

	vector<int> numbers = { 2,7,11,15 };
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target);
    std::cout << result[0] << ',' << result[1] << ',' << numbers[result[0] - 1] + numbers[result[1] - 1] << ',' << target << std::endl;

    numbers = { 2,3,4 };
    target = 6;
    result = sol.twoSum(numbers, target);
    std::cout << result[0] << ',' << result[1] << ',' << numbers[result[0] - 1] + numbers[result[1]- 1] << ',' << target << std::endl;

    numbers = { -1, 0 };
    target = -1;
    result = sol.twoSum(numbers, target);
    std::cout << result[0] << ',' << result[1] << ',' << numbers[result[0] - 1] + numbers[result[1] - 1] << ',' << target << std::endl;

    numbers = { 0, 0, 3, 4 };
    target = 0;
    result = sol.twoSum(numbers, target);
    std::cout << result[0] << ',' << result[1] << ',' << numbers[result[0] - 1] + numbers[result[1] - 1] << ',' << target << std::endl;

    numbers = { -3,3,4,90 };
    target = 0;
    result = sol.twoSum(numbers, target);
    std::cout << result[0] << ',' << result[1] << ',' << numbers[result[0] - 1] + numbers[result[1] - 1] << ',' << target << std::endl;
}