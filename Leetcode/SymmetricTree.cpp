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

class Solution2 {
public:
	bool isSymmetric(TreeNode* root) {

		if (!root->left && !root->right)
			return true;

		if ((root->left == nullptr) ^ (root->right == nullptr))
			return false;

		vector<int> leftVec, rightVec;
		stack<TreeNode*> st;
		st.push(root->left);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (!node)
			{
				leftVec.push_back(-1000);

				//std::cout << -1000 << ',';
				continue;
			}
			else
			{
				leftVec.push_back(node->val);
				//std::cout << node->val << ',';
			}
			

			if (node->left || node->right)
			{
				swap(node->left, node->right);
				st.push(node->left);
				st.push(node->right);
			}
		}

		st.push(root->right);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();

			if (!node)
			{
				rightVec.push_back(-1000);

				//std::cout << -1000 << ',';
				continue;
			}
			else
			{
				rightVec.push_back(node->val);
				//std::cout << node->val << ',';
			}


			if (node->left || node->right)
			{
				st.push(node->left);
				st.push(node->right);
			}
		}

		bool equal = leftVec == rightVec;

		return equal;
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {

		if (!root->left && !root->right)
			return true;

		if ((root->left == nullptr) ^ (root->right == nullptr))
			return false;

		stack<TreeNode*> stLeft, stRight;
		stLeft.push(root->left);
		stRight.push(root->right);

		while (!stLeft.empty() && !stRight.empty())
		{
			TreeNode* nodeL = stLeft.top();
			stLeft.pop();

			TreeNode* nodeR = stRight.top();
			stRight.pop();

			if (nodeL == nullptr && nodeR == nullptr)
				continue;
			else if ((nodeL == nullptr) ^ (nodeR == nullptr))
				return false;

			if (nodeL->val == nodeR->val)
			{
				if (nodeL->left || nodeL->right)
				{
					swap(nodeL->left, nodeL->right);
					stLeft.push(nodeL->left);
					stLeft.push(nodeL->right);
				}

				if (nodeR->left || nodeR->right)
				{
					stRight.push(nodeR->left);
					stRight.push(nodeR->right);
				}
			}
			else
			{
				return false;
			}

			if (stLeft.size() != stRight.size())
				return false;
		}

		return true;
	}
};

void test(vector<TreeNode*> tree)
{
	Solution sol;
	bool symmetric = 0;
	if (tree.size() == 0)
		symmetric = sol.isSymmetric(nullptr);
	else if (tree.size() == 1)
	{
		symmetric = sol.isSymmetric(tree[0]);
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

		symmetric = sol.isSymmetric(tree[0]);
	}

	std::cout << '\n' << symmetric << "\n\n";

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
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(2), new TreeNode(3), new TreeNode(4), new TreeNode(4), new TreeNode(3) });
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(2), nullptr, new TreeNode(3), nullptr, new TreeNode(3) });
	test({ new TreeNode(1), new TreeNode(0), nullptr });

	test({ new TreeNode(2), new TreeNode(3), new TreeNode(3), new TreeNode(4), 
		new TreeNode(5), new TreeNode(5), new TreeNode(4), nullptr, nullptr, 
		new TreeNode(8), new TreeNode(9), new TreeNode(9), new TreeNode(8), nullptr, nullptr });

	return 0;
}