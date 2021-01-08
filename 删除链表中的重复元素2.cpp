#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	map<int, int>flag;
	ListNode* pos = head;
	while (pos != nullptr) {
		if (flag.find(pos->val) != flag.end()) {
			flag.at(pos->val)++;
		}
		else
		{
			flag.insert({ pos->val, 1 });
		}
		pos++;
	}
	ListNode* cur = head;
	ListNode* newhead = new ListNode(0);
	ListNode* ret = newhead;
	while (cur != nullptr) {
		if (flag.at(cur->val) == 1) {
			ListNode* tmp = new ListNode(cur->val);
			newhead->next = tmp;
			newhead = newhead->next;
		}
		cur++;
	}
	ret = ret->next;
	return ret;
}