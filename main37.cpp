#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
	��������������
*/

int monotoneIncreasingDigits(int N) {
    string strN = to_string(N);
    int i = 1;
    // ֱ��ʹ��ǰ�����������,��֤ԭ�����Ƿ�λ����
    while (i < strN.length() && strN[i - 1] <= strN[i]) {
        i += 1;
    }
    // ��ԭ�����в����ǵ�����
    if (i < strN.length()) {
        // �Ӻ���ǰ�����ݼ������м�һ��ֱ���ҵ��ݼ��Ժ��ƻ���ǰ��������ϵ������
        while (i > 0 && strN[i - 1] > strN[i]) {
            strN[i - 1] -= 1;
            i -= 1;
        }
        // ����һ���ҵ��������Ժ�ȫ����Ϊ9
        for (i += 1; i < strN.length(); ++i) {
            strN[i] = '9';
        }
    }
    // �ַ���ת����
    return stoi(strN);
}

int main() {
    cout << monotoneIncreasingDigits(332) << endl;
    return 0;
}
