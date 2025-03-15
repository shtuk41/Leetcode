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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        vector<ListNode*> mem;
        ListNode* travelOld = head;

        

        while (travelOld != nullptr)
        {
            mem.push_back(travelOld);
            travelOld = travelOld->next;
        }

        if (mem.size() == 1)
            return nullptr;
        else if (mem.size() == n)
            return head->next;
        else
        {
            int indexToRemoe = mem.size() - n;
            mem[indexToRemoe - 1]->next = mem[indexToRemoe]->next;
        }

        return head;
    }
};

void test(vector<int> vec, int k)
{
    ListNode* head = new ListNode(vec[0]);
    ListNode* node = head;

    for (vector<int>::iterator it = vec.begin() + 1; it != vec.end(); ++it)
    {
        node->next = new ListNode(*it);
        node = node->next;
    }

    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(head, k);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }

    std::cout << "\n\n";
}

int main()
{
    test({ 1,2,3,4,5 }, 2);
    test({ 1 }, 1);
    test({ 1, 2 }, 1);
    return 0;
}