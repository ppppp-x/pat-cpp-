#include <iostream>
#include <vector>
#include <iomanip> // 用于 setprecision 控制输出精度
#include <algorithm> // 用于 max 函数

using namespace std;

int main() {
    // 1. 提速：关闭 stdio 同步，加快 cin/cout 速度（刷题好习惯）
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    cin >> n;

    // ans 存放 A1-A5 的计算结果
    // count 存放 A1-A5 每一类数字出现的次数
    vector<int> ans(5, 0);
    vector<int> count(5, 0);

    // 2. 逻辑：只遍历一遍，读入的同时直接处理
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << "正在处理数字: " << num << endl; // 加这一句测试
        int r = num % 5; // remainder 余数

        if (r == 0) {
            if (num % 2 == 0) {
                ans[0] += num;
                count[0]++;
            }
        } 
        else if (r == 1) {
            // 技巧：根据当前已有的个数决定符号。偶数个时(第0个,第2个...)做加法，奇数个时做减法
            int sign = (count[1] % 2 == 0) ? 1 : -1;
            ans[1] += sign * num;
            count[1]++;
        } 
        else if (r == 2) {
            // A3 本身就是计数值
            ans[2]++;
            count[2]++;
        } 
        else if (r == 3) {
            ans[3] += num; // 先累加总和，输出时再除以 count
            count[3]++;
        } 
        else if (r == 4) {
            // 如果是第一个数，直接赋值；否则取 max
            if (count[4] == 0) ans[4] = num;
            else ans[4] = max(ans[4], num);
            count[4]++;
        }
    }

    // 3. 输出：统一处理 "N" 的逻辑
    for (int i = 0; i < 5; i++) {
        if (i > 0) cout << " "; // 控制行内空格，行末不留空格

        if (count[i] == 0) {
            cout << "N";
            continue;
        }

        // 针对 A4 做特殊格式化处理
        if (i == 3) {
            cout << fixed << setprecision(1) << (double)ans[3] / count[3];
        } else {
            cout << ans[i];
        }
    }

    return 0;
}
