# PAT乙级 C++ 必备语法知识

> 适用于有一定C++基础的同学，快速掌握PAT乙级刷题所需的核心语法和技巧

---

## 目录

1. [结构体与类](#1-结构体与类)
2. [输入输出](#2-输入输出)
3. [字符串处理](#3-字符串处理)
4. [STL容器](#4-stl容器)
5. [常用算法](#5-常用算法)
6. [数学相关](#6-数学相关)
7. [格式化输出](#7-格式化输出)
8. [常见技巧](#8-常见技巧)

---

## 1. 结构体与类

> 在PAT乙级中，结构体（struct）使用非常频繁，主要用于存储学生信息、成绩、时间等复合数据。类（class）相对较少使用，但掌握基础知识有助于理解面向对象编程。

### 1.1 结构体基础（struct）

```cpp
// 定义结构体
struct Student {
    string name;     // 姓名
    int age;         // 年龄
    double score;    // 成绩
};

int main() {
    // 创建结构体变量
    Student s1;
    s1.name = "Alice";
    s1.age = 20;
    s1.score = 95.5;
    
    // 初始化方式（C++11）
    Student s2 = {"Bob", 21, 88.0};
    
    // 使用成员
    cout << s1.name << " " << s1.score << endl;
    
    return 0;
}
```

### 1.2 结构体数组与vector

```cpp
// 结构体数组
Student students[100];
students[0].name = "Alice";

// 使用vector存储（推荐）
vector<Student> stuList;
stuList.push_back({"Alice", 20, 95.5});
stuList.push_back({"Bob", 21, 88.0});

// 遍历
for (int i = 0; i < stuList.size(); i++) {
    cout << stuList[i].name << endl;
}

// 或范围for循环
for (auto& s : stuList) {
    cout << s.name << " " << s.score << endl;
}
```

### 1.3 结构体排序（PAT高频考点⭐）

```cpp
struct Student {
    string name;
    int score;
};

// 方法1：自定义比较函数
bool cmp(Student a, Student b) {
    // 按分数降序排列，分数相同按姓名字典序升序
    if (a.score != b.score) {
        return a.score > b.score;  // 分数高的在前
    }
    return a.name < b.name;  // 姓名字典序小的在前
}

int main() {
    vector<Student> students = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 90}
    };
    
    sort(students.begin(), students.end(), cmp);
    
    // 方法2：Lambda表达式（更简洁）
    sort(students.begin(), students.end(), [](Student a, Student b) {
        if (a.score != b.score) return a.score > b.score;
        return a.name < b.name;
    });
    
    return 0;
}
```

### 1.4 结构体内置函数

```cpp
struct Student {
    string name;
    int score;
    
    // 构造函数（初始化更方便）
    Student() {}  // 默认构造函数
    Student(string n, int s) : name(n), score(s) {}
    
    // 成员函数
    void print() {
        cout << name << ": " << score << endl;
    }
    
    // 用于排序的比较运算符重载
    bool operator < (const Student& other) const {
        if (score != other.score) return score > other.score;
        return name < other.name;
    }
};

int main() {
    // 使用构造函数创建对象
    Student s1("Alice", 95);
    Student s2("Bob", 88);
    
    s1.print();  // 调用成员函数
    
    // 使用重载的 < 运算符排序
    vector<Student> students = {s1, s2};
    sort(students.begin(), students.end());  // 自动使用 operator<
    
    return 0;
}
```

### 1.5 类的基础（class）

```cpp
// class 与 struct 的区别：
// - struct 成员默认 public
// - class 成员默认 private

class Student {
private:  // 私有成员，外部不能直接访问
    string name;
    int score;
    
public:   // 公有成员，外部可以访问
    // 构造函数
    Student() : name(""), score(0) {}
    Student(string n, int s) : name(n), score(s) {}
    
    // getter 和 setter
    string getName() const { return name; }
    void setName(string n) { name = n; }
    
    int getScore() const { return score; }
    void setScore(int s) { score = s; }
    
    // 成员函数
    void print() const {
        cout << name << ": " << score << endl;
    }
    
    // 判断是否及格
    bool isPassed() const {
        return score >= 60;
    }
};

int main() {
    Student s1("Alice", 95);
    s1.print();
    
    cout << s1.getName() << endl;
    cout << (s1.isPassed() ? "及格" : "不及格") << endl;
    
    return 0;
}
```

### 1.6 运算符重载（进阶）

```cpp
struct Fraction {
    int num;   // 分子
    int den;   // 分母
    
    Fraction(int n = 0, int d = 1) : num(n), den(d) {}
    
    // 加法运算符重载
    Fraction operator + (const Fraction& other) const {
        return Fraction(
            num * other.den + other.num * den,
            den * other.den
        );
    }
    
    // 相等运算符重载
    bool operator == (const Fraction& other) const {
        return num * other.den == other.num * den;
    }
    
    // 小于运算符重载（用于排序）
    bool operator < (const Fraction& other) const {
        return num * other.den < other.num * den;
    }
    
    // 输出运算符重载（友元函数）
    friend ostream& operator << (ostream& os, const Fraction& f) {
        os << f.num << "/" << f.den;
        return os;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    
    Fraction sum = f1 + f2;
    cout << f1 << " + " << f2 << " = " << sum << endl;
    // 输出: 1/2 + 1/3 = 5/6
    
    return 0;
}
```

### 1.7 PAT常见结构体模板

```cpp
// 学生信息（最常用）
struct Student {
    string id;      // 准考证号
    string name;    // 姓名
    int score;      // 成绩
};

// 时间
struct Time {
    int hour, minute, second;
    
    // 转换为秒数，方便比较
    int toSeconds() const {
        return hour * 3600 + minute * 60 + second;
    }
    
    bool operator < (const Time& other) const {
        return toSeconds() < other.toSeconds();
    }
};

// 日期
struct Date {
    int year, month, day;
    
    bool operator < (const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

// 点坐标
struct Point {
    double x, y;
    
    // 计算到原点的距离
    double distance() const {
        return sqrt(x * x + y * y);
    }
    
    // 计算两点距离
    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// 记录（通用模板）
struct Record {
    string key;     // 键/ID
    int value;      // 值
    
    bool operator < (const Record& other) const {
        return value > other.value;  // 按value降序
    }
};
```

### 1.8 struct vs class 选择建议

| 场景 | 推荐使用 | 原因 |
|------|----------|------|
| PAT刷题 | struct | 语法简洁，成员默认public |
| 简单数据聚合 | struct | 如学生信息、坐标点等 |
| 需要封装 | class | 隐藏实现细节，提供接口 |
| 复杂逻辑 | class | 更符合面向对象设计 |

> 💡 **PAT刷题建议**：绝大多数情况使用 `struct` 即可，简单直接。只有在需要复杂封装时才考虑 `class`。

---

## 2. 输入输出

### 2.1 基础输入输出

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    double d;
    char c;
    
    // C++风格
    cin >> n >> d >> c;
    cout << n << " " << d << " " << c << endl;
    
    // C风格（更快，推荐PAT使用）
    scanf("%d %lf %c", &n, &d, &c);
    printf("%d %.2f %c\n", n, d, c);
    
    return 0;
}
```

### 2.2 加速输入输出

```cpp
// 在main函数开头添加，可显著加速cin/cout
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

### 2.3 读取整行

```cpp
#include <string>

string line;
getline(cin, line);  // 读取整行（包括空格）

// 注意：cin >> 后再用 getline 需要先吃掉换行符
int n;
cin >> n;
cin.ignore();  // 或 getline(cin, line); 忽略换行
getline(cin, line);
```

### 2.4 读取到文件结束

```cpp
int n;
while (cin >> n) {
    // 处理数据
}

// 或使用scanf
while (scanf("%d", &n) != EOF) {
    // 处理数据
}
```

---

## 3. 字符串处理

### 3.1 string 基本操作

```cpp
#include <string>

string s = "Hello";
string s2 = "World";

// 长度
int len = s.length();  // 或 s.size()

// 拼接
string s3 = s + " " + s2;  // "Hello World"

// 访问字符
char c = s[0];  // 'H'

// 子串
string sub = s.substr(1, 3);  // "ell" (从位置1开始，取3个字符)

// 查找
int pos = s.find("ll");  // 返回2，找不到返回 string::npos

// 替换
s.replace(0, 2, "YY");  // "YYllo"

// 插入
s.insert(2, "XX");  // 在位置2插入

// 删除
s.erase(0, 2);  // 删除从0开始的2个字符

// 比较
if (s == s2) { }
if (s < s2) { }  // 字典序比较

// 反转
reverse(s.begin(), s.end());
```

### 3.2 字符处理函数

```cpp
#include <cctype>

char c = 'A';

isalpha(c);  // 是否为字母
isdigit(c);  // 是否为数字
isalnum(c);  // 是否为字母或数字
isupper(c);  // 是否为大写
islower(c);  // 是否为小写
isspace(c);  // 是否为空白字符

toupper(c);  // 转大写
tolower(c);  // 转小写
```

### 3.3 字符串与数字转换

```cpp
#include <string>
#include <sstream>

// string → int/double
string s = "123";
int n = stoi(s);      // string to int
long l = stol(s);     // string to long
double d = stod(s);   // string to double

// int/double → string
int num = 123;
string str = to_string(num);

// 使用 stringstream（更灵活）
stringstream ss;
ss << 123;
string result;
ss >> result;  // result = "123"
```

### 3.4 分割字符串

```cpp
#include <sstream>

string s = "hello world test";
stringstream ss(s);
string word;
vector<string> words;

while (ss >> word) {
    words.push_back(word);
}

// 按特定分隔符分割
string s2 = "a,b,c,d";
stringstream ss2(s2);
string token;
while (getline(ss2, token, ',')) {
    cout << token << endl;
}
```

---

## 4. STL容器

### 4.1 vector（动态数组）

```cpp
#include <vector>

vector<int> v;           // 空vector
vector<int> v(10);       // 10个元素，默认值0
vector<int> v(10, 5);    // 10个元素，初始值5
vector<int> v = {1, 2, 3};

// 常用操作
v.push_back(x);     // 末尾添加
v.pop_back();       // 删除末尾
v.size();           // 大小
v.empty();          // 是否为空
v.clear();          // 清空
v[i];               // 访问第i个元素
v.front();          // 第一个元素
v.back();           // 最后一个元素
v.begin();          // 起始迭代器
v.end();            // 结束迭代器

// 遍历
for (int i = 0; i < v.size(); i++) {
    cout << v[i];
}
for (int x : v) {
    cout << x;
}
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it;
}
```

### 4.2 map（映射/字典）

```cpp
#include <map>

map<string, int> mp;

// 插入
mp["apple"] = 5;
mp.insert({"banana", 3});

// 访问
int count = mp["apple"];

// 检查是否存在
if (mp.find("apple") != mp.end()) { }
if (mp.count("apple") > 0) { }

// 遍历（按key字典序）
for (auto& p : mp) {
    cout << p.first << ": " << p.second << endl;
}

// 删除
mp.erase("apple");

// 大小
mp.size();
```

### 4.3 unordered_map（哈希表，更快）

```cpp
#include <unordered_map>

unordered_map<string, int> ump;
// 用法与map相同，但无序，查找更快 O(1)
```

### 4.4 set（集合，自动去重排序）

```cpp
#include <set>

set<int> s;

s.insert(5);
s.insert(3);
s.insert(5);  // 重复，不会插入

// 遍历（有序）
for (int x : s) {
    cout << x << " ";  // 输出 3 5
}

// 查找
if (s.find(5) != s.end()) { }
if (s.count(5) > 0) { }

// 删除
s.erase(5);
```

### 4.5 unordered_set

```cpp
#include <unordered_set>

unordered_set<int> us;
// 用法与set相同，但无序，操作更快 O(1)
```

### 4.6 stack（栈）

```cpp
#include <stack>

stack<int> st;

st.push(1);    // 入栈
st.pop();      // 出栈（无返回值）
st.top();      // 栈顶元素
st.empty();    // 是否为空
st.size();     // 大小
```

### 4.7 queue（队列）

```cpp
#include <queue>

queue<int> q;

q.push(1);     // 入队
q.pop();       // 出队
q.front();     // 队首
q.back();      // 队尾
q.empty();
q.size();
```

### 4.8 priority_queue（优先队列/堆）

```cpp
#include <queue>

// 默认大顶堆（最大的在顶部）
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(2);
pq.top();  // 3

// 小顶堆
priority_queue<int, vector<int>, greater<int>> minPq;

pq.push(x);
pq.pop();
pq.top();
```

---

## 5. 常用算法

### 5.1 排序

```cpp
#include <algorithm>

vector<int> v = {3, 1, 4, 1, 5};

// 升序排序
sort(v.begin(), v.end());

// 降序排序
sort(v.begin(), v.end(), greater<int>());

// 自定义排序
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // 降序
});

// 对数组排序
int arr[] = {3, 1, 4, 1, 5};
sort(arr, arr + 5);

// 结构体排序
struct Student {
    string name;
    int score;
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;  // 分数降序
    return a.name < b.name;  // 名字升序
}
sort(students.begin(), students.end(), cmp);
```

### 5.2 查找

```cpp
#include <algorithm>

vector<int> v = {1, 2, 3, 4, 5};

// 线性查找
auto it = find(v.begin(), v.end(), 3);

// 二分查找（需要有序）
bool found = binary_search(v.begin(), v.end(), 3);

// 下界（第一个 >= x 的位置）
auto lb = lower_bound(v.begin(), v.end(), 3);

// 上界（第一个 > x 的位置）
auto ub = upper_bound(v.begin(), v.end(), 3);
```

### 5.3 其他常用算法

```cpp
#include <algorithm>

// 最大最小
int maxVal = max(a, b);
int minVal = min(a, b);
int maxOf3 = max({a, b, c});

// 交换
swap(a, b);

// 反转
reverse(v.begin(), v.end());

// 去重（需要先排序）
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// 填充
fill(v.begin(), v.end(), 0);

// 累加
#include <numeric>
int sum = accumulate(v.begin(), v.end(), 0);

// 次序排列
next_permutation(v.begin(), v.end());  // 下一个排列
prev_permutation(v.begin(), v.end());  // 上一个排列
```

---

## 6. 数学相关

### 6.1 常用数学函数

```cpp
#include <cmath>

abs(x);      // 整数绝对值
fabs(x);     // 浮点数绝对值
sqrt(x);     // 平方根
pow(x, n);   // x的n次方
ceil(x);     // 向上取整
floor(x);    // 向下取整
round(x);    // 四舍五入
log(x);      // 自然对数
log10(x);    // 以10为底的对数
```

### 6.2 最大公约数与最小公倍数

```cpp
#include <algorithm>  // C++17: #include <numeric>

// C++17 及以上
int g = __gcd(a, b);  // 最大公约数（GCD）

// 或手写
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 最小公倍数（LCM）
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // 先除后乘防溢出
}
```

### 6.3 素数判断

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 埃氏筛（求1~n所有素数）
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
```

### 6.4 进制转换

```cpp
// 十进制转其他进制
string toBase(int n, int base) {
    if (n == 0) return "0";
    string result;
    bool negative = n < 0;
    n = abs(n);
    while (n > 0) {
        int digit = n % base;
        if (digit < 10) {
            result = char('0' + digit) + result;
        } else {
            result = char('A' + digit - 10) + result;
        }
        n /= base;
    }
    return negative ? "-" + result : result;
}

// 其他进制转十进制
int toDecimal(string s, int base) {
    int result = 0;
    for (char c : s) {
        result *= base;
        if (isdigit(c)) {
            result += c - '0';
        } else {
            result += toupper(c) - 'A' + 10;
        }
    }
    return result;
}

// 使用stoi转换（支持2-36进制）
int n = stoi("1010", nullptr, 2);  // 二进制转十进制，n = 10
```

---

## 7. 格式化输出

### 7.1 printf 格式化

```cpp
#include <cstdio>

int n = 42;
double d = 3.14159;

printf("%d\n", n);           // 整数
printf("%05d\n", n);         // 宽度5，前导零: 00042
printf("%-5d\n", n);         // 宽度5，左对齐
printf("%f\n", d);           // 浮点数
printf("%.2f\n", d);         // 保留2位小数: 3.14
printf("%8.2f\n", d);        // 宽度8，保留2位小数
printf("%s\n", "hello");     // 字符串
printf("%c\n", 'A');         // 字符
printf("%x\n", 255);         // 十六进制: ff
printf("%X\n", 255);         // 大写十六进制: FF
printf("%o\n", 8);           // 八进制: 10
printf("%ld\n", 123456789L); // long
printf("%lld\n", 1LL);       // long long
```

### 7.2 cout 格式化

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int n = 42;
double d = 3.14159;

// 设置宽度和填充
cout << setw(5) << n << endl;           // "   42"
cout << setw(5) << setfill('0') << n;   // "00042"

// 浮点数精度
cout << fixed << setprecision(2) << d;  // "3.14"

// 进制输出
cout << hex << 255;  // "ff"
cout << oct << 8;    // "10"
cout << dec << 42;   // "42"

// 左对齐
cout << left << setw(10) << "hello";
```

---

## 8. 常见技巧

### 8.1 大数处理（使用字符串）

```cpp
// 大数加法
string addStrings(string num1, string num2) {
    string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }
    return result;
}
```

### 8.2 回文判断

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// 或使用reverse
bool isPalindrome2(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
```

### 8.3 日期处理

```cpp
// 判断闰年
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 每月天数
int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 获取某月天数
int getDays(int year, int month) {
    if (month == 2 && isLeap(year)) return 29;
    return daysInMonth[month];
}
```

### 8.4 防止超时的技巧

```cpp
// 1. 使用 scanf/printf 代替 cin/cout
// 2. 或者加速 cin/cout
ios::sync_with_stdio(false);
cin.tie(nullptr);

// 3. 使用 '\n' 代替 endl
cout << "hello" << '\n';

// 4. 避免在循环中使用 string 的 + 拼接
// 不好
string s;
for (int i = 0; i < n; i++) {
    s = s + "a";  // O(n^2)
}
// 好
string s;
for (int i = 0; i < n; i++) {
    s += "a";  // O(n)
}

// 5. 预先分配vector大小
vector<int> v(n);  // 而不是一个个push_back
```

### 8.5 常用头文件（万能头）

```cpp
// PAT考试可以使用万能头文件
#include <bits/stdc++.h>
using namespace std;

// 但建议了解各个头文件的作用：
// <iostream>  - cin, cout
// <cstdio>    - scanf, printf
// <string>    - string类
// <vector>    - vector容器
// <map>       - map容器
// <set>       - set容器
// <queue>     - queue, priority_queue
// <stack>     - stack
// <algorithm> - sort, find, reverse等
// <cmath>     - 数学函数
// <cctype>    - 字符处理函数
// <sstream>   - stringstream
// <iomanip>   - 格式化输出
```

### 8.6 PAT乙级常用模板

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读取数据
    int n;
    cin >> n;
    
    // 处理逻辑
    
    // 输出结果
    
    return 0;
}
```

---

## 9. 刷题建议

1. **多做真题**：PAT乙级真题是最好的练习材料
2. **注意边界**：特别关注 n=0, n=1 等边界情况
3. **格式输出**：PAT对输出格式要求严格，注意空格和换行
4. **时间复杂度**：乙级一般 O(n²) 可以通过，但最好优化到 O(n log n)
5. **测试用例**：自己构造特殊测试用例，特别是边界情况

---

## 附：常见错误排查

| 问题 | 可能原因 |
|------|----------|
| 答案错误 | 边界条件未处理、算法逻辑错误 |
| 超时 | 复杂度过高、死循环、cin/cout未加速 |
| 运行错误 | 数组越界、除以零、空指针 |
| 格式错误 | 多余空格/换行、输出顺序错误 |
| 编译错误 | 语法错误、缺少头文件 |

---

> 📝 **提示**：本文档涵盖了PAT乙级刷题最常用的C++语法知识，建议收藏并在刷题时查阅。祝你刷题顺利，早日通过PAT乙级！
