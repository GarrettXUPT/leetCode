#include<iostream>

using namespace std;

/*
    ƽ��������
*/

int mySqrt(int x) {
    //ע�����м���̼���ƽ����ʱ����ܳ��������������long long��
    long long i = 0;
    long long j = x / 2 + 1;//����һ���Ǹ���n������ƽ����������ڣ� n/ 2 + 1��
    while (i <= j)
    {
        long long mid = (i + j) / 2;
        long long res = mid * mid;
        if (res == x) return mid;
        else if (res < x) i = mid + 1;
        else j = mid - 1;
    }
    return j;
}

int main() {
	cout << mySqrt(9) << endl;
	return 0;
}