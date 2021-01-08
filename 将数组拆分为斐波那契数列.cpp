#include<iostream>
#include<vector>

using namespace std;

vector<int> splitIntoFibonacci(string S) {
    vector<int> list;
    backtrack(list, S, S.length(), 0, 0, 0);
    return list;
}

bool backtrack(vector<int>& list, string S, int length, int index, long long sum, int prev) {
    if (index == length) {
        return list.size() >= 3;  // ���б���������3��������ô�Ѿ�ȡ����һ��쳲���������
    }
    long long curr = 0;
    for (int i = index; i < length; i++) {
        if (i > index && S[index] == '0') {  // ��0��ͷ����
            break;
        }
        curr = curr * 10 + S[i] - '0';  // ��ֳ�����ǰ��ֵ
        if (curr > INT_MAX) {  // ��ֳ�����������int��Χ
            break;
        }
        if (list.size() >= 2) {  // ���б��д��ڴ���2����Ԫ��
            if (curr < sum) {  // �ɼ������в��
                continue;
            }
            else if (curr > sum) {  // ����ֳ��������Ѿ������������ĺ�
                break;
            }
        }
        list.push_back(curr);  // ��������Ʋ�������������
        if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
            return true;
        }
        list.pop_back();
    }
    return false;
}
