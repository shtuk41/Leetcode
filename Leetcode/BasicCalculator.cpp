#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Calculator {

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

class Solution2 {

    string getNumber(string input, int &index)
    {
        string number;
        
        number += input[index++];

        while (isdigit(input[index]))
        {
            number += input[index];
            index++;
        }

        return number;
    }

    int findLastIndex(string input, int index)
    {
        index++;
        int count = 0;

        while (index < input.length())
        {
            if (input[index] == ')' && count == 0)
                return index;
            else if (input[index] == '(')
                count++;
            else if (input[index] == ')')
                count--;

            index++;
        }

        return index;
    }

    int calc(string input)
    {
        vector<string> ops;

        string operand;
        string operatorToken;
        int ii = 0;

        while (ii < input.length())
        {
             if (input[ii] == '+' || input[ii] == '-' && !operand.empty() || input[ii] == '*' || input[ii] == '/')
             {
                 operatorToken = input[ii];
             }
            else if (isdigit(input[ii]) || (ii + 1 < input.length()) && input[ii] == '-' && isdigit(input[ii + 1]))
            {
                operand = getNumber(input, ii);
                ops.push_back(operand);
                if (!operatorToken.empty())
                {
                    ops.push_back(operatorToken);
                    operatorToken = "";
                }

                continue;
            }
            else if (input[ii] == '-')
            {
                 ops.push_back("0");
                 operatorToken = "-";

            }
            else if (input[ii] == '(')
            {
                int lastIndex = findLastIndex(input, ii);
                string toParse = input.substr(ii + 1, lastIndex - ii - 1);
                operand = to_string(calc(toParse));
                ops.push_back(operand);
                if (!operatorToken.empty())
                {
                    ops.push_back(operatorToken);
                    operatorToken = "";
                }

                ii = lastIndex;
            }

            ii++;
        }

        Calculator calc;
        int result = calc.evalRPN(ops);
        return result;
    }
public:
    int calculate(string s) {

        int result = calc(s);

        return result;
    }
};

class Solution3 {

 
    string getNumber(string input, int& index)
    {
        string number;

        number += input[index++];

        while (isdigit(input[index]))
        {
            number += input[index];
            index++;
        }

        index--;

        return number;
    }

    int calc(string& s, int& start)
    {
        int index = start;
        int result = 0;
        char opcode = ' ';

        while (index < s.length())
        {
            if (s[index] == '+' || s[index] == '-')
            {
                opcode = s[index];
            }
            else if (isdigit(s[index]) || (index + 1 < s.length()) && s[index] == '-' && isdigit(s[index + 1]))
            {
                int number = stoi(getNumber(s, index));

                if (opcode == '+')
                    result += number;
                else if (opcode == '-')
                    result -= number;
                else
                    result = number;
            }
            else if (s[index] == '(')
            {
                index++;
                int number = calc(s, index);
                
                if (opcode == '+')
                    result += number;
                else if (opcode == '-')
                    result -= number;
                else
                    result = number;
             }
            else if (s[index] == ')')
            {
                break;
            }

            index++;
        }

        start = index;

        return result;
    }

public:
    int calculate(string s) {

        int start = 0;
        int result = calc(s, start);

        return result;
    }
};

class Solution {
    stack<int> numbers;
    stack<char> operators;

    int calc(string& s)
    {
        int index = 0;
        int result = 0;
        char opcode = ' ';
        char* ptr = &s[0];
        int length = s.length();

        while (index < length)
        {
            if (*ptr == '+' || *ptr == '-')
            {
                opcode = *ptr;
            }
            else if (*ptr == '(')
            {
                numbers.push(result);
                operators.push(opcode);

                result = 0;
                opcode = ' ';
            }
            else if (*ptr == ')')
            {
                opcode = operators.top();

                if (opcode == '+')
                    result = numbers.top() + result;
                else if (opcode == '-')
                    result = numbers.top() - result;

                operators.pop();
                numbers.pop();
            }
            else if (isdigit(*ptr) || (index + 1 < length) && *ptr == '-' && isdigit(*(ptr + 1)))
            {
                int number = 0;
                int mult = 1;

                if (*ptr == '-')
                {
                    mult = -1;
                }
                else
                {
                    number = (int)*ptr - 48;
                }

                ptr++;
                index++;

                while (int(*ptr) >= 48 && int(*ptr) <= 57)
                {
                    number = number * 10 + (int(*ptr) - 48);
                    index++;
                    ptr++;
                }

                index--;
                ptr--;

                if (opcode == '+')
                    result += number;
                else if (opcode == '-')
                    result -= number;
                else
                    result = number;
            }

            index++;
            ptr++;
        }

        return result;
    }

public:
    int calculate(string s) {

        int result = calc(s);

        return result;
    }
};

void test(string name, string s)
{
    Solution sol;
    int result = sol.calculate(s);

    std::cout << name << " : " << result << std::endl;
}

int main()
{
    test("test1", "1 + 1");
    test("test2", " 2-1 + 2 ");
    test("test3", "(1+(4+5+2)-3)+(6+8)");
    test("test4", "1-(     -2)");
    test("test5", "- (3 + (4 + 5))");
}
