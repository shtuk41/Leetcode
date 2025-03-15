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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || k == 0)
            return head;

        ListNode* newHead = head;
        ListNode* travel = head;

        int count = 0;

        while (travel->next != nullptr)
        {
            travel = travel->next;
            count++;
        }

        count++;
        
        int nodeNumber = count -  k % count;

        travel->next = head;
        travel = head;
        count = 0;

        while (travel != nullptr)
        {
            ListNode* prev = travel;
            travel = travel->next;
           

            if (count == nodeNumber - 1)
            {
                prev->next = nullptr;
                newHead = travel;
                break;
            }

            count++;
        }

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
    ListNode* newHead = sol.rotateRight(head, k);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }

    std::cout << "\n\n";
}

int main()
{
    test({ 1,2 }, 1);
    test({ 1,2,3,4,5 }, 5);
    test({ 1,2,3,4,5 }, 2);
    test({ 0,1,2 }, 4);

    return 0;
}