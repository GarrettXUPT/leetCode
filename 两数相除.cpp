#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {

     //�������������������
    if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
    
    if (divisor == 1) return dividend;
    
    if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

    bool flag = true, d1Flag = false;       //flag���ڱ�ʶ�����������d1Flag�Ǳ�����ΪINT_MIN�ı�ʶ
    int res = 0;                           //��������

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        flag = false;                      //flagΪfalse����Ϊ��
    }

    if (dividend == INT_MIN) {
        dividend++;                        //���ﱻ����������INT_MIN�����ȼ�һ��ֹȡ����ֵ�����
        d1Flag = true;                     //��ʶ������ΪINT_MIN
    }

    //ȡ����ֵ
    dividend = dividend < 0 ? -dividend : dividend;
    divisor = divisor < 0 ? -divisor : divisor;
    int s = divisor;                       //��s��¼ԭ���ĳ�������Ϊdivisor�Ȼ���Ҫ�仯

    while (dividend >= divisor) {            //���������ڵ��ڳ�����˵�����̳�����1����
        int tmp = 1;                       //tmpΪ��ʱֵ������ѧ��������м��ѭ��ÿ���ܷ��³����ĸ���

        while (dividend - divisor >= divisor) {   //��������ȥ�������ڳ���������˼���ǻ��ܷŶ������ټ�����
            divisor += divisor;
            tmp *= 2;
        }                                  //����ѭ������ʱ�����������Ѿ����ܷ��³�����2^n���������ܻ��ܷ��³�����2^(n-k)��
        dividend -= divisor;               //����������2^(n-1)��
        if (d1Flag) {                        //�ղŷ��������ʱ�Ը����ӵ�1��������Ҫ�������ӻ�ȥ
            dividend++;
            d1Flag = false;
        }
        res += tmp;                        //�ܷ��µı������ڽ����
        divisor = s;                       //��������ԭ��һ��
    }
    return flag ? res : -res;              //���������
}

int main() {

}