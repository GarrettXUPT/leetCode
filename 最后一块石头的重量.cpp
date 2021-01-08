#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
	int len = stones.size();
	if (len == 0) {
		return 0;
	}
	else if (len == 1) {
		return 1;
	}

	while (1) {
		auto firstPos = max_element(stones.begin(), stones.end());
		int firstMax = *firstPos;
		stones.erase(firstPos);
		auto secondPos = max_element(stones.begin(), stones.end());
		int secondMax = *secondPos;
		stones.erase(secondPos);
		int tmp = firstMax - secondMax;
		if (tmp != 0) {
			stones.push_back(tmp);
		}
		if (stones.size() == 1) {
			return stones[0];
		}
		else if (stones.size() == 0) {
			return 0;
		}
	}
	return -1;
}

int main() {
	vector<int> vec{ 2,7,4,1,8,1 };
	cout << lastStoneWeight(vec) << endl;
	return 0;
}