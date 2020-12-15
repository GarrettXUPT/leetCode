#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

/*
	排列序列
*/

string getPermutation(int n, int k) {
	char* chArr = (char*)malloc(sizeof(char) * n + 1);
	memset(chArr, 0, sizeof(char) * n + 1);
	vector<char> vec;
	for (int i = 0; i < n; ++i) {
		chArr[i] = i + 49;
	}

	while (k > 1) {
		int i = n - 1;
		while (i > 0 && chArr[i - 1] >= chArr[i]) {
			i--;
		}

		int j = n - 1;
		while (j > 0 && chArr[j] <= chArr[i - 1]) {
			j--;
		}
		swap(chArr[i - 1], chArr[j]);
		reverse(chArr + i, chArr + sizeof(char) * n);
		k--;
	}

	return chArr;
}

int main() {
	cout << char(48) << endl;
	cout << getPermutation(3, 3) << endl;
	return 0;
}