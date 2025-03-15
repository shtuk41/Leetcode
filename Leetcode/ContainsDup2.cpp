#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

	unordered_map<int, int> table;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

		if (nums.size() < 2)
			return false;

		if (k == 0)
			return false;

		for (int ii = 0; ii < nums.size(); ii++)
		{
			auto n = table.find(nums[ii]);

			if (n == table.end())
			{
				table[nums[ii]] = ii;
			}
			else
			{
				if (std::abs(ii - n->second) <= k)
					return true;

				n->second = ii;
			}
		}

		return false;
    }
};

void test(string name, vector<int>& nums, int k)
{
	Solution sol;
	bool result = sol.containsNearbyDuplicate(nums, k);
	std::cout << name << " : " << result << std::endl;
}

int main()
{
	vector<int> nums1 = {1,2,3,1};
	test("test1", nums1, 3);

	vector<int> nums2 = { 1,0,1,1 };
	test("test2", nums2, 1);

	vector<int> nums3 = { 1,2,3,1,2,3 };
	test("nums3", nums3, 2);

	return 0;
}