#include<iostream>
#include<vector>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

/*
	翻转链表m到n的位置
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m == n) {
		return head;
	}
	ListNode* newhead = head;
	ListNode* node = head;
	ListNode* tmpNode = head;
	int count = 1;
	vector<int> vec;
	while (tmpNode != nullptr) {
		if (count >= m && count <= n) {
			vec.push_back(tmpNode->val);
		}
		else if (count > n) {
			break;
		}
		tmpNode = tmpNode->next;
		count++;
	}
	ListNode* nextNode = new ListNode(vec[vec.size() - 1]);
	ListNode* newNode = nextNode;
	auto rbegin = vec.rbegin() + 1;
	while (rbegin != vec.rend()) {
		nextNode->next = new ListNode(*rbegin);
		nextNode = nextNode->next;
		rbegin++;
	}
	nextNode->next = tmpNode;
	if (m == 1) {
		return newNode;
	}
	int c = 2;
	while (c < m) {
		node = node->next;
		c++;
	}
	node->next = newNode;

	return newhead;
}