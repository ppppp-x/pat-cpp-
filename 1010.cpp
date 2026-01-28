#include <iostream>
using namespace std;

int main() {
    int c, e; // c: 系数(coefficient), e: 指数(exponent)
    bool hasOutput = false; // 用于标记是否有输出，处理零多项式的情况

    // 循环读取每一对数据
    while (cin >> c >> e) {
        // 如果指数为0（常数项），求导后为0，直接跳过不输出
        if (e != 0) {
            // 控制空格：只有不是第一个输出项时，才在前面打印空格
            if (hasOutput) {
                cout << " ";
            }
            
            // 输出导数：系数 * 指数，指数 - 1
            cout << c * e << " " << e - 1;
            
            hasOutput = true;
        }
    }

    // 特殊情况：如果输入是 "10 0" 这种常数多项式，或者全是常数项
    // 导致 hasOutput 依然为 false，题目要求输出 "0 0"
    if (!hasOutput) {
        cout << "0 0";
    }

    return 0;
}
