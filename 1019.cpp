#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;

    do{
    	vector<int> num(4,0);
    	int n1 = 0,n2 = 0;
        s = to_string(n);
        for(int i = 0;i < s.length();i++){
            num[i] = s[i] - '0';
        }
        
        sort(num.begin(),num.end(),greater<int>());
        for(int i = 0;i < num.size();i++){
            n2 = 10 * n2 + num[i];
        }
        
        sort(num.begin(),num.end());
        for(int i = 0;i < num.size();i++){
            n1 = 10 * n1 + num[i];
        }
        
        n = n2 - n1;
        
        printf("%04d - %04d = %04d\n", n2, n1, n);
        if( n == 0) break;
    }while( n != 6174);

    return 0;
}
//满分代码(gemini3pro) 

//#include <iostream>
//#include <string>
//#include <algorithm> // 用于 sort
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//
//    // 核心逻辑：放在 do-while 里，保证至少执行一次（处理输入即为 6174 的情况）
//    do {
//        // 1. 补齐 4 位：如果长度不足 4，在前面补 '0'
//        // 例如输入 "1"，变成 "0001"
//        s.insert(0, 4 - s.length(), '0');
//
//        // 2. 获得最大数 (降序)
//        string max_s = s;
//        sort(max_s.begin(), max_s.end(), greater<char>());
//        int max_n = stoi(max_s); // 转成 int 方便计算
//
//        // 3. 获得最小数 (升序)
//        string min_s = s;
//        sort(min_s.begin(), min_s.end());
//        int min_n = stoi(min_s);
//
//        // 4. 计算差值
//        int diff = max_n - min_n;
//
//        // 5. 格式化输出
//        // %04d 意思是：输出整数，不足4位前面补0
//        printf("%04d - %04d = %04d\n", max_n, min_n, diff);
//
//        // 6. 判断退出条件
//        if (diff == 0 || diff == 6174) break;
//
//        // 7. 将差值转回 string，供下一次循环使用
//        s = to_string(diff);
//
//    } while (true);
//
//    return 0;
//}
