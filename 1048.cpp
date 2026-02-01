#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    string c = "0123456789JQK";
    int index_a = a.length() - 1;
    int index_b = b.length() - 1;
    bool flag = true;
    while( index_a>= 0 && index_b>= 0){
        if(flag){
        //处理奇数位
            b[index_b] = c[(a[index_a] - '0'+ b[index_b] - '0') % 13];
        }else{
        //处理偶位数
            int temp = b[index_b] - a[index_a];
            if (temp < 0) temp = temp + 10;
            b[index_b] = temp + '0';
        }
        flag = !flag;
        index_a--;
        index_b--;
    }
    cout<<b<<endl;
    return 0;
}

//ai生成的标准答案
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     string a, b;
//     cin >> a >> b;
    
//     // 1. 长度处理：较短的字符串前面补 '0'，使其等长
//     int len_a = a.length();
//     int len_b = b.length();
//     if (len_a > len_b) {
//         // b 短，b 前面补 0
//         b.insert(0, len_a - len_b, '0');
//     } else {
//         // a 短，a 前面补 0
//         a.insert(0, len_b - len_a, '0');
//     }

//     string c = "0123456789JQK";
//     // 因为补齐了，现在长度一样，用 b 的长度即可
//     int index = b.length() - 1; 
    
//     // 题目定义倒数第1位是奇数位(1)，倒数第2位是偶数位(2)...
//     // 我们用一个变量来记录当前位数，或者直接用 bool flag 翻转
//     int pos = 1; // 记录当前是从右往左第几位

//     while(index >= 0){
//         // 注意：题目说个位是第1位（奇数），十位是第2位（偶数）
//         // 所以 pos % 2 != 0 是奇数位
//         if(pos % 2 != 0){
//             // 处理奇数位 (A + B) % 13
//             // 修正：先减 '0' 变成数字运算
//             int num_a = a[index] - '0';
//             int num_b = b[index] - '0';
//             b[index] = c[(num_a + num_b) % 13];
//         } else {
//             // 处理偶数位 B - A
//             int num_a = a[index] - '0';
//             int num_b = b[index] - '0';
//             int temp = num_b - num_a;
//             if (temp < 0) temp += 10;
            
//             // 修正：加上 '0' 变回字符
//             b[index] = temp + '0';
//         }
        
//         index--;
//         pos++;
//     }
    
//     cout << b << endl;
//     return 0;
// }