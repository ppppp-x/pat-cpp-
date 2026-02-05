#include <iostream>
#include <cmath>
#include <cstdio> // 使用printf方便格式化

using namespace std;

int main() {
    double R1, P1, R2, P2;
    // 1. 读取输入
    cin >> R1 >> P1 >> R2 >> P2;

    // 2. 计算乘积的模和幅角
    double R = R1 * R2;
    double P = P1 + P2;

    // 3. 转换为直角坐标 (实部A, 虚部B)
    double A = R * cos(P);
    double B = R * sin(P);

    // 4. 处理 -0.00 的情况 (关键步骤)
    // 如果数值很小，且是负数，四舍五入会导致 -0.00，需强制改为 0
    if (A < 0 && A > -0.005) A = 0;
    if (B < 0 && B > -0.005) B = 0;

    // 5. 格式化输出
    // 注意虚部B不仅要输出数值，还要根据符号决定是否输出 '+'
    // 题目要求输出格式为 A+Bi 或 A-Bi，printf的 %.2f 会自带负号，但正号需要自己处理
    if (B >= 0) {
        printf("%.2f+%.2fi\n", A, B);
    } else {
        printf("%.2f%.2fi\n", A, B); // B自带负号，所以不需要加符号
    }

    return 0;
}