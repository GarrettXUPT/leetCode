#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr){}
};

ListNode* insertSortList(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	// 一直指向头部
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* lastStarted = head;
	ListNode* curr = head->next;
	while (curr != nullptr) {
		if (lastStarted->val <= curr->val) {
			lastStarted = lastStarted->next;
		}
		else {
			ListNode* prev = dummy;
			while (prev->next->val <= curr->val) {
				prev = prev->next;
			}
			lastStarted->next = curr->next;
			curr->next = prev->next;
			prev->next = curr;
		}
		curr = lastStarted->next;
	}
	return dummy->next;
}

int main() {

	return 0;
}