#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		vector<TreeNode*> st, stP, stQ;
		st.push_back(root);

		while (!st.empty())
		{
			TreeNode* node = st.back();

			if (node == p)
			{
				stP = st;
			}

			if (node == q)
			{
				stQ = st;
			}

			if (!stQ.empty() && !stP.empty())
				break;

			if (node->left)
			{
				st.push_back(node->left);
				node->left = nullptr;
				continue;
			}

			if (node->right)
			{
				st.push_back(node->right);
				node->right = nullptr;
				continue;
			}

			if (node->left == nullptr && node->right == nullptr)
				st.pop_back();
		}

		for (int ii = 0; ii < min(stQ.size(), stP.size()); ii++)
		{
			if (stQ[ii] == p)
				return p;
			if (stP[ii] == q)
				return q;
			if (stQ[ii] != stP[ii] )
				return stQ[ii - 1];
		}

		return nullptr;
	}
};

void test(vector<TreeNode*> tree, TreeNode* p, TreeNode* q)
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

	Solution sol;
	TreeNode* l = sol.lowestCommonAncestor(tree[0], p, q);

	std::cout << "Result: " << (l != nullptr ? l->val : -1111) << std::endl;

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
	TreeNode* p = new TreeNode(5);
	TreeNode* q = new TreeNode(1);


	test({ new TreeNode(3), 
			p,
			q, 
			new TreeNode(6), 
			new TreeNode(2), 
			new TreeNode(0), 
			new TreeNode(8), 
			nullptr, 
			nullptr, 
			new TreeNode(7), 
			new TreeNode(4) },
			p, q);

	p = new TreeNode(5);
	q = new TreeNode(4);

	test({ new TreeNode(3),
			p,
			new TreeNode(1),
			new TreeNode(6),
			new TreeNode(2),
			new TreeNode(0),
			new TreeNode(8),
			nullptr,
			nullptr,
			new TreeNode(7),
			q },
		p, q);

	p = new TreeNode(1);
	q = new TreeNode(2);

	test({ p, q},
		p, q);

	p = new TreeNode(2);
	q = new TreeNode(1);

	test({ p, nullptr, q },
		p, q);

	return 0;
}