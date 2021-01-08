#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }
    ListNode* pos = head;
    int total = 0;
    vector<int> check;
    while (pos != nullptr) {
        check.push_back(pos->val);
        pos = pos->next;
        total++;
    }
    if (total == 1) {
        return head;
    }
    if (k == total) {
        return head;
    }
    else if (k > total) {
        k = k % total;
        if (k == 0) {
            return head;
        }
    }

    int startPos = check.size() - k;
    ListNode* newhead = new ListNode(check[startPos], nullptr);
    ListNode* tmp = newhead;
    while (total > 1) {
        startPos = (startPos + 1) % check.size();
        newhead->next = new ListNode(check[startPos]);
        newhead = newhead->next;
        total--;
    }
    return tmp;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;//list��ֻ��һ��Ԫ����ô��ת������䣬ֱ�ӷ��ؼ���
    int len = 0;//������βͳ��һ�³���
    ListNode* iter = head;
    while (iter) {
        len++;
        iter = iter->next;
    }
    k = k % len;//ȡ�ཱུά
    while (k) {//�ѵ���������������len����
        ListNode* last = head;//ÿ�ζ�Ҫ������Ѱlast��newlast(��prev)
        ListNode* prev = nullptr;
        while (last->next) {
            prev = last;
            last = last->next;
        }
        //��ʱlast��Ϊ�µĶ�ͷ��prev��Ϊ�µĶ�β
        prev->next = nullptr;
        last->next = head;
        head = last;//�޸�head                            
        k--;
    }
    return  head;
}


ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    int len = 1;  // ��ȡ������
    while (fast->next != nullptr) {
        fast = fast->next;
        len++;
    }
    // ��β���� �ȹ��ɻ�
    fast->next = head;
    // ��ָ���ƶ��Ĳ���
    int step = len - k % len;
    while (step > 1) {
        slow = slow->next;
        step--;
    }
    // slow�൱��β���
    ListNode* tmp = slow->next;
    slow->next = nullptr;
    return tmp;
}

