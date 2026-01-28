# PAT乙级 C++ 速查手册

> 快速查阅刷题所需的核心语法

---

## 1. 结构体与排序（高频⭐）

```cpp
struct Student {
    string name;
    int score;
};

// 自定义排序：分数降序，名字升序
bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
}

sort(students.begin(), students.end(), cmp);

// Lambda写法
sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.score != b.score ? a.score > b.score : a.name < b.name;
});
```

---

## 2. 输入输出

```cpp
// 加速（必加）
ios::sync_with_stdio(false);
cin.tie(nullptr);

// 读整行
getline(cin, line);

// cin >> 后接 getline 需跳过换行
cin >> n;
cin.ignore();
getline(cin, line);

// 读到文件结束
while (cin >> n) { }
```

---

## 3. 字符串

```cpp
s.length();              // 长度
s.substr(pos, len);      // 子串
s.find("xx");            // 查找，失败返回 string::npos
stoi(s);                 // string→int
to_string(num);          // int→string
reverse(s.begin(), s.end());  // 反转

// 字符判断
isalpha(c); isdigit(c); isupper(c); islower(c);
toupper(c); tolower(c);

// 分割字符串
stringstream ss(s);
string word;
while (ss >> word) { }       // 按空格分割
while (getline(ss, word, ',')) { }  // 按逗号分割
```

---

## 4. STL容器

| 容器 | 头文件 | 特点 | 常用操作 |
|------|--------|------|----------|
| `vector<T>` | `<vector>` | 动态数组 | `push_back`, `size`, `[]` |
| `map<K,V>` | `<map>` | 有序映射 | `mp[key]`, `count`, `find` |
| `unordered_map` | `<unordered_map>` | 哈希O(1) | 同map |
| `set<T>` | `<set>` | 有序去重集 | `insert`, `count`, `erase` |
| `stack<T>` | `<stack>` | 栈 | `push`, `pop`, `top` |
| `queue<T>` | `<queue>` | 队列 | `push`, `pop`, `front` |
| `priority_queue<T>` | `<queue>` | 大顶堆 | `push`, `pop`, `top` |

```cpp
// 小顶堆
priority_queue<int, vector<int>, greater<int>> minPq;
```

---

## 5. 常用算法

```cpp
#include <algorithm>

sort(v.begin(), v.end());                  // 升序
sort(v.begin(), v.end(), greater<int>());  // 降序
reverse(v.begin(), v.end());
max(a, b);  min(a, b);  swap(a, b);

// 二分查找（需有序）
binary_search(v.begin(), v.end(), x);
lower_bound(v.begin(), v.end(), x);  // 第一个 >= x
upper_bound(v.begin(), v.end(), x);  // 第一个 > x

// 去重
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// 累加
#include <numeric>
int sum = accumulate(v.begin(), v.end(), 0);
```

---

## 6. 数学

```cpp
#include <cmath>
abs(x); sqrt(x); pow(x, n); ceil(x); floor(x); round(x);

// 最大公约数
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// 素数判断
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// 进制转换
int n = stoi("1010", nullptr, 2);  // 二进制转十进制
```

---

## 7. 格式化输出

```cpp
// printf
printf("%05d", n);       // 宽度5，前导零
printf("%.2f", d);       // 保留2位小数

// cout
#include <iomanip>
cout << setw(5) << setfill('0') << n;     // 00042
cout << fixed << setprecision(2) << d;    // 3.14
```

---

## 8. 常用技巧

```cpp
// 回文判断
bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

// 闰年判断
bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

// 防超时：用 '\n' 代替 endl，用 += 代替 s = s + ...
```

---

## 9. 万能模板

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 代码
    
    return 0;
}
```

---

## 常见错误

| 问题 | 原因 |
|------|------|
| 答案错误 | 边界条件未处理 |
| 超时 | 复杂度高 / cin未加速 |
| 运行错误 | 数组越界 / 除零 |
| 格式错误 | 多余空格换行 |
