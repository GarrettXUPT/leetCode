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
        return list.size() >= 3;  // 若列表中至少有3个数，那么已经取得了一个斐波那契数列
    }
    long long curr = 0;
    for (int i = index; i < length; i++) {
        if (i > index && S[index] == '0') {  // 以0开头的数
            break;
        }
        curr = curr * 10 + S[i] - '0';  // 拆分出来当前的值
        if (curr > INT_MAX) {  // 拆分出来的数大于int范围
            break;
        }
        if (list.size() >= 2) {  // 若列表中存在大于2个的元素
            if (curr < sum) {  // 可继续进行拆分
                continue;
            }
            else if (curr > sum) {  // 若拆分出来的数已经大于两个数的和
                break;
            }
        }
        list.push_back(curr);  // 若是满足菲波那切数列条件
        if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
            return true;
        }
        list.pop_back();
    }
    return false;
}
