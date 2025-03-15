#include <iostream>
#include <stack>
#include <string>


using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.length() == 1)
            return false;
        
        stack<char> parse;

        for (auto c : s)
        {
            if (!parse.empty() && 
                (c == '}' && parse.top() == '{' ||
                c == ']' && parse.top() == '[' ||
                c == ')' && parse.top() == '('))
            {
                 parse.pop();
            }
            else if (c == '{' || c == '[' || c == '(')
            {
                parse.push(c);
            }
            else
            {
                return false;
            }
        }

        return parse.empty();
    }
};

void test(string name, string s)
{
    Solution sol;
    bool isValid = sol.isValid(s);

    std::cout << name << " : " << isValid << std::endl;
}

int main()
{
    test("test1", "{}");
    test("test2", "()[]{}");
    test("test3", "(]");
    test("test4", "([])");
    test("test5", "((");
    test("test5", "){");

    return 0;
}

