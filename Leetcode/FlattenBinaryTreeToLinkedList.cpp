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
	void flatten(TreeNode* root) {
		
		if (!root)
			return;

		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (node->right)
			{
				st.push(node->right);
			}
			if (node->left)
			{
				st.push(node->left);
			}

			if (!st.empty())
			{
				node->right = st.top();
				node->left = nullptr;
			}
		}
	}
};

void test(vector<TreeNode*> tree)
{
	Solution sol;
	if (tree.size() == 0)
		sol.flatten(nullptr);
	else if (tree.size() == 1)
	{
		sol.flatten(tree[0]);
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

		sol.flatten(tree[0]);
	}

	TreeNode* node = tree[0];

	while (node)
	{
		std::cout << node->val << ",";
		node = node->right;
	}

	std::cout << '\n';


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
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(5), new TreeNode(3), new TreeNode(4), nullptr, new TreeNode(6) });
	test({ nullptr });
	test({ new TreeNode(0)});
	return 0;
}