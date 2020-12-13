#include<iostream>

using namespace std;

int mySqrt(int x) {
    //注：在中间过程计算平方的时候可能出现溢出，所以用long long。
    long long i = 0;
    long long j = x / 2 + 1;//对于一个非负数n，它的平方根不会大于（ n/ 2 + 1）
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