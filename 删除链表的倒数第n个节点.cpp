#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (n == 0) {
		return head;
	}
	int len = 0;
	ListNode* pos = head;
	while (pos != nullptr) {
		len++;
		pos = pos->next;
	}
	pos = head;
	if (n == len) {
		head = pos->next;
		return head;
	}
	for (int i = 0; i < len - n - 1; ++i) {
		pos = pos->next;
	}
	pos->next = pos->next->next;
	return head;
}

int main() {
	
	return 0;
}