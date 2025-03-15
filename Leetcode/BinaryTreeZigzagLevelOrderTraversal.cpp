#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
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
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int>> result;

		if (root == nullptr)
			return result;

		stack<pair<TreeNode*, int>> st;
		st.push({ root, 0 });


		while (!st.empty())
		{
			pair<TreeNode*, int> node = st.top();
			st.pop();

			if (result.size() < node.second + 1)
			{
				vector<int> v;
				result.push_back(v);
			}

			result[node.second].push_back(node.first->val);

			if (node.first->right) st.push({ node.first->right, node.second + 1 });
			if (node.first->left) st.push({ node.first->left, node.second + 1 });
			
		}

		for (int ii = 1; ii < result.size(); ii+=2)
		{
			int aSize = result[ii].size();
			for (int jj = 0; jj < (aSize / 2); jj++)
			{
				swap<int>(result[ii][jj], result[ii][aSize - 1- jj]);
			}
		}

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

	vector<vector<int>> result = sol.zigzagLevelOrder(tree.size() == 0 ? nullptr : tree[0]);

	for (auto vec : result)
	{
		for (auto ii : vec)
		{
			std::cout << ii << ',';
		}

		std::cout << '\n';
	}

	std::cout << std::endl;

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
	test({ new TreeNode(3), new TreeNode(9), new TreeNode(20), nullptr, nullptr, new TreeNode(15), new TreeNode(7) });
	test({ new TreeNode(1) });
	test({ });
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3), new TreeNode(4), nullptr, nullptr, new TreeNode(5) });
	return 0;
}