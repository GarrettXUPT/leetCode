#include<iostream>
#include<vector>

using namespace std;


/*
	加油站问题

*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	for (int i = 0; i < gas.size(); ++i) {
		int gasCount = gas[i];
		int count = 0;  // 定义停止条件
		int j = i;
		while (1) {
			if (count == gas.size()) {  // 当遍历所有加油站时 进行返回
				return i;
			}
			if (count > gas.size()) {
				break;
			}
			if (gasCount < cost[j]) {
				break;
			}
			else {
				gasCount -= cost[j];
			}
			gasCount += gas[(j + 1) % gas.size()];
			//begin++;
			count++;
			j = (j + 1) % gas.size();
		}
	}
	return -1;
}

int main() {
	vector<int> vec1{5,1,2,3,4 };
	vector<int> vec2{ 4,4,1,5,1 };
	cout << canCompleteCircuit(vec1, vec2) << endl;


	return 0;
}