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
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;

		stack<TreeNode*> st;
		st.push(root);

		int result = 0;

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			result++;

			if (node->left)
			{
				st.push(node->left);
			}

			if (node->right)
			{
				st.push(node->right);
			}
		}

		return result;
	}
};

void test(vector<TreeNode*> tree)
{
	Solution sol;
	int result;

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

	result = sol.countNodes(tree[0]);

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
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3), new TreeNode(4), new TreeNode(5), new TreeNode(6) });
	test({ new TreeNode(1)});
	test({ nullptr });
	return 0;
}