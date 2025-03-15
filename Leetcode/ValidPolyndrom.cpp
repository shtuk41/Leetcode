#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        if (s.length() == 1)
            return true;

        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });

        s.erase(std::remove_if(s.begin(), s.end(),
            [](auto const& c) -> bool { return !std::isalnum(c); }), s.end());

        if (s.length() < 2)
            return true;


        auto b = s.begin();
        auto e = std::prev(s.end());

        int steps = s.length() / 2 + int(s.length() % 2 == 1);

        for (int ii = 0; ii < steps; ii++)
        {
            if (*b != *e)
                return false;

            b++;
            e--;
        }

        return true;
    }
};

int main()
{
    string test = "aa";

    Solution solution;

    bool yes = solution.isPalindrome(test);

    std::cout << yes << std::endl;


}