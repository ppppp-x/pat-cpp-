#include <iostream>
// 不需要 <bits/stdc++.h>，只用 iostream 即可，加快编译速度（在本地环境）
using namespace std;

int main() {
    // 优化 I/O 操作速度（对于大量数据输入很有用）
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // long long 确保范围覆盖 [-2^31, 2^31] 及其求和结果
    long long a, b, c; 

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        
        // 直接判断并输出，无需存储
        if (a + b > c) {
            cout << "Case #" << i + 1 << ": true" << endl;
        } else {
            cout << "Case #" << i + 1 << ": false" << endl;
        }
    }

    return 0;
}
