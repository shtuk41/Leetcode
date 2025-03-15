#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
    int indexPreorder;
    unordered_map<int, int> inorderMap;

    void assign(int L1, int L2, int R1, int R2, TreeNode* node, vector<int>& preo, vector<int>& inor)
    {
        if (indexPreorder >= inor.size())
            return;

        bool found = inorderMap.find(preo[indexPreorder]) != inorderMap.end();

        if (found)
        {
            int indexL = inorderMap[preo[indexPreorder]];

            if (indexL >= L1 && indexL <= L2)
            {
                node->left = new TreeNode(inor[indexL]);

                indexPreorder += 1;

                if (indexL != L1 || indexL != L2)
                {

                    assign(L1, indexL, indexL + 1, L2, node->left, preo, inor);
                }
            }
        }

        if (indexPreorder >= inor.size())
            return;


        if (found)
        {
            int indexR = inorderMap[preo[indexPreorder]];

            if (indexR >= R1 && indexR <= R2)
            {
                node->right = new TreeNode(inor[indexR]);

                indexPreorder += 1;

                if (indexR != R1 || indexR != R2)
                {

                    assign(R1, indexR, indexR + 1, R2, node->right, preo, inor);
                }
            }
        }
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int ii = 0; ii < inorder.size(); ii++)
            inorderMap[inorder[ii]] = ii;

        indexPreorder = 0;

        TreeNode* tree = new TreeNode(preorder[indexPreorder]);

        int pivot = tree->val;

        indexPreorder += 1;
        int idx = inorderMap[pivot];
        assign(0, idx, idx + 1, inorder.size(), tree, preorder, inorder);

        return tree;

    }
};

void test(vector<int> preorder, vector<int> inorder)
{
    Solution sol;
    TreeNode* tree = sol.buildTree(preorder, inorder);

    if (!tree)
        return;

    stack<TreeNode*> st;

    st.push(tree);

    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();

        std::cout << node->val << ',';

        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }

    std::cout << std::endl;
}

int main()
{
    test({ 3,9,20,15,7 }, { 9,3,15,20,7 });
    test({ -1 }, { -1 });
    test({ 3, 4, 5, 10, 11, 6, 12, 7, 8, 9 }, { 10, 5, 11, 4, 12, 6, 3, 8, 7, 9 });

    return 0;
}