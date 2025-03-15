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
    int indexPostorder;
    unordered_map<int, int> inorderMap;
   
    void assign(int L1, int L2, int R1, int R2, TreeNode* node, vector<int>& inor, vector<int>& post)
    {
        if (indexPostorder < 0)
            return;

        bool foundR = inorderMap.find(post[indexPostorder]) != inorderMap.end();
        

        if (foundR)
        {
            int indexR = inorderMap[post[indexPostorder]];

            if (indexR >= R1 && indexR <= R2)
            {
                node->right = new TreeNode(inor[indexR]);

                indexPostorder -= 1;

                if (indexR != R1 || indexR != R2)
                {

                    assign(R1, indexR, indexR + 1, R2, node->right, inor, post);
                }
            }
        }

        if (indexPostorder < 0)
            return;

        bool foundL = inorderMap.find(post[indexPostorder]) != inorderMap.end();
        


        if (foundL)
        {
            int indexL = inorderMap[post[indexPostorder]];

            if (indexL >= L1 && indexL <= L2)
            {
                node->left = new TreeNode(inor[indexL]);

                indexPostorder -= 1;

                if (indexL != L1 || indexL != L2)
                {

                    assign(L1, indexL, indexL + 1, L2, node->left, inor, post);
                }
            }
        }

    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int ii = 0; ii < inorder.size(); ii++)
        {
            inorderMap[inorder[ii]] = ii;
        }

        indexPostorder = postorder.size() - 1;

        TreeNode* tree = new TreeNode(postorder[indexPostorder]);

        int pivot = tree->val;

        indexPostorder -= 1;
        int ind = inorderMap[pivot];
        assign(0, ind, ind + 1, inorder.size(), tree, inorder, postorder);

        return tree;

    }
};

void test(vector<int> inorder, vector<int> postorder)
{
    Solution sol;
    TreeNode* tree = sol.buildTree(inorder, postorder);

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
    test({ 9,3,15,20,7 }, { 9,15,7,20,3 });
    test({ -1 }, { -1 });
    test({ 1,2 }, { 2,1 });

    return 0;
}