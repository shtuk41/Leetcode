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
	vector<double> averageOfLevels(TreeNode* root) {

		unordered_map<int, pair<double, int>> result;

		stack<pair<TreeNode*, int>> st;

		st.push({ root, 0 });

		while (!st.empty())
		{
			pair<TreeNode*, int> node = st.top();
			st.pop();

			double n = ++result[node.second].second;

			double mult = (n - 1) / n;

			result[node.second].first = result[node.second].first * mult +  node.first->val / n;

			if (node.first->right) st.push({ node.first->right, node.second + 1 });
			if (node.first->left) st.push({ node.first->left, node.second + 1 });
		}

		vector<double> resultVec;
		resultVec.resize(result.size());

		for (int ii = 0; ii < result.size(); ii++)
		{
			resultVec[ii] = result[ii].first;
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

	vector<double> result = sol.averageOfLevels(tree.size() == 0 ? nullptr : tree[0]);

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
	test({ new TreeNode(3), new TreeNode(9), new TreeNode(20), nullptr, nullptr, new TreeNode(15), new TreeNode(7) });
	test({ new TreeNode(3), new TreeNode(9), new TreeNode(20), new TreeNode(15), new TreeNode(7) });
	return 0;
}