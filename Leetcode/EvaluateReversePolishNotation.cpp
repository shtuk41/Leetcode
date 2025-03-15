#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {

    stack<int> ops;
public:
    int evalRPN(vector<string>& tokens) {

        for (auto t : tokens)
        {
            if (t.length() == 1 && (t == "+" || t == "-" || t == "*" || t == "/"))
            {

                int val2 = ops.top();
                ops.pop();
                int val1 = ops.top();
                ops.pop();
                int result;

                if (t == "+")
                {
                    result = val1 + val2;
                }
                else if (t == "-")
                {
                    result = val1 - val2;
                }
                else if (t == "*")
                {
                    result = val1 * val2;
                }
                else if (t == "/")
                {
                    result = val1 / val2;
                }
                ops.push(result);
            }
            else
            {
                ops.push(stoi(t));
            }
        }

        int result = ops.top();
        
        return result;

    }
};

void test(string name, vector<string>&tokens)
{
    Solution sol;
    int result = sol.evalRPN(tokens);

    std::cout << name << " : " << result << std::endl;
}

int main()
{
    vector<string> test1 = { "2", "1", "+", "3", "*" };
    test("test1", test1);

    vector<string> test2 = { "4", "13", "5", "/", "+" };
    test("test2", test2);

    vector<string> test3 = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    test("test3", test3);

    vector<string> test4 = { "10"};
    test("test4", test4);

    vector<string> test5 = { "4", "3", "-"};
    test("test5", test5);

}