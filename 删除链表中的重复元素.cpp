#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* deleteDuplicates(ListNode* head) {

	ListNode* newhead = head;
	int tmp = head->val;
	while (head->next != nullptr) {
		if (head->next->val == tmp) {
			head->next = head->next->next;
		}
		tmp = head->next->val;
		head = head->next;
	}

	return newhead;
}