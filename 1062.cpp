#include <iostream>
#include <algorithm>
#include <cstdio> // 用于scanf

using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long n1, m1, n2, m2;
    int k;
    
    // 读取输入
    scanf("%lld/%lld %lld/%lld %d", &n1, &m1, &n2, &m2, &k);
    
    // 转化为浮点数确定左右边界（也可以用通分比较）
    double start = (double)n1 / m1;
    double end = (double)n2 / m2;
    
    // 题目可能给出大的在前，小的在后，需要确保 start < end
    if (start > end) {
        swap(start, end);
    }
    
    bool first = true; // 用于控制空格输出
    
    // 分子的可能范围是从 1 开始 (或者根据 start * k 估算起点)
    // 既然是找介于两者之间的，分子 x 满足: start * k < x < end * k
    // 我们直接遍历所有可能的分子，判断是否在区间内
    
    // 优化：不需要从1遍历到k，直接计算起止分子
    // 加上一个小量 1e-8 避免浮点误差，或者严格大于/小于
    int x_start = (int)(start * k) + 1; 
    // 注意：如果 start*k 正好是整数，需要判断是否严格大于
    // 最稳妥的方法是遍历 1 到 k (如果 k 不大)，判断值是否在范围内
    
    for (int i = 1; i < k; i++) {
        double val = (double)i / k;
        
        // 1. 判断是否在区间内 (严格大于 start 且 严格小于 end)
        if (val > start && val < end) {
            
            // 2. 判断是否是最简分数 (gcd == 1)
            if (gcd(i, k) == 1) {
                // 3. 格式化输出
                if (!first) {
                    printf(" ");
                }
                printf("%d/%d", i, k);
                first = false;
            }
        }
    }
    
    printf("\n");
    return 0;
}