#include<iostream>
#include<vector>

using namespace std;

/*
	枚举法质数计数
*/
bool isPrimef(int x) {

	for (int i = 2; i < x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int countPrimes(int n) {
	if (n <= 1) {
		return 0;
	}
	int count = 0;
	for (int i = 2; i < n; ++i) {
		if (isPrimef(i)) {
			count++;
		}
	}
	return count;
}

/*
	枚举没有考虑到数与数的关联性，因此难以再继续优化时间复杂度。接下来我们介绍一个常见的算法，
	该算法由希腊数学家厄拉多塞提出，称为厄拉多塞筛法，简称埃氏筛。

	我们考虑这样一个事实：如果 xx 是质数，那么大于 xx 的 xx 的倍数 2x,3x,2x,3x,… 一定不是质数，因此我们可以从这里入手。

	我们设 {isPrime}[i] 表示数i是不是质数，如果是质数则为1，否则为0。
	从小到大遍历每个数，如果这个数为质数，则将其所有的倍数都标记为合数（除了该质数本身），即 0，这样在运行结束的时候我们即能知道质数的个数。

	当然这里还可以继续优化，对于一个质数 x，如果按上文说的我们从 2x 开始标记其实是冗余的，应该直接从 xx开始标记，
	因为2x,3x,… 这些数一定在x之前就被其他数的倍数标记过了，例如 2 的所有倍数，3 的所有倍数等。
*/
int countPrimes(int n) {
	vector<int> isPrime(n, 1);
	int ans = 0;
	for (int i = 2; i < n; ++i) {
		if (isPrime[i]) {
			ans += 1;
			if ((long long)i * i < n) {
				for (int j = i * i; j < n; j += i) {
					isPrime[j] = 0;
				}
			}
		}
	}
	return ans;
}


int main() {
	cout << countPrimes(499979) << endl;
	return 0;
}