#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* sortList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	vector<int> vec;
	while (head != nullptr) {
		vec.push_back(head->val);
		head = head->next;
	}
	sort(vec.begin(), vec.end());
	/*for (auto& ele : vec) {
		cout << ele << endl;
	}*/
	ListNode* newhead = new ListNode(vec[0], nullptr);
	newhead->next = nullptr;
	for (int i = 1; i < vec.size(); ++i) {
		newhead->next = new ListNode(vec[i], nullptr);
		newhead = newhead->next;
	}

	return newhead;

}

int main() {
	ListNode* head = nullptr;
	sortList(head);
	return 0;
}