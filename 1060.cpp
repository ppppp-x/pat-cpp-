#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // 为了使用 greater

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0; // 增加读取保护

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. 从大到小排序 (Descend)
    // 这样 a[i] 就代表第 i+1 大的骑行距离
    sort(a.begin(), a.end(), greater<int>());

    int e = 0;
    // 2. 遍历查找
    for (int i = 0; i < n; i++) {
        // 这里的 i+1 代表天数
        // a[i] 代表当天的距离
        // 题目要求：距离 > 天数 (E天 超过 E英里)
        if (a[i] > i + 1) {
            e = i + 1;
        } else {
            // 因为是从大到小排序，如果当前的数已经不满足 > 天数
            // 后面更小的数肯定也不满足，直接退出
            break;
        }
    }

    cout << e << endl;
    return 0;
}