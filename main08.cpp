#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
	使用两个指针，一个指向第一个元素，一个指向最后一个元素,两个元素之间形成的最大区域就是min(first, last) * (last - first - 1)
	前后两个元素，哪个元素值较小，则移动该元素上的指针即可
*/
int maxArea(vector<int>& height) {
	auto begin = height.begin();
	auto rbegin = height.end() - 1;
	int len = height.size() - 1;
	vector<int> resVec;
	while (begin != rbegin) {
		int hg = min(*begin, *rbegin);
		resVec.push_back(len * hg);
		if (hg == *begin) {
			begin++;
		}
		else {
			rbegin--;
		}
		len--;
	}
	return *max_element(resVec.begin(), resVec.end());
}

int main() {
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	
	vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
	/*for (auto& ele : input) {
		cout << ele << endl;
	}
	cout << endl;*/
	cout << maxArea(input) << endl;
}