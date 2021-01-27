#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
	单调递增的数字
*/

int monotoneIncreasingDigits(int N) {
    string strN = to_string(N);
    int i = 1;
    // 直接使用前项递增的数字,验证原数字是否位递增
    while (i < strN.length() && strN[i - 1] <= strN[i]) {
        i += 1;
    }
    // 若原数字中并不是递增的，此时i就是不递增的元素
    if (i < strN.length()) {
        // 从后往前数，递减的序列减一，直到找到递减以后不破坏由前向后递增关系的数字，从后向前数，将从后向前的所有数减一
        // 将i以前的元素减一
        while (i > 0 && strN[i - 1] > strN[i]) {
            strN[i - 1] -= 1;
            i -= 1;
        }
        // 由上一轮找到产生由前向后发生递减的数字以后，从该位开始，全部填为9
        for (i += 1; i < strN.length(); ++i) {
            strN[i] = '9';
        }
    }
    // 字符串转数字
    return stoi(strN);
}

int main() {
    cout << monotoneIncreasingDigits(332) << endl;
    return 0;
}
