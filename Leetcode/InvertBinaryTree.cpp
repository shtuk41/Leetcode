#include <iostream>
#include <vector>
#include <stack>

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
public:
	TreeNode* invertTree(TreeNode* root) {

		if (!root)
			return root;

		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (node->left || node->right)
			{
				swap(node->left, node->right);
				if (node->left)
					st.push(node->left);
				if (node->right)
					st.push(node->right);
			}
		}

		return root;
	}
};

void test(vector<TreeNode*> tree)
{
	Solution sol;
	TreeNode* newTree;
	if (tree.size() == 0)
		newTree = sol.invertTree(nullptr);
	else if (tree.size() == 1)
	{
		newTree = sol.invertTree(tree[0]);
	}
	else
	{
		for (int ii = 0; ii < tree.size(); ii++)
		{
			int index = ii + 1;

			if (tree[ii] != nullptr)
			{
				int leftIndex = index * 2 - 1;
				int rightIndex = index * 2;

				tree[ii]->left = leftIndex < tree.size() ? tree[leftIndex] : nullptr;
				tree[ii]->right = rightIndex < tree.size() ? tree[rightIndex] : nullptr;
			}
		}

		newTree = sol.invertTree(tree[0]);
	}

	stack<TreeNode*> st;
	st.push(newTree);

	while (!st.empty())
	{
		TreeNode* node = st.top();
		st.pop();

		if (node != nullptr)
			cout << node->val << ',';
		else
			continue;

		if (node->left)
			st.push(node->left);
		if (node->right)
			st.push(node->right);
	}

	if (!tree.empty())
	{
		for (auto ii : tree)
		{
			delete ii;
		}
	}
}

int main()
{
	test({ new TreeNode(4), new TreeNode(2), new TreeNode(7), new TreeNode(1),new TreeNode(3),new TreeNode(6),new TreeNode(9)});

	

	return 0;
}