#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode();
        ListNode* r = result;

        int nval = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            r->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + nval;
            nval = r->val / 10;
            r->val = r->val % 10;

            if (nval > 0 || l1 != nullptr || l2 != nullptr)
            {
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;

                if (!l1 && !l2)
                {
                    if (nval > 0)
                    {
                        ListNode* np = new ListNode();
                        np->val = nval;
                        r->next = np;
                    }

                    break;
                }

                ListNode* np = new ListNode();
                r->next = np;
                r = np;
            }
        }

        return result;
    }
};

ListNode* createLL(vector<int>& v)
{
    ListNode* ln = new ListNode(v[0]);

    ListNode* next = ln;

    int index = 1;

    while (index < v.size())
    {
        ListNode* nn = new ListNode(v[index]);
        next->next = nn;
        next = nn;
        index++;
    }

    return ln;
}

void test(string name, vector<int> v1, vector<int> v2)
{
    Solution sol;
    ListNode* result = sol.addTwoNumbers(createLL(v1), createLL(v2));

    std::cout << name << " : [";

    while (result != nullptr)
    {
        std::cout << result->val << ',';
        result = result->next;
    }

    std::cout << "]\n";
}

int main()
{
    test("test1", vector<int>({ 2,4,3 }), vector<int>({ 5,6,4 }));
    test("test2", vector<int>({ 0 }), vector<int>({ 0 }));
    test("test2", vector<int>({ 9,9,9,9,9,9,9 }), vector<int>({ 9,9,9,9 }));

    return 0;
}