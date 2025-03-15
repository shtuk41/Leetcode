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
	vector<int> rightSideView(TreeNode* root) {
		
		unordered_map<int, int> result;

		if (!root)
			return vector<int>();

		stack<pair<TreeNode*, int>> st;

		st.push({ root, 0 });
		result[0] = root->val;
		
		while (!st.empty())
		{
			pair<TreeNode*, int> node = st.top();
			st.pop();

			result[node.second] = node.first->val;

			if (node.first->right) st.push({ node.first->right, node.second + 1 });
			if (node.first->left) st.push({ node.first->left, node.second + 1 });
		}

		vector<int> resultVec;
		resultVec.reserve(result.size());

		for (int ii = 0; ii < result.size(); ii++)
		{
			resultVec.push_back(result[ii]);
		}

		return resultVec;
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

	vector<int> result = sol.rightSideView(tree.size() == 0 ? nullptr: tree[0]);

	for (auto ii : result)
	{
		std::cout << ii << ',';
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
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3), nullptr, new TreeNode(5), nullptr, new TreeNode(4)});
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3), new TreeNode(4), nullptr, nullptr, nullptr, new TreeNode(5)});
	test({ new TreeNode(1), nullptr, new TreeNode(3) });
	test({ });
	return 0;
}