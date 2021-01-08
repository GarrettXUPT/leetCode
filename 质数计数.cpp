#include<iostream>
#include<vector>

using namespace std;

/*
	ö�ٷ���������
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
	ö��û�п��ǵ��������Ĺ����ԣ���������ټ����Ż�ʱ�临�Ӷȡ����������ǽ���һ���������㷨��
	���㷨��ϣ����ѧ�Ҷ��������������Ϊ��������ɸ������ư���ɸ��

	���ǿ�������һ����ʵ����� xx ����������ô���� xx �� xx �ı��� 2x,3x,2x,3x,�� һ������������������ǿ��Դ��������֡�

	������ {isPrime}[i] ��ʾ��i�ǲ��������������������Ϊ1������Ϊ0��
	��С�������ÿ��������������Ϊ�������������еı��������Ϊ���������˸������������� 0�����������н�����ʱ�����Ǽ���֪�������ĸ�����

	��Ȼ���ﻹ���Լ����Ż�������һ������ x�����������˵�����Ǵ� 2x ��ʼ�����ʵ������ģ�Ӧ��ֱ�Ӵ� xx��ʼ��ǣ�
	��Ϊ2x,3x,�� ��Щ��һ����x֮ǰ�ͱ��������ı�����ǹ��ˣ����� 2 �����б�����3 �����б����ȡ�
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