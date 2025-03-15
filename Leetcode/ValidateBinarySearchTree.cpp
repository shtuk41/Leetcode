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


class Solution {
public:
	bool isValidBST(TreeNode* root) {
	
		if (root && !root->left && !root->right)
			return true;

		stack<TreeNode*> st;

		TreeNode* curr = root;

		int lastVal = INT_MIN;
		bool first = true;

		while (true)
		{
			while (curr)
			{
				st.push(curr);
				curr = curr->left;
			}

			if (st.empty())
				return true;

			curr = st.top();
			st.pop();

			if (curr->val > lastVal || lastVal == INT_MIN && first)
			{
				lastVal = curr->val;
				first = false;
			}
			else
				break;

			curr = curr->right;
		}


		return false;
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

	bool result = sol.isValidBST(tree[0]);

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
	//test({ new TreeNode(2), new TreeNode(1), new TreeNode(3)});
	//test({ new TreeNode(5), new TreeNode(1), new TreeNode(4), nullptr, nullptr, new TreeNode(3), new TreeNode(6)});
	test({ new TreeNode(-2147483648), nullptr, new TreeNode(2147483647) });
	test({ new TreeNode(-2147483648), new TreeNode(-2147483648) });
	return 0;
}