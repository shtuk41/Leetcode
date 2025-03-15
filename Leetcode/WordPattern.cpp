
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

class Solution {

    map<char, string> dictionary;

    bool valueExists(string str)
    {
        for (auto pair : dictionary)
        {
            if (pair.second == str)
                return true;
        }

        return false;
    }

public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
            return false;

        for (int ii = 0; ii < pattern.length(); ii++)
        {
            if (dictionary.find(pattern[ii]) != dictionary.end())
            {
                if (dictionary[pattern[ii]] != words[ii])
                    return false;
            }
            else if (valueExists(words[ii]))
            {
                return false;
            }
            else
            {
                dictionary[pattern[ii]] = words[ii];
            }
        }

        return true;
    }
};

void test(string pattern, string s)
{
    Solution sol;
    bool result = sol.wordPattern(pattern, s);
    std::cout << result << std::endl;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";

    test(pattern, s);

    pattern = "abba";
    s = "dog cat cat fish";

    test(pattern, s);

    pattern = "aaaa";
    s = "dog cat cat dog";

    test(pattern, s);

    pattern = "aaa";
    s = "aa aa aa aa";

    test(pattern, s);
}