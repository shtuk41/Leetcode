#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution2 {
public:
	int getMinimumDifference(TreeNode* root) {

		set<int> numbers;
		stack<TreeNode*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			numbers.insert(node->val);

			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}

		int minimumSize = 111111;
		int prev = 222222;

		for (int num : numbers)
		{
			int diff = abs(num - prev);
			if (diff < minimumSize)
			{
				minimumSize = diff;
			}

			prev = num;
		}

		return minimumSize;
	}
};

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {

		stack<TreeNode*> st;
		st.push(root);

		int minimumSize = 111111;
		int prev = 222222;

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (!node->left)
			{
				//std::cout << node->val << ',';
				int diff = abs(node->val - prev);
				if (diff < minimumSize)
				{
					minimumSize = diff;
				}

				prev = node->val;
			}

			if (node->left)
			{
				st.push(node);
				st.push(node->left);
				node->left = nullptr;
				continue;
			}

			if (node->right)
			{
				st.push(node->right);
				node->right = nullptr;
			}
		}

		//std::cout << std::endl;

		return minimumSize;
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

	int result = sol.getMinimumDifference(tree.size() == 0 ? nullptr : tree[0]);

	std::cout << result << std::endl;

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
	test({ new TreeNode(4), new TreeNode(2), new TreeNode(6), new TreeNode(1), new TreeNode(3)});
	test({ new TreeNode(1), new TreeNode(0), new TreeNode(48), nullptr, nullptr, new TreeNode(12), new TreeNode(49)});
	return 0;
}