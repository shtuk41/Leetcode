#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        stack<string> words;

        bool start = false;

        string word;

        int count = 0;

        for (int ii = 0; ii < s.length(); ii++)
        {
            char c = s[ii];

            if (c != ' ')
            {
                word += c;
                start = true;
            }
            else if (start)
            {
                if (count > 0)
                    words.push(" ");

                words.push(word);
                start = false;
                word = "";
                count++;
            }
        }

        if (word.length() > 0)
        {
            if (count > 0)
                words.push(" ");

            words.push(word);
        }

        string finalString = "";
        
        while (!words.empty())
        {
            finalString += words.top();
            words.pop();
        }

        return finalString;
    }
};

int main()
{
    Solution sol;

    string str1 = "the sky is blue";
    string result = sol.reverseWords(str1);
    std::cout << result << std::endl;

    string str2 = "  hello world  ";
    result = sol.reverseWords(str2);
    std::cout << result << std::endl;

    string str3 = "a good   example";
    result = sol.reverseWords(str3);
    std::cout << result << std::endl;


}

