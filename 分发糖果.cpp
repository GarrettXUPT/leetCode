#include<iostream>
#include<vector>

using namespace std;

/*
	老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
	你需要按照以下要求，帮助老师给这些孩子分发糖果：
		每个孩子至少分配到 1 个糖果。
		相邻的孩子中，评分高的孩子必须获得更多的糖果。
	那么这样下来，老师至少需要准备多少颗糖果呢？
*/


// 两次遍历
int candy(vector<int>& ratings) {
	int len = ratings.size();
	int ret = 0;
	vector<int> vecLeft(len, 0);
	for (int i = 0; i < len; ++i) {
		if (i > 0 && ratings[i] > ratings[i - 1]) {
			vecLeft[i] = vecLeft[i - 1] + 1;
		}
		else {
			vecLeft[i] = 1;
		}
	}
	/*
		此处是未省略
	*/
	vector<int> vecRight(len, 0);
	for (int i = len - 1; i >= 0; --i) {
		if (i < len - 1 && ratings[i] > ratings[i + 1]) {
			vecRight[i] = vecRight[i + 1] + 1;
		}
		else
		{
			vecRight[i] = 1;
		}
		ret += max(vecLeft[i], vecRight[i]);

	}
	// 下为改良版，可省去空间使用
	/*int right = 0, ret = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (i < len - 1 && ratings[i] > ratings[i + 1]) {
			right++;
		}
		else
		{
			right = 1;
		}
		ret += max(vecLeft[i], right);
	}*/
	return ret;
}

int main() {
	vector<int> vec{ 1,3,2,4,2,1,5 };
	cout << candy(vec) << endl;
	return 0;
}