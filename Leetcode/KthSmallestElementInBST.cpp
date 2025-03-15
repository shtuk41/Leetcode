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
	int kthSmallest(TreeNode* root, int k) {

		stack<TreeNode*> st;
		st.push(root);

		int count = 1;

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (!node->left)
			{
				if (count == k)
					return node->val;

				count++;
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

		return -1;
	}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode* curr = root;

		while (true) {
			while (curr) {  
				st.push(curr);
				curr = curr->left;
			}

			curr = st.top();
			st.pop();

			if (--k == 0)  
				return curr->val;

			curr = curr->right;  
		}
	}
};



void test(vector<TreeNode*> tree, int k)
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

	int result = sol.kthSmallest(tree[0], k);

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
	test({ new TreeNode(3), new TreeNode(1), new TreeNode(4), nullptr, new TreeNode(2) }, 1);
	test({ new TreeNode(5), new TreeNode(3), new TreeNode(6), new TreeNode(2), new TreeNode(4), nullptr, nullptr, new TreeNode(1) }, 3);
	return 0;
}