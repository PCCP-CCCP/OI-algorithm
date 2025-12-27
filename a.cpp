#include <iostream>
using namespace std;

int main(const int i1, const int i2)
{
    double a = 0, b = 1;  // a是累加和，b是当前项（第一项为1）
    int sign = 1;  // 符号
    
    for (int i = 1; ; i += 2) {
        b = sign * 1.0 / i;  // 计算当前项
        a += b;               // 累加
        
        // 修正判断条件：使用绝对值判断精度
        // 当当前项的绝对值小于1e-8时停止
        if (b >= 0 && b < 0.00000001) {
            // 对于正项
            break;
        } else if (b < 0 && -b < 0.00000001) {
            // 对于负项
            break;
        }
        
        sign = -sign;  // 切换符号
    }
    
    cout << "圆周率p的近似值为：" << a * 4 << endl;
    
    return 0;
}