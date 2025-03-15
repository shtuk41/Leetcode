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
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<ListNode*> mem;
        mem.reserve(5000);
        ListNode* travelOld = head;

        while (travelOld != nullptr)
        {
            mem.push_back(travelOld);
            travelOld = travelOld->next;
        }

        if (mem.size() < k || mem.size() == 1)
            return head;

        int count = 0;

        ListNode* newHead = mem[k - 1];
        ListNode* travel = newHead;
        bool first = true;

        while (mem.size() - count >= k)
        {
            count += k;
            for (int ii = count - 1; ii >= count - k; ii--)
            {
                if (first)
                {
                    first = false;
                    continue;
                }

                travel->next = mem[ii];
                travel = travel->next;
            }
        }

        while (count < mem.size())
        {
            travel->next = mem[count];
            travel = travel->next;
            count++;
        }

        travel->next = nullptr;

        return newHead;

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
    ListNode* newHead = sol.reverseKGroup(head, k);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }

    std::cout << "\n\n";
}

int main()
{
    test({1,2,3,4,5}, 2);
    test({1,2,3,4,5}, 3);
    test({ 1 }, 1);
    test({ 1, 2 }, 2);
    return 0;
}