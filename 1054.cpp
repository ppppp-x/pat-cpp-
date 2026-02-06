#include <bits/stdc++.h>
using namespace std;

// 判断字符串是否为合法数字
bool isLegal(string s, double &val) {
    int dotCount = 0;
    int dotPos = -1;

    // 1. 检查字符合法性
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            if (i != 0) return false; // 负号只能在开头
        } else if (s[i] == '.') {
            if (dotCount > 0) return false; // 只能有一个小数点
            dotCount++;
            dotPos = i;
        } else if (!isdigit(s[i])) {
            return false; // 其他必须是数字
        }
    }

    // 2. 检查小数位数（不能超过2位）
    if (dotCount == 1) {
        if (s.length() - dotPos - 1 > 2) return false;
    }

    // 3. 检查数值范围
    try {
        val = stod(s); // 转换为double
        if (val < -1000 || val > 1000) return false;
    } catch(...) {
        return false; // 转换失败（如仅有一个"."）
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    int count = 0;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        double tempVal;
        if (isLegal(s, tempVal)) {
            count++;
            sum += tempVal;
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }

    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (count == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of %d numbers is %.2f\n", count, sum / count);

    return 0;
}