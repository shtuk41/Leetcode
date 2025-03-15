#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    unordered_map<Node*, int> oldNodeIndex;
    unordered_map<int , Node*> newNodeIndex;

public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        Node* node = new Node(head->val);
        Node* newHead = node;
        newNodeIndex.insert({ 0, node });

        oldNodeIndex.insert({ head, 0 });

        int count = 1;
        Node* headT = head->next;

        while (headT != nullptr)
        {
            Node* next = new Node(headT->val);
            oldNodeIndex.insert({ headT, count});
            newNodeIndex.insert({ count, next });
            node->next = next;
            node = next;
            headT = headT->next;
            count++;
        }

        Node* travel = head;
        Node* travelNew = newHead;

        while (travel != nullptr)
        {
            if (travel->random == nullptr)
                travelNew->random = nullptr;
            else
            {
                int idx = oldNodeIndex[travel->random];
                travelNew->random = newNodeIndex[idx];
            }

            travel = travel->next;
            travelNew = travelNew->next;
        }

        return newHead;
    }
};

Node* createTestLL(vector<pair<int, int>> input)
{
    unordered_map<int, Node*> nodeNumberAddress;

    Node* node = new Node(input[0].first);
    Node* head = node;

    nodeNumberAddress.insert({ 0, node });

    int count = 1;

    for (auto ii = input.begin() + 1; ii < input.end(); ++ii)
    {
        Node*next = new Node(ii->first);
        nodeNumberAddress.insert({ count, next });
        node->next = next;
        node = next;
        count++;
    }

    Node* travel = head;

    for (int ii = 0; ii < input.size(); ii++)
    {
        if (input[ii].second < 0)
            travel->random = nullptr;
        else
        {
            travel->random = nodeNumberAddress[input[ii].second];
        }

        travel = travel->next;
    }

    return head;
}

void test(vector<pair<int, int>> input)
{
    Node* oldHead = createTestLL(input);

    Solution sol;
    Node* newHead = sol.copyRandomList(oldHead);

    while (newHead != nullptr)
    {
        std::cout << newHead->val << std::endl;
        newHead = newHead->next;
    }

    std::cout << std::endl;
}

int main()
{
    test(vector<pair<int, int>>({ {7, -1}, {13,0}, {11,4}, {10,2}, {1, 0} }));
    test(vector<pair<int, int>>({ {1, 1}, {2, 1} }));
    test(vector<pair<int, int>>({ {3, -1}, {3, 0}, {3, -1} }));
    
    return 0;
}
