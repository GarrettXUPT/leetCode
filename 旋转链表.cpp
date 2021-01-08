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
    if (!head || !head->next) return head;//list中只有一个元素怎么旋转都不会变，直接返回即可
    int len = 0;//遍历到尾统计一下长度
    ListNode* iter = head;
    while (iter) {
        len++;
        iter = iter->next;
    }
    k = k % len;//取余降维
    while (k) {//把迭代次数控制在了len以内
        ListNode* last = head;//每次都要重新搜寻last和newlast(即prev)
        ListNode* prev = nullptr;
        while (last->next) {
            prev = last;
            last = last->next;
        }
        //此时last成为新的队头，prev成为新的队尾
        prev->next = nullptr;
        last->next = head;
        head = last;//修改head                            
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
    int len = 1;  // 获取链表长度
    while (fast->next != nullptr) {
        fast = fast->next;
        len++;
    }
    // 首尾相连 先构成环
    fast->next = head;
    // 慢指针移动的步数
    int step = len - k % len;
    while (step > 1) {
        slow = slow->next;
        step--;
    }
    // slow相当于尾结点
    ListNode* tmp = slow->next;
    slow->next = nullptr;
    return tmp;
}

