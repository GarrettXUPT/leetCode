#include<iostream>
#include<vector>

using namespace std;

bool isVaildSukudo(vector<vector<char>>& board) {

}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = { 0 };// ��ϣ��洢ÿһ�е�ÿ�����Ƿ���ֹ���Ĭ�ϳ�ʼ����£�ÿһ��ÿһ������û�г��ֹ�
        // ����board��9�У��ڶ�ά��ά��10��Ϊ�����±���9���������е�����9��Ӧ��
        int col[9][10] = { 0 };// �洢ÿһ�е�ÿ�����Ƿ���ֹ���Ĭ�ϳ�ʼ����£�ÿһ�е�ÿһ������û�г��ֹ�
        int box[9][10] = { 0 };// �洢ÿһ��box��ÿ�����Ƿ���ֹ���Ĭ�ϳ�ʼ����£���ÿ��box�У�ÿ������û�г��ֹ�������board��9��box��
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // ��������i�е�j�е��Ǹ���,����Ҫ�ж�������������ڵ�����û�г��ֹ���
                // ͬʱ�ж�������������ڵ�����û�г��ֹ�
                // ͬʱ�ж�������������ڵ�box����û�г��ֹ�
                if (board[i][j] == '.') continue;
                int curNumber = board[i][j] - '0';
                if (row[i][curNumber]) return false;
                if (col[j][curNumber]) return false;
                if (box[j / 3 + (i / 3) * 3][curNumber]) return false;

                row[i][curNumber] = 1;// ֮ǰ��û���ֹ������ڳ����ˣ��͸�����Ϊ1���´����������ܹ�ֱ�ӷ���false�ˡ�
                col[j][curNumber] = 1;
                box[j / 3 + (i / 3) * 3][curNumber] = 1;
            }
        }
        return true;
    }
};

