#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {

        if (s.length() == 1)
            return 1;

        int length = 0;
        bool startCount = false;

        for (int ii = s.length() - 1; ii >= 0; ii--)
        {
            if (s[ii] != ' ')
            {
                length++;
                startCount = true;
            }
            else if (startCount)
            {
                break;
            }
        }

        return length;
    }
  
};

int main()
{
    //5
    string sentence1 = "Hello World";
    //4
    string sentence2 = "   fly me   to   the moon  ";
    //6
    string sentence3 = "luffy is still joyboy";

    Solution sol;
    int length = sol.lengthOfLastWord(sentence1);
    std::cout << length << '\n';

    length = sol.lengthOfLastWord(sentence2);
    std::cout << length << '\n';

    length = sol.lengthOfLastWord(sentence3);
    std::cout << length << '\n';
    
}