#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {

public:
	bool hasCycle(ListNode* head) {

		if (head == nullptr)
			return false;

		ListNode* fast = head;
		ListNode* slow = head;

		do
		{
			fast = fast->next;

			if (fast == slow)
				return true;

			if (fast != nullptr)
				fast = fast->next;
			else
				return false;

			if (fast == slow)
				return true;
			
			if (fast != nullptr)
				fast = fast->next;
			else
				return false;

			slow = slow->next;

			if (fast == slow)
				return true;
		} while (fast != nullptr && slow != nullptr);

		return false;
	}
};


void test(string name, ListNode* head)
{
	Solution sol;
	bool result = sol.hasCycle(head);

	std::cout << name << " : " << result << std::endl;
}

int main()
{
	ListNode node1_1(3);
	ListNode node1_2(2);
	ListNode node1_3(0);
	ListNode node1_4(-4);

	node1_1.next = &node1_2;
	node1_2.next = &node1_3;
	node1_3.next = &node1_4;
	node1_4.next = &node1_2;

	test("test1",  & node1_1);

	ListNode node2_1(1);
	ListNode node2_2(2);

	node2_1.next = &node2_2;
	node2_2.next = &node2_1;

	test("test2", &node2_1);

	ListNode node3_1(1);

	test("test3", &node3_1);






}