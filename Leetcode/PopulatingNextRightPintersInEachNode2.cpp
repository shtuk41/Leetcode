#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution2 {
public:
    Node* connect(Node* root) {

        if (root != nullptr)
        {
            Node* node = root;

            queue<Node*> level;
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);

            while (level.size() > 0)
            {
                Node* t = level.front();
                level.pop();

                queue<Node*> nextLevel;

                while (!level.empty())
                {
                    Node* nextPtr = level.front();
                    level.pop();
                    t->next = nextPtr;

                    if (t->left) nextLevel.push(t->left);
                    if (t->right) nextLevel.push(t->right);

                    t = nextPtr;
                }

                if (t->left) nextLevel.push(t->left);
                if (t->right) nextLevel.push(t->right);

                level = nextLevel;
            }

            return root;
        }

        return nullptr;
    }
};

class Solution {
public:
    Node* connect(Node* root) {

        if (root != nullptr)
        {
            Node* node = root;

            vector<Node*> level, nextLevel;
            if (node->left) level.push_back(node->left);
            if (node->right) level.push_back(node->right);

            bool avail = level.size() > 0;

            while (avail)
            {
                for (vector<Node*>::iterator ii = level.begin(); ii != level.end(); ++ii)
                {
                    if (next(ii) != level.end())
                        (*ii)->next = *next(ii);

                    if ((*ii)->left) nextLevel.push_back((*ii)->left);
                    if ((*ii)->right) nextLevel.push_back((*ii)->right);
                }

                avail = nextLevel.size() > 0;
                level = nextLevel;
                nextLevel.clear();
            }

            return root;
        }

        return nullptr;
    }
};

void test(vector<Node*> nodes)
{
    Solution sol;
    Node* result;
    
    if (nodes.size() == 0)
    {
        result = sol.connect(nullptr);
    }
    else
    {
        for (int ii = 0; ii < nodes.size(); ii++)
        {
            int index = ii + 1;

            if (nodes[ii] != nullptr)
            {
                int leftIndex = index * 2 - 1;
                int rightIndex = index * 2;

                nodes[ii]->left = leftIndex < nodes.size() ? nodes[leftIndex] : nullptr;
                nodes[ii]->right = rightIndex < nodes.size() ? nodes[rightIndex] : nullptr;
            }
        }

        result = sol.connect(nodes[0]);
    }

    if (result != nullptr)
    {
        stack<Node*> st;

        st.push(result);
        while (!st.empty())
        {
            Node* n = st.top();
            st.pop();

            std::cout << n->val << "->" << (n->next != nullptr ? n->next->val : -111111) << std::endl;

            if (n->left) st.push(n->left);
            if (n->right) st.push(n->right);
        }
    }
}

int main()
{
    test({ new Node(1), new Node(2), new Node(3), new Node(4), new Node(5), nullptr, new Node(7)});
    //test({ nullptr });

    return 0;
}
