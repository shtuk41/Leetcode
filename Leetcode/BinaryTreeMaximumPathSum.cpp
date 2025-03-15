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
	int maxPathSum(TreeNode* root) {

		int maxSum = INT_MIN;
		int maxRootSum = INT_MIN;

		vector< pair<TreeNode*, pair<TreeNode*, TreeNode*>>> nodes;
		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			nodes.push_back({ node, {node->left, node->right} });

			if (node->left)
			{
				st.push(node->left);
			}

			if (node->right)
			{
				st.push(node->right);
			}
		}

		for (auto v = nodes.rbegin(); v != nodes.rend(); ++v)
		{
			pair<TreeNode*, TreeNode*> p = v->second;

			int temp = INT_MIN;

			if (p.first && p.second)
			{
				temp = v->first->val + p.first->val + p.second->val;
				int maxKids = max(p.first->val, p.second->val);
				int maxKidsSum = v->first->val + maxKids;
				v->first->val = max(v->first->val, maxKidsSum);
			}
			else if (p.first)
			{
				temp = v->first->val + p.first->val; 
				int maxKidsSum = v->first->val + p.first->val;
				v->first->val = max(v->first->val, maxKidsSum);
			}
			else if (p.second)
			{
				temp = v->first->val + p.second->val;
				int maxKidsSum = v->first->val + p.second->val;
				v->first->val = max(v->first->val, maxKidsSum);
			}

			if (v->first->val > maxSum)
				maxSum = v->first->val;

			if (temp > maxRootSum)
				maxRootSum = temp;
		}

		int result = max(maxSum, maxRootSum);

		return result;
	}
};

void test(vector<TreeNode*> tree)
{
	Solution sol;

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

	int result = sol.maxPathSum(tree[0]);

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
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3) });
	test({ new TreeNode(-10), new TreeNode(9), new TreeNode(20), nullptr, nullptr, new TreeNode(15), new TreeNode(7) });
	test({ new TreeNode(-3)});
	test({ new TreeNode(2), new TreeNode(-1)});
	test({ new TreeNode(1), new TreeNode(-2), new TreeNode(-3), new TreeNode(1), new TreeNode(3), new TreeNode(-2), nullptr, new TreeNode(-1) });
	return 0;
}