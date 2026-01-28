#include <iostream>
#include <cmath>
using namespace std;

// 判断是否为素数，复杂度 O(sqrt(n))
bool isPrime(int n) {
    if (n <= 1) return false;
    // 注意：使用 i * i <= n 避免浮点运算，且比 sqrt 更快
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int M, N;
    if (cin >> M >> N) { // 读取输入
        int count = 0;   // 记录目前找到了第几个素数
        int num = 2;     // 当前正在判断的数字，从2开始
        int printed = 0; // 记录已经打印了多少个素数（用于控制换行）

        while (count < N) {
            if (isPrime(num)) {
                count++;
                // 只有当 count 在 [M, N] 区间内才输出
                if (count >= M) {
                    printed++;
                    
                    // 格式控制核心逻辑：
                    // 1. 如果不是该行的第1个数，先输出空格
                    if (printed % 10 != 1) {
                        cout << " ";
                    }
                    
                    cout << num;
                    
                    // 2. 如果是该行的第10个数，输出换行
                    if (printed % 10 == 0) {
                        cout << endl;
                    }
                }
            }
            num++;
        }
    }
    return 0;
}
