#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	ʹ�ö�̬�滮��������⣺һ���ֱ�����������״̬��һ���ֱ�����������״̬
	buy[i][j]��ʾ����prices[0,...,i]�۸��ڣ�ǡ����j�ν��ף������������ϻ���һֻ��Ʊ
	sell[i][j]��ʾ����prices[0,...,i]�۸��ڣ�ǡ����j�ν���, �����ϲ�ʣ���Ʊ
	
	�����������buy[i][j],���ǵ�ǰ���ϳ��еĹ�Ʊ�Ƿ��ǵ�i�������
		1�����ǵ�i�����룬��ô��i - 1��ʱ������û�й�Ʊ sell[i - 1][j] - price[i]
		2�����ǵ�i - 1�����룬��ôbuy[i - 1][j]
	�����������̣����ǹ�Ʊ��ʲôʱ��������
		1�����ǵ�i��������buy[i - 1][j - 1] + price[i]
		2�������ǵ�i�������ģ���ô�ڵ�i - 1�죬���ϲ����й�Ʊ��Ϊsell[i - 1][j]
	�߽�������buy[0][0,...,k] sell[0][0,...,k]
		����buy������ԣ�����buy[0][0] = - price[0]����ֵ�ģ�����λ�ö�Ϊ�Ƿ�λ��
		����sell������ԣ�sell[0][0] = 0; ����λ�ö�Ϊ�Ƿ�λ��
*/

int maxProfit(int k, vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int len = prices.size();
	k = min(k, len / 2);  // ��n�������Խ���n / 2�ν��ף����Կɽ��иò��Ż����ж�̬�滮
	vector<vector<int>> buy(len, vector<int>(k + 1, 0));
	vector<vector<int>> sell(len, vector<int>(k + 1, 0));
	buy[0][0] = -prices[0];
	sell[0][0] = 0;
	for (int i = 1; i <= k; ++i) {
		buy[0][i] = sell[0][i] = INT16_MIN / 2;
	}
	
	for (int i = 1; i < len; ++i) {
		buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
		for (int j = 1; j <= k; ++j) {
			buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
			sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
		}
	}
	return *max_element(sell[len - 1].begin(), sell[len - 1].end());
}

int main() {
	vector<int> vec{ 2, 4, 1 };
	cout << maxProfit(2, vec) << endl;

}