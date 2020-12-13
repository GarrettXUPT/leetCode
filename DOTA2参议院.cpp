#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string predictPartVictory(string senate){
    int n = senate.size();
    queue<int> radiant, dire;
    for (int i = 0; i < n; ++i) {  // 以字符所在编号作为队列元素
        if (senate[i] == 'R') {
            radiant.push(i);
        }
        else {
            dire.push(i);
        }
    }
    while (!radiant.empty() && !dire.empty()) {
        if (radiant.front() < dire.front()) {  // 将先投票的议员计入下一轮
            radiant.push(radiant.front() + n);
        }
        else {
            dire.push(dire.front() + n);
        }
        radiant.pop();
        dire.pop();  // 将对方议员永久弹出
    }
    return !radiant.empty() ? "Radiant" : "Dire";
}

int main(int argc, char const *argv[])
{
    cout << predictPartVictory("DRR") << endl;
    return 0;
}

