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
	int maxDepth(TreeNode* root) {

		if (!root)
			return 0;
		
		int maxDepth = 0;
		int currentDepth = 1;

		stack<pair<TreeNode*, int>> mem;
		TreeNode* node = root;

		while (true)
		{
			//std::cout << node->val << ":" << currentDepth << '\n';

			if (node->right)
				mem.push({ node, currentDepth });

			while (node && node->left)
			{
				node = node->left;
				currentDepth += 1;
				//std::cout << node->val << ":" << currentDepth << '\n';

				if (node->right)
					mem.push({ node, currentDepth });
			}

			if (currentDepth > maxDepth)
				maxDepth = currentDepth;

			if (mem.empty())
				break;

			pair<TreeNode*, int> n = mem.top();
			mem.pop();

			node = n.first->right;
			currentDepth = n.second + 1;

			if (currentDepth > maxDepth)
				maxDepth = currentDepth;
		}

		return maxDepth;

	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {

		if (!root)
			return 0;

		int maxDepth = 0;

		stack<pair<TreeNode*, int>> mem;
		TreeNode* node = root;
		mem.push({ node, 1 });

		while (!mem.empty())
		{
			auto [node, depth] = mem.top();
			mem.pop();
			maxDepth = max(maxDepth, depth);

			if (node->left)
				mem.push({ node->left, depth + 1 });
			if (node->right)
				mem.push({ node->right, depth + 1 });
		}

		return maxDepth;

	}
};



void test(vector<TreeNode*> tree)
{
	Solution sol;
	int depth = 0;
	if (tree.size() == 0)
		depth = sol.maxDepth(nullptr);
	else if (tree.size() == 1)
	{
		depth = sol.maxDepth(tree[0]);
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

		depth = sol.maxDepth(tree[0]);
	}

	std::cout << '\n' << depth << "\n\n";

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
	test({ new TreeNode(1), nullptr, new TreeNode(2) });
	test({ new TreeNode(-8), new TreeNode(-6), new TreeNode(7), new TreeNode(6), nullptr, nullptr, nullptr, nullptr, new TreeNode(5) });
	
	return 0;
}