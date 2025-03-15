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
        ListNode* partition(ListNode* head, int x) {

            if (!head || !head->next)
            {
                return head;
            }

            vector<ListNode*> largeNodes;

            ListNode* newHead = nullptr;
            ListNode* node = nullptr;
            ListNode* travel = head;

            while (travel != nullptr)
            {
                if (travel->val < x)
                {
                    if (newHead == nullptr)
                    {
                        newHead = travel;
                        node = newHead;
                    }
                    else
                    {
                        node->next = travel;
                        node = travel;
                    }
                }
                else
                {
                    largeNodes.push_back(travel);
                }

                travel = travel->next;
            }

            for (auto travel : largeNodes)
            {
                if (newHead == nullptr)
                {
                    newHead = travel;
                    node = newHead;
                }
                else
                {
                    node->next = travel;
                    node = travel;
                }
            }

            if (node != nullptr)
                node->next = nullptr;


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
    ListNode* newHead = sol.partition(head, k);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << ',';
        newHead = newHead->next;
    }

    std::cout << "\n\n";
}

int main()
{
    test({ 1,4,3,2,5,2 }, 3);
    test({ 2,1 }, 2);
    test({ 2 }, 1);
    test({ 2 }, 3);
    test({  }, 3);

    return 0;
}