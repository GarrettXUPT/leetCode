#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool findNegative(map<int, int>& p) {
	auto begin = p.begin();
	while (begin != p.end()) {
		if (begin->second < 0) {
			return false;
		}
		begin++;
	}
	return true;
}

bool lemonadeChange(vector<int>& bills) {

	if (bills.empty() || bills[0] > 5) {
		return false;
	}
	map<int, int>changesType{ {5, 0}, {10, 0}, {20, 0} };
	int changes = 0;
	auto begin = bills.begin();
	while (begin != bills.end()) {
		if (*begin > 5) {
			if (changes < *begin - 5) {
				return false;
			}
			int tmp = *begin - 5;
			if (tmp  == 5) {
				changesType[5]--;
			}
			else if(tmp == 15)
			{
				if (changesType[10]) {
					changesType[10]--;
				}
				else
				{
					changesType[5] = changesType[5] - 2;
				}
				changesType[5]--;
			}
			if (!findNegative(changesType)) {
				return false;
			}
			changesType[*begin]++;
			changes -= tmp;
			changes += *begin;
		}
		else
		{
			changesType[*begin]++;
			changes = changes + 5;
		}
		begin++;
	}
	return true;
}

int main() {
	vector<int> vec{ 5,5,10,10,20 };
	auto res = lemonadeChange(vec);
	cout << res << endl;

}