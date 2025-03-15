#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    stack<ListNode*> mem;
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == 1 && left == right)
        {
            return head;
        }

        ListNode* newHead = head;
        ListNode* travel = head;
        ListNode* prev = nullptr;
        int count = 1;
        ListNode* cont;

        while (travel != nullptr)
        {
            if (count == left)
            {
                ListNode* n = travel;
                
                while (count <= right)
                {
                    mem.push(n);
                    n = n->next;
                    count++;
                }

                cont = mem.top()->next;

                if (prev == nullptr)
                {
                    newHead = mem.top();
                    travel = newHead;
                    mem.pop();
                }
                else
                {
                    travel = prev;
                }

                while (!mem.empty())
                {
                    auto nn = mem.top();
                    travel->next = nn;
                    travel = travel->next;
                    mem.pop();
                }

                travel->next = cont;

                if (travel != nullptr)
                    break;


                travel = travel->next;
                
            }
            prev = travel;
            travel = travel->next;
            count++;
        }

        return newHead;
    }
};

void test(vector<int> vec, int left, int right)
{
    ListNode* node = new ListNode(vec[0]);
    ListNode* head = node;

    for (auto ii = vec.begin() + 1; ii != vec.end(); ++ii)
    {
        ListNode* next = new ListNode(*ii);
        node->next = next;
        node = next;
    }

    Solution sol;
    ListNode* newHead = sol.reverseBetween(head, left, right);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }
    
    std::cout << '\n';
    std::cout << '\n';
}

int main()
{
    test({ 1,2,3,4,5 }, 2, 4);
    test({ 5 }, 1, 1);
    test({ 3, 5 }, 2, 2);
    test({ 3, 5 }, 1, 2);
}