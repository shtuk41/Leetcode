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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* first = nullptr;
        ListNode* current = nullptr;

        
        if (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                first = current = list1;
                list1 = list1->next;

            }
            else
            {
                first = current = list2;    
                list2 = list2->next;
            }
        }
        else if (list1)
        {
            first = current = list1;
            list1 = list1->next;
        }
        else if (list2)
        {
            first = current = list2;
            list2 = list2->next;
        }

        while (list1 || list2)
        {
            if (list1 && list2)
            {
                if (list1->val <= list2->val)
                {
                    current->next = list1;
                    current = current->next;
                    list1 = list1->next;

                }
                else
                {
                    current->next = list2;
                    current = current->next;
                    list2 = list2->next;
                }
            }
            else if (list1)
            {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
            }
            else if (list2)
            {
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }

        return first;
    }
};

ListNode* createLL(vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;

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
    ListNode* result = sol.mergeTwoLists(createLL(v1), createLL(v2));

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
    test("test1", vector<int>({ 1,2,4 }), vector<int>({ 1,3,4 }));
    test("test2", vector<int>({ }), vector<int>({  }));
    test("test2", vector<int>({ }), vector<int>({ 0 }));

    return 0;
}