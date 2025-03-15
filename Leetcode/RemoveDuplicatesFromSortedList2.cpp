#include <iostream>
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
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else if (head->next->next == nullptr && 
            head->val == head->next->val)
        {
            return nullptr;
        }

        ListNode* lookahead = head->next->next;
        ListNode* follower = head->next;
        ListNode* tail = head;
        ListNode* newHead = nullptr;
        ListNode* node = nullptr;

        int count = 0;

        if (tail->val != follower->val)
        {
            newHead = tail;
            node = tail;
        }

        while (lookahead != nullptr)
        {
            if (lookahead->val != follower->val && 
                follower->val != tail->val)
            {
                if (!newHead)
                {
                    newHead = follower;
                    node = follower;
                }
                else
                {
                    node->next = follower;
                    node = follower;
                }
            }
            lookahead = lookahead->next;
            follower = follower->next;
            tail = tail->next;
        }

        if (follower->val != tail->val)
        {
            if (!newHead)
            {
                newHead = follower;
                node = follower;
            }
            else
            {
                node->next = follower;
                node = follower;
            }
        }

        if (node != nullptr)
            node->next = nullptr;
       
        return newHead;
    }
};

void test(vector<int> vec)
{
    ListNode* head = new ListNode(vec[0]);
    ListNode* node = head;

    for (vector<int>::iterator it = vec.begin() + 1; it != vec.end(); ++it)
    {
        node->next = new ListNode(*it);
        node = node->next;
    }

    Solution sol;
    ListNode* newHead = sol.deleteDuplicates(head);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }

    std::cout << "\n\n";
}

int main()
{
    test({ 1, 1, 1 });
    test({ 1,2,3,4,5 });
    test({ 1,2,3,3,4,4,5 });
    test({ 1,1,1,2,3 });
    test({ 1 });
    test({ 1, 2 });
    return 0;
}