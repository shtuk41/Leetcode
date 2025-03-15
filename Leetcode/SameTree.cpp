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
	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (!p && !q)
			return true;
		else if (!p)
			return false;
		else if (!q)
			return false;

		stack<TreeNode*> stack1, stack2;

		stack1.push(p);
		stack2.push(q);

		while (!stack1.empty() && !stack2.empty())
		{
			TreeNode* node1 = stack1.top();
			stack1.pop();
			TreeNode* node2 = stack2.top();
			stack2.pop();

			if (node1->val != node2->val)
				return false;

			bool compareLeft = !((node1->left == nullptr) ^ (node2->left == nullptr)) || node1->left && node2->left && (node1->left->val == node2->left->val);
			bool compareRight = !((node1->right == nullptr) ^ (node2->right == nullptr)) || node1->right && node2->right && (node1->right->val == node2->right->val);

			if (!compareLeft || !compareRight)
				return false;

			if (node1->left)
				stack1.push(node1->left);
			if (node1->right)
				stack1.push(node1->right);

			if (node2->left)
				stack2.push(node2->left);
			if (node2->right)
				stack2.push(node2->right);
		}

		return true;
	}
};

void test(vector<TreeNode*> tree1, vector<TreeNode*> tree2)
{
	Solution sol;
	bool same = false;
	if (tree1.size() == 0 && tree2.size() == 0)
		same = sol.isSameTree(nullptr, nullptr);
	else
	{
		for (int ii = 0; ii < tree1.size(); ii++)
		{
			int index = ii + 1;

			if (tree1[ii] != nullptr)
			{
				int leftIndex = index * 2 - 1;
				int rightIndex = index * 2;

				tree1[ii]->left = leftIndex < tree1.size() ? tree1[leftIndex] : nullptr;
				tree1[ii]->right = rightIndex < tree1.size() ? tree1[rightIndex] : nullptr;
			}
		}
		for (int ii = 0; ii < tree2.size(); ii++)
		{
			int index = ii + 1;

			if (tree2[ii] != nullptr)
			{
				int leftIndex = index * 2 - 1;
				int rightIndex = index * 2;

				tree2[ii]->left = leftIndex < tree2.size() ? tree2[leftIndex] : nullptr;
				tree2[ii]->right = rightIndex < tree2.size() ? tree2[rightIndex] : nullptr;
			}
		}

		same = sol.isSameTree(tree1[0], tree2[0]);
	}

	std::cout << '\n' << same << "\n\n";

	if (!tree1.empty())
	{
		for (auto ii : tree1)
		{
			delete ii;
		}
	}

	if (!tree2.empty())
	{
		for (auto ii : tree2)
		{
			delete ii;
		}
	}
}

int main()
{
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(3)},
		{ new TreeNode(1), new TreeNode(2), new TreeNode(3) });
	test({ new TreeNode(1), new TreeNode(2) },
		{ new TreeNode(1), nullptr, new TreeNode(2) });
	test({ new TreeNode(1), new TreeNode(2), new TreeNode(1) },
		{ new TreeNode(1), new TreeNode(1), new TreeNode(2) });
	test({ nullptr },
		{ new TreeNode(0)});

	return 0;
}