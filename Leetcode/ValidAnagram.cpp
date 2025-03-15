#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution1 {

    map<char, int> dictionary;

public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        for (auto ch : s)
        {
            dictionary[ch] += 1;
        }

        for (auto ch : t)
        {
            auto it = dictionary.find(ch);
            if (it != dictionary.end())
            {
                if (it->second <= 0)
                    return false;

                it->second--;
            }
            else
                return false;
        }

        return true;
    }
};

class Solution {

    int map[256] = { 0 };

public:
    bool isAnagram(string s, string t) {

        int map[256] = { 0 };

        if (s.length() != t.length())
            return false;

        if (s == "" && t == "")
            return true;

        std::sort(s.begin(), s.end());

        std::sort(t.begin(), t.end());

        return s == t;
    }
};

void test(string s, string t)
{
    Solution sol;
    bool result = sol.isAnagram(s, t);
    std::cout << result << std::endl;
}

int main()
{
    test("anagram", "nagaram");
    test("rat", "car");

    return 0;
}