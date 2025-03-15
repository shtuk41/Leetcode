#include <iostream>
#include <stack>
#include <limits>

using namespace std;

class MinStack {

    stack<pair<int, int>> minStack;
    int minimum;

public:
    MinStack() {
        minimum = INT_MAX;
    }

    void push(int val) {

        if (val < minimum)
            minimum = val;

        minStack.push({ val, minimum });
    }

    void pop() {

        if (!minStack.empty())
            minStack.pop();

        if (minStack.empty())
            minimum = INT_MAX;
        else
        {
            minimum = minStack.top().second;
        }
    }

    int top() {
        return minStack.top().first;
    }

    int getMin() {
        return minimum;
    }
};

void test1()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << minStack.top() << std::endl;
    std::cout << minStack.getMin() << std::endl;
}

int main()
{
    test1();
}
