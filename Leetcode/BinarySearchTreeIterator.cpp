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

class BSTIterator2 {

	vector<TreeNode*> vec;
	int count = 0;

public:
	BSTIterator2(TreeNode* root) {

		
		stack<TreeNode*> st;
		st.push(root);
		
		//build in-order tree
		while (!st.empty())
		{
			TreeNode* n = st.top();
			st.pop();

			if (!n->left)
			{
				vec.push_back(n);
			}

			if (n->right)
			{
				st.push(n->right);
				n->right = nullptr;
			}
			
			if (n->left)
			{
				st.push(n);
				st.push(n->left);
				n->left = nullptr;
			}
		}
	}

	int next() {
		
		int val = 0;
		if (count < vec.size())
		{
			val = vec[count++]->val;
		}

		return val;

	}

	bool hasNext() {
		if (vec.size() > 0 && count < vec.size())
			return true;
		else
			return false;
	}
};

class BSTIterator {

	stack<TreeNode*> st;

public:
	BSTIterator(TreeNode* root) {
		st.push(root);
	}

	int next() {

		int result = -1111;
		bool found = false;

		while (!st.empty())
		{
			TreeNode* n = st.top();
			st.pop();

			if (!n->left)
			{
				result = n->val;
				found = true;
			}

			if (n->right)
			{
				st.push(n->right);
				n->right = nullptr;
			}

			if (n->left)
			{
				st.push(n);
				st.push(n->left);
				n->left = nullptr;
			}

			if (found)
				return result;
		}

		return result;

	}

	bool hasNext() {
		return !st.empty();
	}
};

void test(vector<TreeNode*> tree)
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

	BSTIterator sol(tree[0]);

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
	test({ new TreeNode(7), new TreeNode(3), new TreeNode(15), nullptr, nullptr, new TreeNode(9), new TreeNode(20) });

	test({ new TreeNode(1), nullptr, new TreeNode(2) });
	return 0;
}