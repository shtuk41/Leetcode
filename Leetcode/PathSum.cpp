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
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;

		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (node->left)
			{
				node->left->val += node->val;
				st.push(node->left);
			}

			if (node->right)
			{
				node->right->val += node->val;
				st.push(node->right);
			}

			if (node->left == nullptr && node->right == nullptr && node->val == targetSum)
			{
				return true;
			}
		}

		return false;
	}
};

void test(vector<TreeNode*> tree, int sum)
{
	Solution sol;
	bool result;
	if (tree.size() == 0)
		result = sol.hasPathSum(nullptr, sum);
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

		result = sol.hasPathSum(tree[0], sum);
	}

	std::cout << "Result: " << result << std::endl;

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
	test({ new TreeNode(5), new TreeNode(4), new TreeNode(8), new TreeNode(11), nullptr, new TreeNode(13), new TreeNode(4), new TreeNode(7), new TreeNode(2), nullptr, nullptr, new TreeNode(1) }, 22);
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3) }, 5);
	test({ nullptr }, 0);
	return 0;
}