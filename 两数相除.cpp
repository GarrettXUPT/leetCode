#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {

     //老三样，处理特殊情况
    if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
    
    if (divisor == 1) return dividend;
    
    if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

    bool flag = true, d1Flag = false;       //flag用于标识结果的正负，d1Flag是被除数为INT_MIN的标识
    int res = 0;                           //运算结果；

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        flag = false;                      //flag为false则结果为负
    }

    if (dividend == INT_MIN) {
        dividend++;                        //这里被除数若等于INT_MIN，则先加一防止取绝对值后溢出
        d1Flag = true;                     //标识被除数为INT_MIN
    }

    //取绝对值
    dividend = dividend < 0 ? -dividend : dividend;
    divisor = divisor < 0 ? -divisor : divisor;
    int s = divisor;                       //用s记录原本的除数，因为divisor等会需要变化

    while (dividend >= divisor) {            //被除数大于等于除数，说明能商出大于1的数
        int tmp = 1;                       //tmp为临时值，其数学意义代表中间层循环每次能放下除数的个数

        while (dividend - divisor >= divisor) {   //被除数减去除数大于除数本身，意思就是还能放二倍，再继续塞
            divisor += divisor;
            tmp *= 2;
        }                                  //这里循环结束时，代表被除数已经不能放下除数的2^n倍，但可能还能放下除数的2^(n-k)倍
        dividend -= divisor;               //减掉除数的2^(n-1)倍
        if (d1Flag) {                        //刚才防溢出处理时对负数加的1，现在需要对正数加回去
            dividend++;
            d1Flag = false;
        }
        res += tmp;                        //能放下的倍数存在结果里
        divisor = s;                       //将除数复原到一倍
    }
    return flag ? res : -res;              //添加正负号
}

int main() {

}