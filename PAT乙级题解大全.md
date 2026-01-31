# PAT乙级题解大全

> 全部125道题目（1001-1125）C++解答与解析

---

## 目录

| 范围 | 题目 |
|------|------|
| [1001-1025](#1001-1025) | 基础入门 |
| [1026-1050](#1026-1050) | 字符串处理 |
| [1051-1075](#1051-1075) | 模拟算法 |
| [1076-1100](#1076-1100) | 进阶应用 |
| [1101-1125](#1101-1125) | 综合提高 |

---

## 1001-1025

### 1001 害死人不偿命的(3n+1)猜想 (15分)

**题目**：对任何正整数n，若n为偶数则n/2，若n为奇数则(3n+1)/2，反复操作直到n=1，统计操作次数。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = (3 * n + 1) / 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
```

**解析**：简单模拟，按规则循环直到n=1。时间O(logn)。

---

### 1002 写出这个数 (20分)

**题目**：读入一个整数，计算各位数字之和，用拼音输出。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s) sum += c - '0';
    string pinyin[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string result = to_string(sum);
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << pinyin[result[i] - '0'];
    }
    return 0;
}
```

**解析**：先求和，再逐位转拼音输出。用字符串处理大数。

---

### 1003 我要通过！ (20分)

**题目**：判断字符串是否满足PAT条件：xPATx形式，且中间T左边A个数*P左边字符数=T右边A个数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int p = s.find('P'), t = s.find('T');
        if (p == string::npos || t == string::npos || t - p <= 1) {
            cout << "NO" << endl;
            continue;
        }
        bool valid = true;
        int a = 0, b = t - p - 1, c = 0;
        for (int i = 0; i < p; i++) 
            if (s[i] == 'A') a++; else { valid = false; break; }
        for (int i = p + 1; i < t; i++)
            if (s[i] != 'A') { valid = false; break; }
        for (int i = t + 1; i < s.size(); i++)
            if (s[i] == 'A') c++; else { valid = false; break; }
        if (valid && b >= 1 && c == a * b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
```

**解析**：找P和T位置，统计各区域A的数量，验证a*b=c。

---

### 1004 成绩排名 (20分)

**题目**：找出N个学生中成绩最高和最低的学生。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string maxName, maxId, minName, minId;
    int maxScore = -1, minScore = 101;
    while (n--) {
        string name, id;
        int score;
        cin >> name >> id >> score;
        if (score > maxScore) { maxScore = score; maxName = name; maxId = id; }
        if (score < minScore) { minScore = score; minName = name; minId = id; }
    }
    cout << maxName << " " << maxId << endl;
    cout << minName << " " << minId << endl;
    return 0;
}
```

**解析**：遍历一次，记录最大最小值及对应信息。

---

### 1005 继续(3n+1)猜想 (25分)

**题目**：找出一组数中不会被其他数的变换序列覆盖的"关键数"。

```cpp
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, a[101];
    set<int> covered;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int t = a[i];
        while (t != 1) {
            if (t % 2 == 0) t /= 2;
            else t = (3 * t + 1) / 2;
            covered.insert(t);
        }
    }
    int result[101], cnt = 0;
    for (int i = 0; i < n; i++)
        if (covered.find(a[i]) == covered.end()) result[cnt++] = a[i];
    sort(result, result + cnt, greater<int>());
    for (int i = 0; i < cnt; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    return 0;
}
```

**解析**：用set记录所有中间数，输出未被覆盖的数（降序）。

---

### 1006 换个格式输出整数 (15分)

**题目**：把整数n拆成百位B、十位S、个位g的特殊格式输出。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n / 100; i++) cout << "B";
    for (int i = 0; i < n / 10 % 10; i++) cout << "S";
    for (int i = 1; i <= n % 10; i++) cout << i;
    return 0;
}
```

**解析**：分离百、十、个位，按规则输出对应字符。

---

### 1007 素数对猜想 (20分)

**题目**：统计不超过N的所有"素数对"（差为2的相邻素数）。

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n, cnt = 0, prev = 2;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        if (isPrime(i)) {
            if (i - prev == 2) cnt++;
            prev = i;
        }
    }
    cout << cnt << endl;
    return 0;
}
```

**解析**：遍历判断素数，记录相邻素数差为2的对数。

---

### 1008 数组元素循环右移问题 (20分)

**题目**：将数组循环右移M位。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m, a[101];
    cin >> n >> m;
    m %= n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[(n - m + i) % n];
    }
    return 0;
}
```

**解析**：利用取模计算新位置，直接输出。

---

### 1009 说反话 (20分)

**题目**：将句子中的单词逆序输出。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<string> words;
    while (cin >> s) words.push_back(s);
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    return 0;
}
```

**解析**：读入所有单词存入vector，逆序输出。

---

### 1010 一元多项式求导 (25分)

**题目**：对一元多项式求导输出。

```cpp
#include <iostream>
using namespace std;

int main() {
    int c, e, first = 1;
    while (cin >> c >> e) {
        if (e == 0) continue;
        if (!first) cout << " ";
        cout << c * e << " " << e - 1;
        first = 0;
    }
    if (first) cout << "0 0";
    return 0;
}
```

**解析**：依次读入系数和指数，求导后输出（指数0跳过）。

---

### 1011 A+B 和 C (15分)

**题目**：判断A+B是否大于C。

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << (a + b > c ? "true" : "false") << endl;
    }
    return 0;
}
```

**解析**：注意用long long防溢出。

---

### 1012 数字分类 (20分)

**题目**：将数字按条件分成5类并统计。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, a;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    int c2 = 0, c4 = 0, sign = 1;
    bool f1 = false, f2 = false, f3 = false, f4 = false, f5 = false;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a % 5 == 0 && a % 2 == 0) { a1 += a; f1 = true; }
        if (a % 5 == 1) { a2 += sign * a; sign *= -1; c2++; f2 = true; }
        if (a % 5 == 2) { a3++; f3 = true; }
        if (a % 5 == 3) { a4 += a; c4++; f4 = true; }
        if (a % 5 == 4) { if (a > a5) a5 = a; f5 = true; }
    }
    if (f1) cout << a1; else cout << "N"; cout << " ";
    if (f2) cout << a2; else cout << "N"; cout << " ";
    if (f3) cout << a3; else cout << "N"; cout << " ";
    if (f4) cout << fixed << setprecision(1) << (double)a4 / c4; else cout << "N"; cout << " ";
    if (f5) cout << a5; else cout << "N";
    return 0;
}
```

**解析**：按a%5分类，分别处理求和、交替和、计数、平均、最大值。

---

### 1013 数素数 (20分)

**题目**：输出第M到第N个素数。

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int m, n, cnt = 0, num = 2;
    cin >> m >> n;
    while (cnt < n) {
        if (isPrime(num)) {
            cnt++;
            if (cnt >= m) {
                cout << num;
                if (cnt < n) {
                    if ((cnt - m + 1) % 10 == 0) cout << endl;
                    else cout << " ";
                }
            }
        }
        num++;
    }
    return 0;
}
```

**解析**：逐个判断素数，计数到第N个，从第M个开始输出。

---

### 1014 福尔摩斯的约会 (20分)

**题目**：从两对字符串中解密约会日期时间。

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    string day[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i = 0, len = min(s1.size(), s2.size());
    while (i < len && !(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')) i++;
    cout << day[s1[i] - 'A'] << " ";
    i++;
    while (i < len && !(s1[i] == s2[i] && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')))) i++;
    int hour = (s1[i] >= 'A') ? s1[i] - 'A' + 10 : s1[i] - '0';
    printf("%02d:", hour);
    len = min(s3.size(), s4.size());
    for (i = 0; i < len; i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
```

**解析**：第一对找星期和小时，第二对字母相同位置为分钟。

---

### 1015 德才论 (25分)

**题目**：按德才分数对考生排名。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    int id, de, cai, total;
    int type;
};

bool cmp(Student a, Student b) {
    if (a.type != b.type) return a.type < b.type;
    if (a.total != b.total) return a.total > b.total;
    if (a.de != b.de) return a.de > b.de;
    return a.id < b.id;
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<Student> v;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.id >> s.de >> s.cai;
        if (s.de < l || s.cai < l) continue;
        s.total = s.de + s.cai;
        if (s.de >= h && s.cai >= h) s.type = 1;
        else if (s.de >= h) s.type = 2;
        else if (s.de >= s.cai) s.type = 3;
        else s.type = 4;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (auto& s : v)
        cout << s.id << " " << s.de << " " << s.cai << endl;
    return 0;
}
```

**解析**：按类别分组，组内按总分、德分、学号排序。

---

### 1016 部分A+B (15分)

**题目**：提取数字中的某个数字组成新数，求和。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    char da, db;
    cin >> a >> da >> b >> db;
    long long pa = 0, pb = 0;
    for (char c : a) if (c == da) pa = pa * 10 + (da - '0');
    for (char c : b) if (c == db) pb = pb * 10 + (db - '0');
    cout << pa + pb << endl;
    return 0;
}
```

**解析**：遍历统计指定数字出现次数，构造新数相加。

---

### 1017 A除以B (20分)

**题目**：大整数除法。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int b;
    cin >> a >> b;
    int r = 0;
    string ans;
    for (int i = 0; i < a.size(); i++) {
        r = r * 10 + a[i] - '0';
        ans += (r / b) + '0';
        r %= b;
    }
    int i = 0;
    while (i < ans.size() - 1 && ans[i] == '0') i++;
    cout << ans.substr(i) << " " << r << endl;
    return 0;
}
```

**解析**：模拟竖式除法，逐位处理。

---

### 1018 锤子剪刀布 (20分)

**题目**：统计猜拳游戏胜负平及最常出的手势。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w1 = 0, w2 = 0, t = 0;
    int a[3] = {0}, b[3] = {0}; // B C J
    auto idx = [](char c) { return c == 'B' ? 0 : (c == 'C' ? 1 : 2); };
    auto wins = [](char a, char b) { 
        return (a == 'B' && b == 'C') || (a == 'C' && b == 'J') || (a == 'J' && b == 'B'); 
    };
    while (n--) {
        char c1, c2;
        cin >> c1 >> c2;
        if (wins(c1, c2)) { w1++; a[idx(c1)]++; }
        else if (wins(c2, c1)) { w2++; b[idx(c2)]++; }
        else t++;
    }
    cout << w1 << " " << t << " " << w2 << endl;
    cout << w2 << " " << t << " " << w1 << endl;
    char m1 = a[0] >= a[1] && a[0] >= a[2] ? 'B' : (a[1] >= a[2] ? 'C' : 'J');
    char m2 = b[0] >= b[1] && b[0] >= b[2] ? 'B' : (b[1] >= b[2] ? 'C' : 'J');
    cout << m1 << " " << m2 << endl;
    return 0;
}
```

**解析**：统计胜负，记录每种手势获胜次数，找最多的。

---

### 1019 数字黑洞 (20分)

**题目**：卡普雷卡尔运算：4位数重排求差直到6174或0。

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    s = string(4 - s.size(), '0') + s;
    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), greater<char>());
        sort(b.begin(), b.end());
        int diff = stoi(a) - stoi(b);
        s = to_string(diff);
        s = string(4 - s.size(), '0') + s;
        cout << a << " - " << b << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}
```

**解析**：补齐4位，按降序升序排列相减，循环直到结果。

---

### 1020 月饼 (25分)

**题目**：贪心策略卖月饼获得最大收益。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Cake {
    double stock, price, unit;
} cakes[1001];

bool cmp(Cake a, Cake b) { return a.unit > b.unit; }

int main() {
    int n;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> cakes[i].stock;
    for (int i = 0; i < n; i++) {
        cin >> cakes[i].price;
        cakes[i].unit = cakes[i].price / cakes[i].stock;
    }
    sort(cakes, cakes + n, cmp);
    double ans = 0;
    for (int i = 0; i < n && d > 0; i++) {
        if (cakes[i].stock <= d) {
            ans += cakes[i].price;
            d -= cakes[i].stock;
        } else {
            ans += cakes[i].unit * d;
            d = 0;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
```

**解析**：按单价排序，贪心选取单价最高的月饼。

---

### 1021 个位数统计 (15分)

**题目**：统计大整数中每个数字出现次数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[10] = {0};
    for (char c : s) cnt[c - '0']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i] > 0) cout << i << ":" << cnt[i] << endl;
    return 0;
}
```

**解析**：用数组统计0-9每个数字出现次数。

---

### 1022 D进制的A+B (20分)

**题目**：计算A+B并转换为D进制。

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int sum = a + b;
    if (sum == 0) { cout << 0; return 0; }
    string s;
    while (sum > 0) {
        s = char(sum % d + '0') + s;
        sum /= d;
    }
    cout << s << endl;
    return 0;
}
```

**解析**：辗转相除法转进制。

---

### 1023 组个最小数 (20分)

**题目**：用给定数字组成最小的正整数。

```cpp
#include <iostream>
using namespace std;

int main() {
    int cnt[10];
    for (int i = 0; i < 10; i++) cin >> cnt[i];
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0) { cout << i; cnt[i]--; break; }
    }
    for (int i = 0; i < 10; i++)
        while (cnt[i]-- > 0) cout << i;
    return 0;
}
```

**解析**：首位选最小非零数字，其余从小到大输出。

---

### 1024 科学计数法 (20分)

**题目**：将科学计数法转为普通数字。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == '-') cout << '-';
    int ePos = s.find('E');
    string num = s[1] + s.substr(3, ePos - 3);
    int exp = stoi(s.substr(ePos + 1));
    if (exp >= 0) {
        if (exp < num.size() - 1) num.insert(exp + 1, ".");
        else num += string(exp - num.size() + 1, '0');
    } else {
        num = "0." + string(-exp - 1, '0') + num;
    }
    cout << num << endl;
    return 0;
}
```

**解析**：提取符号、数字、指数，根据指数移动小数点。

---

### 1025 反转链表 (25分)

**题目**：每K个节点反转链表。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int addr, data, next;
    int order;
} nodes[100005];

bool cmp(Node a, Node b) { return a.order < b.order; }

int main() {
    int first, n, k;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    int cnt = 0, p = first;
    while (p != -1) {
        nodes[p].order = cnt++;
        p = nodes[p].next;
    }
    for (int i = 0; i < 100005; i++)
        if (nodes[i].order < 0 || nodes[i].order >= cnt) nodes[i].order = 100005;
    sort(nodes, nodes + 100005, cmp);
    for (int i = 0; i < cnt - cnt % k; i += k)
        reverse(nodes + i, nodes + i + k);
    for (int i = 0; i < cnt - 1; i++)
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i+1].addr);
    printf("%05d %d -1\n", nodes[cnt-1].addr, nodes[cnt-1].data);
    return 0;
}
```

**解析**：链表存入数组排序，每K个反转，重新输出。

---

## 1026-1050

### 1026 程序运行时间 (15分)

**题目**：将时钟打点数转换为时:分:秒格式。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int c1, c2;
    cin >> c1 >> c2;
    int t = (c2 - c1 + 50) / 100;  // 四舍五入
    printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
    return 0;
}
```

**解析**：CLK_TCK=100，先四舍五入再转换时分秒。

---

### 1027 打印沙漏 (20分)

**题目**：用给定符号打印沙漏形状。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    int row = 1, used = 1;
    while (used + 2 * (row + 2) - 1 <= n) {
        row += 2;
        used += 2 * row - 1;
    }
    for (int i = row; i >= 1; i -= 2) {
        cout << string((row - i) / 2, ' ') << string(i, c) << endl;
    }
    for (int i = 3; i <= row; i += 2) {
        cout << string((row - i) / 2, ' ') << string(i, c) << endl;
    }
    cout << n - used << endl;
    return 0;
}
```

**解析**：计算最大行数，上半倒三角，下半正三角。

---

### 1028 人口普查 (20分)

**题目**：统计有效生日范围内最年长和最年轻的人。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string minDate = "2014/09/07", maxDate = "1814/09/06";
    string oldest, youngest, oldestDate = minDate, youngestDate = maxDate;
    int cnt = 0;
    while (n--) {
        string name, date;
        cin >> name >> date;
        if (date >= maxDate && date <= minDate) {
            cnt++;
            if (date < oldestDate) { oldestDate = date; oldest = name; }
            if (date > youngestDate) { youngestDate = date; youngest = name; }
        }
    }
    if (cnt == 0) cout << 0 << endl;
    else cout << cnt << " " << oldest << " " << youngest << endl;
    return 0;
}
```

**解析**：日期字符串可直接比较，注意日期范围和边界。

---

### 1029 旧键盘 (20分)

**题目**：找出坏掉的键（输出时大写）。

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> typed, printed;
    for (char c : s2) typed.insert(toupper(c));
    for (char c : s1) {
        char upper = toupper(c);
        if (typed.find(upper) == typed.end() && printed.find(upper) == printed.end()) {
            cout << upper;
            printed.insert(upper);
        }
    }
    return 0;
}
```

**解析**：比较两串，找出s1中有但s2中没有的字符。

---

### 1030 完美数列 (25分)

**题目**：找出最多能选多少个数使max<=min*p。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    long long a[100005];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 1, j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= a[i] * p) j++;
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}
```

**解析**：排序后双指针/二分查找。

---

### 1031 查验身份证 (15分)

**题目**：验证身份证号码是否有效。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char check[] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int n;
    cin >> n;
    bool allPass = true;
    while (n--) {
        string s;
        cin >> s;
        int sum = 0;
        bool valid = true;
        for (int i = 0; i < 17; i++) {
            if (!isdigit(s[i])) valid = false;
            sum += (s[i] - '0') * weight[i];
        }
        if (!valid || s[17] != check[sum % 11]) {
            cout << s << endl;
            allPass = false;
        }
    }
    if (allPass) cout << "All passed" << endl;
    return 0;
}
```

**解析**：按身份证校验规则计算校验码。

---

### 1032 挖掘机技术哪家强 (20分)

**题目**：统计各学校总分，输出最高分学校。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, scores[100005] = {0};
    cin >> n;
    while (n--) {
        int id, score;
        cin >> id >> score;
        scores[id] += score;
    }
    int maxId = 1, maxScore = scores[1];
    for (int i = 2; i <= 100000; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxId = i;
        }
    }
    cout << maxId << " " << maxScore << endl;
    return 0;
}
```

**解析**：数组统计各校总分，找最大值。

---

### 1033 旧键盘打字 (20分)

**题目**：模拟坏键盘打字效果。

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string bad, s;
    getline(cin, bad);
    getline(cin, s);
    set<char> broken;
    for (char c : bad) broken.insert(toupper(c));
    for (char c : s) {
        if (broken.count(toupper(c))) continue;
        if (isupper(c) && broken.count('+')) continue;
        cout << c;
    }
    return 0;
}
```

**解析**：坏键无法输出，上档键坏则大写无法输出。

---

### 1034 有理数四则运算 (20分)

**题目**：两个有理数的加减乘除运算。

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

string format(long long a, long long b) {
    if (b == 0) return "Inf";
    if (a == 0) return "0";
    string s = (a < 0) != (b < 0) ? "(-" : "";
    a = abs(a); b = abs(b);
    long long g = gcd(a, b);
    a /= g; b /= g;
    if (a >= b) {
        s += to_string(a / b);
        a %= b;
        if (a > 0) s += " " + to_string(a) + "/" + to_string(b);
    } else {
        s += to_string(a) + "/" + to_string(b);
    }
    if (s[0] == '(') s += ")";
    return s;
}

int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    cout << format(a1, b1) << " + " << format(a2, b2) << " = " << format(a1*b2 + a2*b1, b1*b2) << endl;
    cout << format(a1, b1) << " - " << format(a2, b2) << " = " << format(a1*b2 - a2*b1, b1*b2) << endl;
    cout << format(a1, b1) << " * " << format(a2, b2) << " = " << format(a1*a2, b1*b2) << endl;
    cout << format(a1, b1) << " / " << format(a2, b2) << " = " << format(a1*b2, b1*a2) << endl;
    return 0;
}
```

**解析**：分数运算+格式化输出，注意符号和约分。

---

### 1035 插入与归并 (25分)

**题目**：判断是插入排序还是归并排序的中间状态。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[101], b[101];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i+1]; i++);
    for (j = i + 1; j < n && a[j] == b[j]; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(b, b + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1;
        while (1) {
            k *= 2;
            bool same = true;
            for (int x = 0; x < n; x++) if (a[x] != b[x]) same = false;
            for (int x = 0; x < n; x += k)
                sort(a + x, a + min(x + k, n));
            if (same) break;
        }
    }
    for (int x = 0; x < n; x++) {
        if (x > 0) cout << " ";
        cout << b[x];
    }
    return 0;
}
```

**解析**：插入排序前部有序且后部不变，归并排序模拟迭代。

---

### 1036 跟奥巴马一起编程 (15分)

**题目**：打印指定字符构成的矩形框。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    int row = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    cout << string(n, c) << endl;
    for (int i = 1; i < row - 1; i++)
        cout << c << string(n - 2, ' ') << c << endl;
    if (row > 1) cout << string(n, c) << endl;
    return 0;
}
```

**解析**：首尾行全填充，中间行只填首尾。

---

### 1037 在霍格沃茨找零钱 (20分)

**题目**：哈利波特魔法货币计算。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int t1 = g1 * 17 * 29 + s1 * 29 + k1;
    int t2 = g2 * 17 * 29 + s2 * 29 + k2;
    int diff = t2 - t1;
    if (diff < 0) { cout << "-"; diff = -diff; }
    printf("%d.%d.%d\n", diff / 17 / 29, diff / 29 % 17, diff % 29);
    return 0;
}
```

**解析**：全转Knut计算，再转回三种货币。

---

### 1038 统计同成绩学生 (20分)

**题目**：查询各分数的学生人数。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, cnt[101] = {0};
    cin >> n;
    while (n--) {
        int s;
        cin >> s;
        cnt[s]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        if (i > 0) cout << " ";
        cout << cnt[q];
    }
    return 0;
}
```

**解析**：数组统计各分数人数，直接查询。

---

### 1039 到底买不买 (20分)

**题目**：判断珠子是否足够。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int cnt[128] = {0};
    for (char c : s1) cnt[c]++;
    int need = 0;
    for (char c : s2) {
        if (cnt[c] > 0) cnt[c]--;
        else need++;
    }
    if (need > 0) cout << "No " << need << endl;
    else {
        int extra = 0;
        for (int i = 0; i < 128; i++) extra += cnt[i];
        cout << "Yes " << extra << endl;
    }
    return 0;
}
```

**解析**：统计需要的珠子，检查是否足够。

---

### 1040 有几个PAT (25分)

**题目**：统计字符串中PAT组合的个数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long countP = 0, countPA = 0, ans = 0;
    for (char c : s) {
        if (c == 'P') countP++;
        else if (c == 'A') countPA += countP;
        else if (c == 'T') ans += countPA;
    }
    cout << ans % 1000000007 << endl;
    return 0;
}
```

**解析**：统计每个位置前P的个数和PA的个数，遇T累加。

---

### 1041 考试座位号 (15分)

**题目**：根据试机座位号查询考试座位号。

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    int examSeat;
} students[1001];

int main() {
    int n;
    cin >> n;
    while (n--) {
        string id;
        int t, e;
        cin >> id >> t >> e;
        students[t].id = id;
        students[t].examSeat = e;
    }
    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        cout << students[q].id << " " << students[q].examSeat << endl;
    }
    return 0;
}
```

**解析**：以试机座位号为索引存储信息。

---

### 1042 字符统计 (20分)

**题目**：统计出现最多的英文字母。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int cnt[26] = {0};
    for (char c : s) {
        if (isalpha(c)) cnt[tolower(c) - 'a']++;
    }
    int maxIdx = 0;
    for (int i = 1; i < 26; i++) {
        if (cnt[i] > cnt[maxIdx]) maxIdx = i;
    }
    cout << char('a' + maxIdx) << " " << cnt[maxIdx] << endl;
    return 0;
}
```

**解析**：转小写统计，找最大值（相同取字母序小的）。

---

### 1043 输出PATest (20分)

**题目**：将字符串中PATest字符按特定顺序输出。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[6] = {0};
    string pat = "PATest";
    for (char c : s) {
        for (int i = 0; i < 6; i++)
            if (c == pat[i]) { cnt[i]++; break; }
    }
    while (cnt[0] || cnt[1] || cnt[2] || cnt[3] || cnt[4] || cnt[5]) {
        for (int i = 0; i < 6; i++) {
            if (cnt[i] > 0) { cout << pat[i]; cnt[i]--; }
        }
    }
    return 0;
}
```

**解析**：统计PATest各字符数量，循环输出。

---

### 1044 火星数字 (20分)

**题目**：地球数字与火星数字互转。

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string low[] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[] = {"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        if (isdigit(s[0])) {
            int num = stoi(s);
            if (num >= 13) {
                cout << high[num / 13];
                if (num % 13) cout << " " << low[num % 13];
            } else {
                cout << low[num];
            }
        } else {
            int ans = 0;
            stringstream ss(s);
            string w;
            while (ss >> w) {
                for (int i = 1; i <= 12; i++)
                    if (w == high[i]) ans += i * 13;
                for (int i = 0; i <= 12; i++)
                    if (w == low[i]) ans += i;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}
```

**解析**：13进制转换，高位和低位用不同词汇表。

---

### 1045 快速排序 (25分)

**题目**：找出可能作为主元的元素。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[100005], maxLeft[100005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    maxLeft[0] = 0;
    for (int i = 1; i < n; i++) maxLeft[i] = max(maxLeft[i-1], a[i-1]);
    int minRight = a[n-1];
    int result[100005], cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxLeft[i] && a[i] <= minRight) result[cnt++] = a[i];
        minRight = min(minRight, a[i]);
    }
    sort(result, result + cnt);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    if (cnt == 0) cout << endl;
    cout << endl;
    return 0;
}
```

**解析**：主元条件：大于左边所有数，小于等于右边所有数。

---

### 1046 划拳 (15分)

**题目**：统计划拳游戏中各方喝酒次数。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 0;
    cin >> n;
    while (n--) {
        int h1, c1, h2, c2;
        cin >> h1 >> c1 >> h2 >> c2;
        int sum = h1 + h2;
        if (c1 == sum && c2 != sum) b++;
        if (c2 == sum && c1 != sum) a++;
    }
    cout << a << " " << b << endl;
    return 0;
}
```

**解析**：猜对者让对方喝酒，统计双方喝酒次数。

---

### 1047 编程团体赛 (20分)

**题目**：统计团队总分并排名。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, scores[1001] = {0};
    cin >> n;
    while (n--) {
        int team, member, score;
        scanf("%d-%d %d", &team, &member, &score);
        scores[team] += score;
    }
    int maxTeam = 1;
    for (int i = 2; i <= 1000; i++) {
        if (scores[i] > scores[maxTeam]) maxTeam = i;
    }
    cout << maxTeam << " " << scores[maxTeam] << endl;
    return 0;
}
```

**解析**：按队伍号统计总分，找最高分队伍。

---

### 1048 数字加密 (20分)

**题目**：按特定规则对数字加密。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
    string result;
    for (int i = a.size() - 1, pos = 1; i >= 0; i--, pos++) {
        int da = a[i] - '0', db = b[i] - '0';
        if (pos % 2 == 1) {
            result = char((da + db) % 10 + '0') + result;
        } else {
            int diff = db - da;
            if (diff < 0) diff += 10;
            result = (diff < 10 ? char(diff + '0') : char(diff - 10 + 'A')) + result;
        }
    }
    cout << result << endl;
    return 0;
}
```

**解析**：奇数位相加取个位，偶数位相减（负数+10）。

---

### 1049 数列的片段和 (20分)

**题目**：计算所有连续子数列片段和的总和。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double a;
        cin >> a;
        sum += a * i * (n - i + 1);
    }
    printf("%.2f\n", sum);
    return 0;
}
```

**解析**：第i个元素出现次数 = i * (n-i+1)。

---

### 1050 螺旋矩阵 (25分)

**题目**：将数字按螺旋顺序填入矩阵。

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, a[10001], matrix[101][101] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int m = sqrt((double)n), col;
    while (n % m) m++;
    col = n / m;
    int row = m;
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    int idx = 0;
    while (idx < n) {
        for (int i = left; i <= right && idx < n; i++) matrix[top][i] = a[idx++];
        top++;
        for (int i = top; i <= bottom && idx < n; i++) matrix[i][right] = a[idx++];
        right--;
        for (int i = right; i >= left && idx < n; i--) matrix[bottom][i] = a[idx++];
        bottom--;
        for (int i = bottom; i >= top && idx < n; i--) matrix[i][left] = a[idx++];
        left++;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j > 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
```

**解析**：先排序再螺旋填充，注意行列计算。

---

## 1051-1075

### 1051 复数乘法 (15分)

**题目**：计算两个复数的乘积。

```cpp
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double r = r1 * r2;
    double p = p1 + p2;
    double real = r * cos(p);
    double imag = r * sin(p);
    if (fabs(real) < 0.005) real = 0;
    if (fabs(imag) < 0.005) imag = 0;
    printf("%.2f%+.2fi\n", real, imag);
    return 0;
}
```

**解析**：极坐标相乘：模相乘，角相加，转直角坐标。

---

### 1052 卖个萌 (20分)

**题目**：根据输入组合表情。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<string>> parts(3);
    for (int i = 0; i < 3; i++) {
        string line;
        getline(cin, line);
        string cur;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '[') cur = "";
            else if (line[j] == ']') parts[i].push_back(cur);
            else cur += line[j];
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a < 1 || a > parts[0].size() || b < 1 || b > parts[1].size() ||
            c < 1 || c > parts[0].size() || d < 1 || d > parts[1].size() ||
            e < 1 || e > parts[2].size()) {
            cout << "Are you kidding me? @\\/@" << endl;
        } else {
            cout << parts[0][a-1] << "(" << parts[1][b-1] << parts[2][e-1] 
                 << parts[1][d-1] << ")" << parts[0][c-1] << endl;
        }
    }
    return 0;
}
```

**解析**：解析方括号内容存入vector，按索引组合输出。

---

### 1053 住房空置率 (20分)

**题目**：统计空置房和可能空置房的比例。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, d;
    double e;
    cin >> n >> d >> e;
    int maybe = 0, empty = 0;
    while (n--) {
        int k, cnt = 0;
        cin >> k;
        for (int i = 0; i < k; i++) {
            double x;
            cin >> x;
            if (x < e) cnt++;
        }
        if (cnt > k / 2.0) {
            if (k > d) empty++;
            else maybe++;
        }
    }
    printf("%.1f%% %.1f%%\n", maybe * 100.0 / (n == 0 ? 1 : maybe + empty + n), 
           empty * 100.0 / (n == 0 ? 1 : maybe + empty + n));
    return 0;
}
```

**解析**：统计低于阈值天数超过一半的房屋，按时长分类。

---

### 1054 求平均值 (20分)

**题目**：过滤非法输入后求平均值。

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, cnt = 0;
    double sum = 0;
    cin >> n;
    while (n--) {
        char s[50];
        double num;
        cin >> s;
        int flag = sscanf(s, "%lf", &num);
        char check[50];
        sprintf(check, "%.2f", num);
        bool valid = (flag == 1 && strlen(s) == strlen(check) && 
                      num >= -1000 && num <= 1000);
        if (!valid) {
            printf("ERROR: %s is not a legal number\n", s);
        } else {
            sum += num;
            cnt++;
        }
    }
    if (cnt == 0) printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1) printf("The average of 1 number is %.2f\n", sum);
    else printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    return 0;
}
```

**解析**：用sscanf和sprintf验证输入合法性。

---

### 1055 集体照 (25分)

**题目**：按身高排列集体照站位。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int height;
};

bool cmp(Person a, Person b) {
    if (a.height != b.height) return a.height > b.height;
    return a.name < b.name;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Person> people(n);
    for (int i = 0; i < n; i++) cin >> people[i].name >> people[i].height;
    sort(people.begin(), people.end(), cmp);
    int idx = 0;
    for (int row = 0; row < k; row++) {
        int num = n / k + (row < n % k ? 1 : 0);
        vector<string> line(num);
        int mid = num / 2;
        for (int i = 0, left = mid, right = mid + 1; i < num; i++) {
            if (i % 2 == 0) line[left--] = people[idx++].name;
            else line[right++] = people[idx++].name;
        }
        for (int i = 0; i < num; i++) {
            if (i > 0) cout << " ";
            cout << line[i];
        }
        cout << endl;
    }
    return 0;
}
```

**解析**：排序后从中间向两边交替排列。

---

### 1056 组合数的和 (15分)

**题目**：计算所有两数组合的和。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, a[10], sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) sum += a[i] * 10 + a[j];
        }
    }
    cout << sum << endl;
    return 0;
}
```

**解析**：双重循环枚举所有两位数组合。

---

### 1057 数零壹 (20分)

**题目**：将字符串转数字相加，转二进制统计0和1个数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    for (char c : s) {
        if (isalpha(c)) sum += tolower(c) - 'a' + 1;
    }
    int cnt0 = 0, cnt1 = 0;
    if (sum == 0) cnt0 = 1;
    while (sum > 0) {
        if (sum % 2 == 0) cnt0++;
        else cnt1++;
        sum /= 2;
    }
    cout << cnt0 << " " << cnt1 << endl;
    return 0;
}
```

**解析**：字母转1-26求和，转二进制统计。

---

### 1058 选择题 (20分)

**题目**：批改选择题并统计错误最多的题目。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> score(m), options(m), correct_cnt(m);
    vector<string> correct(m);
    vector<int> wrong(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> score[i] >> options[i] >> correct_cnt[i];
        string ans;
        for (int j = 0; j < correct_cnt[i]; j++) {
            char c; cin >> c;
            ans += c;
        }
        correct[i] = ans;
    }
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < m; j++) {
            int cnt; char c;
            cin >> c >> cnt >> c;
            string ans;
            for (int k = 0; k < cnt; k++) {
                cin >> c;
                ans += c;
                if (k < cnt - 1) cin >> c;
            }
            cin >> c;
            if (ans == correct[j]) total += score[j];
            else wrong[j]++;
        }
        cout << total << endl;
    }
    int maxWrong = 0;
    for (int i = 0; i < m; i++) maxWrong = max(maxWrong, wrong[i]);
    if (maxWrong == 0) cout << "Too simple" << endl;
    else {
        cout << maxWrong;
        for (int i = 0; i < m; i++)
            if (wrong[i] == maxWrong) cout << " " << i + 1;
        cout << endl;
    }
    return 0;
}
```

**解析**：解析复杂输入格式，统计错误次数。

---

### 1059 C语言竞赛 (20分)

**题目**：根据排名分配奖励。

```cpp
#include <iostream>
#include <map>
#include <set>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    map<string, int> rank;
    for (int i = 1; i <= n; i++) {
        string id;
        cin >> id;
        rank[id] = i;
    }
    int k;
    cin >> k;
    set<string> checked;
    while (k--) {
        string id;
        cin >> id;
        cout << id << ": ";
        if (rank.find(id) == rank.end()) cout << "Are you kidding?" << endl;
        else if (checked.count(id)) cout << "Checked" << endl;
        else {
            checked.insert(id);
            int r = rank[id];
            if (r == 1) cout << "Mystery Award" << endl;
            else if (isPrime(r)) cout << "Minion" << endl;
            else cout << "Chocolate" << endl;
        }
    }
    return 0;
}
```

**解析**：用map存排名，set记录已领奖者。

---

### 1060 爱丁顿数 (25分)

**题目**：找出满足条件的最大E值。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[100005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int e = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) e = i + 1;
        else break;
    }
    cout << e << endl;
    return 0;
}
```

**解析**：降序排序后找最大的i+1使得a[i]>i+1。

---

### 1061 判断题 (15分)

**题目**：批改判断题计算总分。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int score[101], correct[101];
    for (int i = 0; i < m; i++) cin >> score[i];
    for (int i = 0; i < m; i++) cin >> correct[i];
    while (n--) {
        int total = 0;
        for (int i = 0; i < m; i++) {
            int ans;
            cin >> ans;
            if (ans == correct[i]) total += score[i];
        }
        cout << total << endl;
    }
    return 0;
}
```

**解析**：逐题对比答案累加分数。

---

### 1062 最简分数 (20分)

**题目**：在范围内找所有最简分数。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int a1, b1, a2, b2, k;
    scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &k);
    if (a1 * b2 > a2 * b1) { swap(a1, a2); swap(b1, b2); }
    bool first = true;
    for (int i = 1; i < k; i++) {
        if (i * b1 > a1 * k && i * b2 < a2 * k && gcd(i, k) == 1) {
            if (!first) cout << " ";
            cout << i << "/" << k;
            first = false;
        }
    }
    return 0;
}
```

**解析**：枚举分子，检查范围和互质条件。

---

### 1063 计算谱半径 (20分)

**题目**：计算复数集合的谱半径（最大模）。

```cpp
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    double maxR = 0;
    while (n--) {
        double a, b;
        cin >> a >> b;
        maxR = max(maxR, sqrt(a * a + b * b));
    }
    printf("%.2f\n", maxR);
    return 0;
}
```

**解析**：求所有复数模的最大值。

---

### 1064 朋友数 (20分)

**题目**：找出各位数字和相同的"朋友"数。

```cpp
#include <iostream>
#include <set>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) { sum += n % 10; n /= 10; }
    return sum;
}

int main() {
    int n;
    cin >> n;
    set<int> friends;
    while (n--) {
        int x;
        cin >> x;
        friends.insert(digitSum(x));
    }
    cout << friends.size() << endl;
    bool first = true;
    for (int x : friends) {
        if (!first) cout << " ";
        cout << x;
        first = false;
    }
    return 0;
}
```

**解析**：用set存储所有不同的数字和。

---

### 1065 单身狗 (25分)

**题目**：找出派对中的单身者。

```cpp
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> couple;
    while (n--) {
        int a, b;
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }
    int m;
    cin >> m;
    set<int> guests;
    while (m--) {
        int x;
        cin >> x;
        guests.insert(x);
    }
    vector<int> singles;
    for (int g : guests) {
        if (couple.find(g) == couple.end() || guests.find(couple[g]) == guests.end())
            singles.push_back(g);
    }
    sort(singles.begin(), singles.end());
    cout << singles.size() << endl;
    for (int i = 0; i < singles.size(); i++) {
        if (i > 0) cout << " ";
        printf("%05d", singles[i]);
    }
    if (singles.empty()) cout << endl;
    return 0;
}
```

**解析**：没有伴侣或伴侣不在场的都是单身狗。

---

### 1066 图像过滤 (15分)

**题目**：将指定范围内的像素替换。

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, n, a, b, t;
    cin >> m >> n >> a >> b >> t;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (j > 0) cout << " ";
            printf("%03d", (x >= a && x <= b) ? t : x);
        }
        cout << endl;
    }
    return 0;
}
```

**解析**：遍历像素，范围内替换。

---

### 1067 试密码 (20分)

**题目**：模拟密码验证过程。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string pwd;
    int n;
    getline(cin, pwd);
    n = stoi(pwd.substr(pwd.rfind(' ') + 1));
    pwd = pwd.substr(0, pwd.rfind(' '));
    string input;
    int cnt = 0;
    while (getline(cin, input) && input != "#") {
        if (input == pwd) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cout << "Wrong password: " << input << endl;
            if (++cnt >= n) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}
```

**解析**：记录错误次数，达到上限时锁定账户。

---

### 1068 万绿丛中一点红 (20分)

**题目**：找图像中唯一的特殊点。

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int a[1001][1001];

int main() {
    int m, n, tol;
    cin >> m >> n >> tol;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int cnt = 0, resX, resY, resC;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool unique = true;
            for (int k = 0; k < 8 && unique; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                    if (abs(a[i][j] - a[ni][nj]) <= tol) unique = false;
            }
            if (unique) { cnt++; resX = j + 1; resY = i + 1; resC = a[i][j]; }
        }
    }
    if (cnt == 0) cout << "Not Exist" << endl;
    else if (cnt > 1) cout << "Not Unique" << endl;
    else cout << "(" << resX << ", " << resY << "): " << resC << endl;
    return 0;
}
```

**解析**：8邻域检查，确保唯一特殊点。

---

### 1069 微博转发抽奖 (20分)

**题目**：按间隔抽取中奖者（跳过重复）。

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    set<string> winners;
    bool hasWinner = false;
    for (int i = 1; i <= m; i++) {
        string name;
        cin >> name;
        if (i == s || (i > s && (i - s) % n == 0 && winners.find(name) == winners.end())) {
            if (winners.find(name) != winners.end()) continue;
            if (i >= s && ((i - s) % n == 0)) {
                if (winners.find(name) == winners.end()) {
                    cout << name << endl;
                    winners.insert(name);
                    hasWinner = true;
                }
            }
        }
    }
    // 简化重写
    return 0;
}
```

**解析**：从s开始每隔n个抽取，去重后输出。

---

### 1070 结绳 (25分)

**题目**：用贪心策略最大化最终绳长。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10001];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    double len = a[0];
    for (int i = 1; i < n; i++)
        len = (len + a[i]) / 2;
    cout << (int)len << endl;
    return 0;
}
```

**解析**：从最短的开始结，贪心保证最长。

---

### 1071 小赌怡情 (15分)

**题目**：模拟猜大小赌博游戏。

```cpp
#include <iostream>
using namespace std;

int main() {
    int t, k;
    cin >> t >> k;
    while (k--) {
        int n1, b, n2;
        char c;
        cin >> n1 >> b >> c >> n2;
        if (b > t) {
            cout << "Not enough tokens.  Total = " << t << "." << endl;
        } else {
            bool win = (c == 'd' && n2 > n1) || (c == 'x' && n2 < n1);
            if (win) {
                t += b;
                cout << "Win " << b << "!  Total = " << t << "." << endl;
            } else {
                t -= b;
                cout << "Lose " << b << ".  Total = " << t << "." << endl;
                if (t == 0) { cout << "Game Over." << endl; break; }
            }
        }
    }
    return 0;
}
```

**解析**：按规则判断输赢，更新余额。

---

### 1072 开学寄语 (20分)

**题目**：检查学生携带的违禁物品。

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<string> banned;
    while (m--) {
        string s;
        cin >> s;
        banned.insert(s);
    }
    int students = 0, items = 0;
    while (n--) {
        string name;
        int k;
        cin >> name >> k;
        bool found = false;
        string line = name;
        while (k--) {
            string item;
            cin >> item;
            if (banned.count(item)) {
                line += " " + item;
                found = true;
                items++;
            }
        }
        if (found) {
            cout << line << endl;
            students++;
        }
    }
    cout << students << " " << items << endl;
    return 0;
}
```

**解析**：用set存违禁品，逐个检查。

---

### 1073 多选题常见计分法 (20分)

**题目**：按部分正确计分规则批改多选题。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> score(m);
    vector<string> correct(m);
    vector<vector<int>> wrong(m, vector<int>(5, 0));
    for (int i = 0; i < m; i++) {
        int s, opt, cnt;
        cin >> s >> opt >> cnt;
        score[i] = s;
        string ans;
        for (int j = 0; j < cnt; j++) { char c; cin >> c; ans += c; }
        correct[i] = ans;
    }
    for (int i = 0; i < n; i++) {
        double total = 0;
        for (int j = 0; j < m; j++) {
            char c; int cnt;
            cin >> c >> cnt >> c;
            string ans;
            for (int k = 0; k < cnt; k++) {
                cin >> c;
                ans += c;
                if (k < cnt - 1) cin >> c;
            }
            cin >> c;
            if (ans == correct[j]) total += score[j];
            else {
                bool partial = true;
                for (char x : ans)
                    if (correct[j].find(x) == string::npos) { partial = false; break; }
                if (partial && ans.size() < correct[j].size()) total += score[j] / 2.0;
                for (int k = 0; k < 5; k++) {
                    char opt = 'a' + k;
                    bool inAns = ans.find(opt) != string::npos;
                    bool inCorrect = correct[j].find(opt) != string::npos;
                    if (inAns != inCorrect) wrong[j][k]++;
                }
            }
        }
        printf("%.1f\n", total);
    }
    int maxWrong = 0;
    for (int j = 0; j < m; j++)
        for (int k = 0; k < 5; k++)
            maxWrong = max(maxWrong, wrong[j][k]);
    if (maxWrong == 0) cout << "Too simple" << endl;
    else {
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 5; k++)
                if (wrong[j][k] == maxWrong)
                    cout << maxWrong << " " << j + 1 << "-" << char('a' + k) << endl;
    }
    return 0;
}
```

**解析**：选对部分得一半分，统计选项错误次数。

---

### 1074 宇宙无敌加法器 (20分)

**题目**：按自定义进制规则做加法。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string base, a, b;
    cin >> base >> a >> b;
    while (a.size() < base.size()) a = "0" + a;
    while (b.size() < base.size()) b = "0" + b;
    string result;
    int carry = 0;
    for (int i = base.size() - 1; i >= 0; i--) {
        int radix = (base[i] == '0') ? 10 : base[i] - '0';
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char(sum % radix + '0') + result;
        carry = sum / radix;
    }
    if (carry) result = to_string(carry) + result;
    int i = 0;
    while (i < result.size() - 1 && result[i] == '0') i++;
    cout << result.substr(i) << endl;
    return 0;
}
```

**解析**：按位置对应的进制做加法运算。

---

### 1075 链表元素分类 (25分)

**题目**：将链表按正负零重新排列。

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int addr, data, next;
} nodes[100005];

int main() {
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    vector<Node> neg, mid, pos;
    for (int p = head; p != -1; p = nodes[p].next) {
        if (nodes[p].data < 0) neg.push_back(nodes[p]);
        else if (nodes[p].data <= k) mid.push_back(nodes[p]);
        else pos.push_back(nodes[p]);
    }
    vector<Node> result;
    for (auto& x : neg) result.push_back(x);
    for (auto& x : mid) result.push_back(x);
    for (auto& x : pos) result.push_back(x);
    for (int i = 0; i < result.size(); i++) {
        printf("%05d %d ", result[i].addr, result[i].data);
        if (i == result.size() - 1) printf("-1\n");
        else printf("%05d\n", result[i+1].addr);
    }
    return 0;
}
```

**解析**：分三类存储后按顺序重连。

---

## 1076-1100

### 1076 Wifi密码 (15分)

**题目**：从选择题答案中提取Wifi密码。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 4; i++) {
            char c;
            cin >> c >> c >> c;
            if (c == 'T') cout << i + 1;
        }
    }
    return 0;
}
```

**解析**：找每题正确选项对应的数字输出。

---

### 1077 互评成绩计算 (20分)

**题目**：计算去掉极值后的平均分。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int teacher, scores[15], sum = 0, minS = 100, maxS = 0;
        cin >> teacher;
        for (int i = 0; i < m - 1; i++) {
            cin >> scores[i];
            if (scores[i] < 0) scores[i] = 0;
            if (scores[i] > teacher) scores[i] = teacher;
            sum += scores[i];
            minS = min(minS, scores[i]);
            maxS = max(maxS, scores[i]);
        }
        int avg = (sum - minS - maxS + m - 3) / (m - 3);  // 四舍五入
        cout << (teacher + avg + 1) / 2 << endl;  // 四舍五入
    }
    return 0;
}
```

**解析**：过滤非法分数，去极值求平均。

---

### 1078 字符串压缩与解压 (20分)

**题目**：实现字符串的压缩和解压。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    char op;
    string s;
    cin >> op;
    getline(cin, s);
    getline(cin, s);
    if (op == 'C') {
        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            if (j - i > 1) cout << j - i;
            cout << s[i];
            i = j;
        }
    } else {
        for (int i = 0; i < s.size(); ) {
            if (isdigit(s[i])) {
                int cnt = 0;
                while (isdigit(s[i])) cnt = cnt * 10 + s[i++] - '0';
                for (int j = 0; j < cnt; j++) cout << s[i];
                i++;
            } else {
                cout << s[i++];
            }
        }
    }
    return 0;
}
```

**解析**：压缩统计连续字符，解压重复输出。

---

### 1079 延迟的回文数 (20分)

**题目**：判断数字是否为回文数或能通过操作变成回文数。

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b) {
    string res;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res = char(sum % 10 + '0') + res;
        carry = sum / 10;
    }
    if (carry) res = "1" + res;
    return res;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i]) return false;
    return true;
}

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        if (isPalindrome(n)) { cout << n << " is a palindromic number." << endl; return 0; }
        string rev = n;
        reverse(rev.begin(), rev.end());
        cout << n << " + " << rev << " = ";
        n = add(n, rev);
        cout << n << endl;
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}
```

**解析**：大数加法判断回文，最多10次迭代。

---

### 1080 MOOC期终成绩 (25分)

**题目**：计算学生总评成绩并排名。

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    int gp = -1, gm = -1, gf = -1, g = 0;
};

bool cmp(Student a, Student b) {
    if (a.g != b.g) return a.g > b.g;
    return a.id < b.id;
}

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    map<string, Student> students;
    for (int i = 0; i < p; i++) {
        string id; int score;
        cin >> id >> score;
        students[id].id = id;
        students[id].gp = score;
    }
    for (int i = 0; i < m; i++) {
        string id; int score;
        cin >> id >> score;
        if (students.count(id)) students[id].gm = score;
    }
    for (int i = 0; i < n; i++) {
        string id; int score;
        cin >> id >> score;
        if (students.count(id)) students[id].gf = score;
    }
    vector<Student> result;
    for (auto& p : students) {
        Student& s = p.second;
        if (s.gp < 200) continue;
        s.g = (s.gm > s.gf) ? (int)(s.gm * 0.4 + s.gf * 0.6 + 0.5) : s.gf;
        if (s.g >= 60) result.push_back(s);
    }
    sort(result.begin(), result.end(), cmp);
    for (auto& s : result)
        cout << s.id << " " << s.gp << " " << s.gm << " " << s.gf << " " << s.g << endl;
    return 0;
}
```

**解析**：合并多次成绩，按规则计算总评。

---

### 1081 检查密码 (15分)

**题目**：验证密码是否符合规则。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        if (s.size() < 6) { cout << "Your password is tai duan le." << endl; continue; }
        bool hasAlpha = false, hasDigit = false, valid = true;
        for (char c : s) {
            if (isalpha(c)) hasAlpha = true;
            else if (isdigit(c)) hasDigit = true;
            else if (c != '.') valid = false;
        }
        if (!valid) cout << "Your password is tai luan le." << endl;
        else if (!hasAlpha) cout << "Your password needs shu zi." << endl;
        else if (!hasDigit) cout << "Your password needs zi mu." << endl;
        else cout << "Your password is wan mei." << endl;
    }
    return 0;
}
```

**解析**：检查长度、字符类型、是否有字母和数字。

---

### 1082 射击比赛 (20分)

**题目**：找出射击成绩最好和最差的选手。

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string bestId, worstId;
    double bestDist = 1e9, worstDist = 0;
    while (n--) {
        string id;
        int x, y;
        cin >> id >> x >> y;
        double dist = sqrt(x * x + y * y);
        if (dist < bestDist) { bestDist = dist; bestId = id; }
        if (dist > worstDist) { worstDist = dist; worstId = id; }
    }
    cout << bestId << " " << worstId << endl;
    return 0;
}
```

**解析**：计算到靶心距离，找最小和最大。

---

### 1083 是否存在相等的差 (20分)

**题目**：统计数列中差值的出现次数。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, cnt[10001] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[abs(a - i)]++;
    }
    for (int i = 10000; i >= 0; i--) {
        if (cnt[i] > 1) cout << i << " " << cnt[i] << endl;
    }
    return 0;
}
```

**解析**：统计|a[i]-i|的出现次数，降序输出。

---

### 1084 外观数列 (20分)

**题目**：生成外观数列的第N项。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;
    string s = to_string(d);
    for (int i = 1; i < n; i++) {
        string next;
        for (int j = 0; j < s.size(); ) {
            int k = j;
            while (k < s.size() && s[k] == s[j]) k++;
            next += s[j] + to_string(k - j);
            j = k;
        }
        s = next;
    }
    cout << s << endl;
    return 0;
}
```

**解析**：统计连续字符生成下一项。

---

### 1085 PAT单位排行 (25分)

**题目**：按加权总分对学校排名。

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct School {
    string name;
    double score = 0;
    int cnt = 0;
};

bool cmp(School a, School b) {
    if ((int)a.score != (int)b.score) return (int)a.score > (int)b.score;
    if (a.cnt != b.cnt) return a.cnt < b.cnt;
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;
    map<string, School> schools;
    while (n--) {
        string id, school;
        int score;
        cin >> id >> score >> school;
        for (char& c : school) c = tolower(c);
        schools[school].name = school;
        schools[school].cnt++;
        if (id[0] == 'B') schools[school].score += score / 1.5;
        else if (id[0] == 'A') schools[school].score += score;
        else schools[school].score += score * 1.5;
    }
    vector<School> v;
    for (auto& p : schools) v.push_back(p.second);
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    int rank = 1;
    for (int i = 0; i < v.size(); i++) {
        if (i > 0 && (int)v[i].score != (int)v[i-1].score) rank = i + 1;
        cout << rank << " " << v[i].name << " " << (int)v[i].score << " " << v[i].cnt << endl;
    }
    return 0;
}
```

**解析**：按等级加权求和，多级排序输出。

---

### 1086 就不告诉你 (15分)

**题目**：输出两数乘积的倒序。

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a * b);
    reverse(s.begin(), s.end());
    cout << stoi(s) << endl;
    return 0;
}
```

**解析**：计算乘积后反转字符串，去前导零。

---

### 1087 有多少不同的值 (20分)

**题目**：统计表达式产生的不同值数量。

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i / 2 + i / 3 + i / 5);
    cout << s.size() << endl;
    return 0;
}
```

**解析**：用set存储所有不同的计算结果。

---

### 1088 三人行 (20分)

**题目**：找满足条件的甲乙分数。

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, x, y;
    cin >> m >> x >> y;
    for (int jia = 99; jia >= 10; jia--) {
        int yi = jia % 10 * 10 + jia / 10;
        double bing = fabs(jia - yi);
        if (bing * x == m * y) {
            cout << jia << " " << (jia > m ? "Cong" : (jia == m ? "Ping" : "Gai")) << endl;
            cout << yi << " " << (yi > m ? "Cong" : (yi == m ? "Ping" : "Gai")) << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
```

**解析**：枚举甲的分数，计算乙并验证丙。

---

### 1089 狼人杀-简单版 (20分)

**题目**：找出两个说谎的狼人。

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a[101];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int wolf[101] = {0}, liar = 0, wolfLiar = 0;
            wolf[i] = wolf[j] = 1;
            for (int k = 1; k <= n; k++) {
                bool statement = (a[k] > 0) ? !wolf[abs(a[k])] : wolf[-a[k]];
                if (!statement) {
                    liar++;
                    if (wolf[k]) wolfLiar++;
                }
            }
            if (liar == 2 && wolfLiar == 1) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
```

**解析**：枚举狼人组合，验证谎言条件。

---

### 1090 危险品装箱 (25分)

**题目**：检查货物是否可安全装箱。

```cpp
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> danger;
    while (n--) {
        int a, b;
        cin >> a >> b;
        danger[a].push_back(b);
        danger[b].push_back(a);
    }
    while (m--) {
        int k;
        cin >> k;
        vector<int> items(k);
        set<int> inBox;
        for (int i = 0; i < k; i++) {
            cin >> items[i];
            inBox.insert(items[i]);
        }
        bool safe = true;
        for (int item : items) {
            for (int d : danger[item]) {
                if (inBox.count(d)) { safe = false; break; }
            }
            if (!safe) break;
        }
        cout << (safe ? "Yes" : "No") << endl;
    }
    return 0;
}
```

**解析**：用map存危险品对，检查是否同时在箱中。

---

### 1091 N-自守数 (15分)

**题目**：判断N乘以某数平方是否以该数结尾。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        long long sq = (long long)n * k * k;
        string s = to_string(sq), t = to_string(k);
        if (s.size() >= t.size() && s.substr(s.size() - t.size()) == t)
            cout << sq << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```

**解析**：计算乘积检查末尾是否匹配。

---

### 1092 最好吃的月饼 (20分)

**题目**：找出销量最高的月饼。

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sales(n + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int s;
            cin >> s;
            sales[j] += s;
        }
    }
    int maxSale = 0;
    for (int i = 1; i <= n; i++) maxSale = max(maxSale, sales[i]);
    cout << maxSale << endl;
    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (sales[i] == maxSale) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    return 0;
}
```

**解析**：累计各月饼销量，找最大值。

---

### 1093 字符串A+B (20分)

**题目**：合并两字符串并去重。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool used[128] = {false};
    for (char c : a + b) {
        if (!used[(int)c]) {
            cout << c;
            used[(int)c] = true;
        }
    }
    return 0;
}
```

**解析**：按顺序输出首次出现的字符。

---

### 1094 谷歌的招聘 (20分)

**题目**：在数字串中找第一个指定长度的素数。

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int l, k;
    string n;
    cin >> l >> k >> n;
    for (int i = 0; i <= l - k; i++) {
        string sub = n.substr(i, k);
        if (isPrime(stoll(sub))) {
            cout << sub << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
```

**解析**：枚举所有k位子串判断素数。

---

### 1095 解码PAT准考证 (25分)

**题目**：根据准考证号统计考试信息。

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    int score;
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Student> students(n);
    for (int i = 0; i < n; i++) cin >> students[i].id >> students[i].score;
    for (int q = 1; q <= m; q++) {
        int type;
        string c;
        cin >> type >> c;
        cout << "Case " << q << ": " << type << " " << c << endl;
        if (type == 1) {
            vector<Student> res;
            for (auto& s : students)
                if (s.id[0] == c[0]) res.push_back(s);
            sort(res.begin(), res.end(), cmp);
            if (res.empty()) cout << "NA" << endl;
            else for (auto& s : res) cout << s.id << " " << s.score << endl;
        } else if (type == 2) {
            int cnt = 0, sum = 0;
            for (auto& s : students)
                if (s.id.substr(1, 3) == c) { cnt++; sum += s.score; }
            if (cnt == 0) cout << "NA" << endl;
            else cout << cnt << " " << sum << endl;
        } else {
            map<string, int> rooms;
            for (auto& s : students)
                if (s.id.substr(1, 3) == c) rooms[s.id.substr(4, 6)]++;
            vector<pair<int, string>> res;
            for (auto& p : rooms) res.push_back({p.second, p.first});
            sort(res.begin(), res.end(), [](auto& a, auto& b) {
                return a.first != b.first ? a.first > b.first : a.second < b.second;
            });
            if (res.empty()) cout << "NA" << endl;
            else for (auto& p : res) cout << p.second << " " << p.first << endl;
        }
    }
    return 0;
}
```

**解析**：按准考证号结构解析，分类统计查询。

---

### 1096 大美数 (15分)

**题目**：找出各位数字均为偶数的大美数。

```cpp
#include <iostream>
using namespace std;

bool isDamei(int n) {
    while (n > 0) {
        if ((n % 10) % 2 != 0) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (isDamei(a)) {
            if (found) cout << " ";
            cout << a;
            found = true;
        }
    }
    if (!found) cout << "No";
    return 0;
}
```

**解析**：检查每位数字是否都是偶数。

---

### 1097 矩阵行平移 (20分)

**题目**：对矩阵奇数行左移、偶数行右移后求每列最大值。

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> m(n + 1, vector<int>(2 * n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int offset = (i % 2 == 1) ? (n - k) : (n + k);
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            m[i][(j + offset - 1) % (2 * n) + 1] = x;
        }
    }
    bool first = true;
    for (int j = 1; j <= 2 * n; j++) {
        int maxVal = 0;
        for (int i = 1; i <= n; i++) maxVal = max(maxVal, m[i][j]);
        if (maxVal > 0) {
            if (!first) cout << " ";
            cout << maxVal;
            first = false;
        }
    }
    return 0;
}
```

**解析**：扩展矩阵宽度，平移后求列最大值。

---

### 1098 岩洞施工 (20分)

**题目**：计算岩洞可通过的最大高度。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int minGap = 1e9;
    for (int i = 0; i < n; i++) {
        int top, bottom;
        cin >> top >> bottom;
        minGap = min(minGap, bottom - top);
    }
    if (minGap <= 0) cout << "No" << endl;
    else cout << minGap << endl;
    return 0;
}
```

**解析**：计算每处顶底差的最小值。

---

### 1099 性格评测 (20分)

**题目**：根据问卷计算性格类型。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int e = 0, i = 0, s_ = 0, n_ = 0, t = 0, f = 0, j = 0, p = 0;
        for (int k = 0; k < s.size(); k++) {
            int q = k + 1;
            char c = s[k];
            if (q % 7 == 1) { if (c == 'a') e++; else i++; }
            else if (q % 7 == 2 || q % 7 == 3) { if (c == 'a') s_++; else n_++; }
            else if (q % 7 == 4 || q % 7 == 5) { if (c == 'a') t++; else f++; }
            else { if (c == 'a') j++; else p++; }
        }
        cout << (e >= i ? 'E' : 'I') << (s_ >= n_ ? 'S' : 'N')
             << (t >= f ? 'T' : 'F') << (j >= p ? 'J' : 'P') << endl;
    }
    return 0;
}
```

**解析**：按题号统计各维度倾向。

---

### 1100 校庆 (25分)

**题目**：找校友中最年长者，无校友则在所有人中找。

```cpp
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> alumni;
    while (n--) {
        string id;
        cin >> id;
        alumni.insert(id);
    }
    int m, cnt = 0;
    cin >> m;
    string oldestAlum, oldestGuest;
    while (m--) {
        string id;
        cin >> id;
        if (alumni.count(id)) {
            cnt++;
            if (oldestAlum.empty() || id.substr(6, 8) < oldestAlum.substr(6, 8))
                oldestAlum = id;
        }
        if (oldestGuest.empty() || id.substr(6, 8) < oldestGuest.substr(6, 8))
            oldestGuest = id;
    }
    cout << cnt << endl;
    cout << (cnt > 0 ? oldestAlum : oldestGuest) << endl;
    return 0;
}
```

**解析**：用set存校友，比较身份证出生日期。

---

## 1101-1125

### 1101 B是A的多少倍 (15分)

**题目**：计算B是A的多少倍。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    int da, db;
    cin >> a >> da >> b >> db;
    double valA = a * pow(10, da);
    double valB = b * pow(10, db);
    cout << fixed << setprecision(2) << valB / valA << endl;
    return 0;
}
```

**解析**：转换科学计数法后相除。

---

### 1102 教超冠军卷 (20分)

**题目**：找出吃最多蛋白质的选手。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string winner;
    double maxProtein = 0;
    for (int i = 0; i < n; i++) {
        string name;
        double protein, amount;
        cin >> name >> protein >> amount;
        double total = protein * amount / 100;
        if (total > maxProtein) {
            maxProtein = total;
            winner = name;
        }
    }
    cout << winner << " " << (int)(maxProtein + 0.5) << endl;
    return 0;
}
```

**解析**：计算蛋白质总摄入量，找最大值。

---

### 1103 缘分数 (20分)

**题目**：找配对的缘分数。

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) { sum += n % 10; n /= 10; }
    return sum;
}

int reverseNum(int n) {
    int rev = 0;
    while (n > 0) { rev = rev * 10 + n % 10; n /= 10; }
    return rev;
}

int main() {
    int n;
    cin >> n;
    bool found = false;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (sumDigits(a) == sumDigits(b)) {
            int sq = (int)sqrt(a * b);
            if (sq * sq == a * b && reverseNum(sq) == sq) {
                cout << a << " " << b << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "No Solution" << endl;
    return 0;
}
```

**解析**：检查数字和相等且乘积开方为回文数。

---

### 1104 天长地久 (20分)

**题目**：找满足条件的数对。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) { sum += n % 10; n /= 10; }
    return sum;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m, s;
        cin >> m >> s;
        vector<pair<int, int>> results;
        for (int a = 1; a < pow(10, m); a++) {
            int b = a + s;
            if (b >= pow(10, m)) break;
            if (digitSum(a) == digitSum(b)) {
                int g = __gcd(a, b);
                results.push_back({a / g, b / g});
            }
        }
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        if (results.empty()) cout << "No Solution" << endl;
        else {
            for (auto& p : results)
                cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
```

**解析**：枚举a，检查a和a+s数字和相等。

---

### 1105 链表合并 (25分)

**题目**：合并两个链表，交替取节点。

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int addr, data, next;
} nodes[100005];

int main() {
    int h1, h2, n;
    cin >> h1 >> h2 >> n;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> list1, list2;
    for (int p = h1; p != -1; p = nodes[p].next) list1.push_back(p);
    for (int p = h2; p != -1; p = nodes[p].next) list2.push_back(p);
    if (list1.size() < list2.size()) swap(list1, list2);
    reverse(list1.begin(), list1.end());
    vector<int> result;
    int i = 0, j = 0;
    while (i < list1.size() || j < list2.size()) {
        if (i < list1.size()) { result.push_back(list1[i]); i++; }
        if (i < list1.size()) { result.push_back(list1[i]); i++; }
        if (j < list2.size()) { result.push_back(list2[j]); j++; }
    }
    for (int k = 0; k < result.size(); k++) {
        printf("%05d %d ", result[k], nodes[result[k]].data);
        if (k == result.size() - 1) printf("-1\n");
        else printf("%05d\n", result[k + 1]);
    }
    return 0;
}
```

**解析**：分别遍历两链表，按规则交替合并。

---

### 1106 2019数列 (15分)

**题目**：生成2019数列的前N项。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string seq = "2019";
    for (int i = 4; i < n; i++) {
        char next = ((seq[i-1] - '0') + (seq[i-2] - '0') + (seq[i-3] - '0') + (seq[i-4] - '0')) % 10 + '0';
        seq += next;
    }
    cout << seq.substr(0, n) << endl;
    return 0;
}
```

**解析**：按规则生成后续数字。

---

### 1107 老鼠爱大米 (20分)

**题目**：统计投票找出最受欢迎选手。

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> votes(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            if (v >= 1 && v <= n) votes[v]++;
        }
    }
    int maxVote = 0, winner = 0;
    for (int i = 1; i <= n; i++) {
        if (votes[i] > maxVote) {
            maxVote = votes[i];
            winner = i;
        }
    }
    cout << winner << " " << maxVote << endl;
    return 0;
}
```

**解析**：统计各选手票数，找最高票。

---

### 1108 String复读机 (20分)

**题目**：模拟字符串重复操作。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    string result = s;
    for (int i = 1; i < n; i++) result += s;
    cout << result << endl;
    return 0;
}
```

**解析**：将字符串重复n次输出。

---

### 1109 擅长C (20分)

**题目**：用字符矩阵拼出单词。

```cpp
#include <iostream>
#include <string>
using namespace std;

string letters[26][7];

int main() {
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++)
            getline(cin, letters[i][j]);
    string word;
    bool first = true;
    while (cin >> word) {
        if (!first) cout << endl;
        first = false;
        for (int row = 0; row < 7; row++) {
            for (int i = 0; i < word.size(); i++) {
                if (i > 0) cout << " ";
                cout << letters[word[i] - 'A'][row];
            }
            cout << endl;
        }
    }
    return 0;
}
```

**解析**：读取字母模板，按单词拼接输出。

---

### 1110 区块反转 (25分)

**题目**：将链表按块反转。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int addr, data, next;
} nodes[100005];

int main() {
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr;
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    vector<int> list;
    for (int p = head; p != -1; p = nodes[p].next) list.push_back(p);
    int total = list.size();
    int blocks = total / k;
    vector<int> result;
    for (int i = blocks - 1; i >= 0; i--) {
        for (int j = i * k; j < (i + 1) * k; j++)
            result.push_back(list[j]);
    }
    for (int i = blocks * k; i < total; i++)
        result.push_back(list[i]);
    for (int i = 0; i < result.size(); i++) {
        printf("%05d %d ", result[i], nodes[result[i]].data);
        if (i == result.size() - 1) printf("-1\n");
        else printf("%05d\n", result[i + 1]);
    }
    return 0;
}
```

**解析**：分块后整体反转块顺序。

---

### 1111 对称日 (15分)

**题目**：判断日期是否为对称日。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string date;
        cin >> date;
        string rev = date;
        reverse(rev.begin(), rev.end());
        cout << (date == rev ? "Yes" : "No") << endl;
    }
    return 0;
}
```

**解析**：判断日期字符串是否为回文。

---

### 1112 超标区间 (20分)

**题目**：找出数列中连续超标的区间。

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> intervals;
    int start = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > t) {
            if (start == -1) start = i;
        } else {
            if (start != -1) {
                intervals.push_back({start, i - 1});
                start = -1;
            }
        }
    }
    if (start != -1) intervals.push_back({start, n - 1});
    if (intervals.empty()) cout << "Nothing to worry about." << endl;
    else {
        for (auto& p : intervals)
            cout << "[" << p.first << ", " << p.second << "]" << endl;
    }
    return 0;
}
```

**解析**：扫描记录连续超过阈值的区间。

---

### 1113 钱串子的加法 (15分)

**题目**：不进位加法运算。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
    string result;
    for (int i = 0; i < a.size(); i++)
        result += ((a[i] - '0') + (b[i] - '0')) % 10 + '0';
    int i = 0;
    while (i < result.size() - 1 && result[i] == '0') i++;
    cout << result.substr(i) << endl;
    return 0;
}
```

**解析**：逐位相加取个位，不进位。

---

### 1114 全素日 (20分)

**题目**：判断日期各部分是否都是素数。

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    string date;
    cin >> date;
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(4, 2));
    int day = stoi(date.substr(6, 2));
    int ym = stoi(date.substr(0, 6));
    int md = stoi(date.substr(4, 4));
    int full = stoi(date);
    cout << (isPrime(year) ? "Yes" : "No") << endl;
    cout << (isPrime(month) ? "Yes" : "No") << endl;
    cout << (isPrime(day) ? "Yes" : "No") << endl;
    cout << (isPrime(ym) ? "Yes" : "No") << endl;
    cout << (isPrime(md) ? "Yes" : "No") << endl;
    cout << (isPrime(full) ? "Yes" : "No") << endl;
    return 0;
}
```

**解析**：分别检查年、月、日及其组合是否为素数。

---

### 1115 裁判机 (25分)

**题目**：模拟井字棋裁判。

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        char board[3][3] = {0};
        string moves;
        cin >> moves;
        char turn = 'X';
        bool xWin = false, oWin = false, invalid = false;
        for (char c : moves) {
            int pos = c - '1';
            int r = pos / 3, col = pos % 3;
            if (board[r][col] != 0) { invalid = true; break; }
            board[r][col] = turn;
            // Check win
            auto check = [&](char p) {
                for (int i = 0; i < 3; i++) {
                    if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
                    if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
                }
                if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
                if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
                return false;
            };
            if (check(turn)) {
                if (turn == 'X') xWin = true;
                else oWin = true;
            }
            turn = (turn == 'X') ? 'O' : 'X';
        }
        if (invalid) cout << "Invalid" << endl;
        else if (xWin && oWin) cout << "Invalid" << endl;
        else if (xWin) cout << "X" << endl;
        else if (oWin) cout << "O" << endl;
        else cout << "Tie" << endl;
    }
    return 0;
}
```

**解析**：模拟下棋过程，检测胜负或平局。

---

### 1116 多二了 (15分)

**题目**：判断数字是否被2整除的次数最多。

```cpp
#include <iostream>
using namespace std;

int countTwo(int n) {
    int cnt = 0;
    while (n % 2 == 0) { n /= 2; cnt++; }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int maxCnt = 0, result = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = countTwo(x);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            result = x;
        }
    }
    cout << result << " " << maxCnt << endl;
    return 0;
}
```

**解析**：统计每个数能被2整除的次数。

---

### 1117 数字之王 (20分)

**题目**：找出乘积各位数字出现最多的数。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        long long product = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            product *= x;
        }
        string s = to_string(product);
        int cnt[10] = {0};
        for (char c : s) cnt[c - '0']++;
        int maxCnt = 0;
        for (int i = 0; i < 10; i++) maxCnt = max(maxCnt, cnt[i]);
        bool first = true;
        for (int i = 9; i >= 0; i--) {
            if (cnt[i] == maxCnt) {
                if (!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << ":" << maxCnt << endl;
    }
    return 0;
}
```

**解析**：计算乘积后统计各数字出现频率。

---

### 1118 这是什么鬼 (20分)

**题目**：解析特殊格式的数字。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        long long result = 0;
        bool negative = (s[0] == '-');
        for (int i = (negative ? 1 : 0); i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                result = result * 10 + s[i] - '0';
        }
        if (negative) result = -result;
        cout << result << endl;
    }
    return 0;
}
```

**解析**：过滤非数字字符，提取数值。

---

### 1119 前序与中序 (25分)

**题目**：根据前序和中序重建二叉树并输出后序。

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> pre, in, post;
unordered_map<int, int> inPos;

void build(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;
    int root = pre[preL];
    int k = inPos[root];
    int leftSize = k - inL;
    build(preL + 1, preL + leftSize, inL, k - 1);
    build(preL + leftSize + 1, preR, k + 1, inR);
    post.push_back(root);
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) { cin >> in[i]; inPos[in[i]] = i; }
    build(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << post[i];
    }
    return 0;
}
```

**解析**：递归重建二叉树，后序遍历输出。

---

### 1120 买地攻略 (25分)

**题目**：在预算内选择最多连续地块。

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < n; right++) {
        sum += price[right];
        while (sum > m) sum -= price[left++];
        maxLen = max(maxLen, right - left + 1);
    }
    cout << maxLen << endl;
    return 0;
}
```

**解析**：滑动窗口维护预算内最长区间。

---

### 1121 集装箱配置 (20分)

**题目**：优化集装箱配置策略。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int left = 0, right = n - 1, cnt = 0;
    while (left <= right) {
        if (left == right) { cnt++; break; }
        if (w[left] + w[right] <= c) left++;
        right--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
```

**解析**：贪心配对，最轻最重尝试同装。

---

### 1122 用字母拼图 (20分)

**题目**：检查能否用字母卡片拼出单词。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string cards;
    int n;
    cin >> cards >> n;
    while (n--) {
        string word;
        cin >> word;
        int cnt[26] = {0};
        for (char c : cards) if (isalpha(c)) cnt[tolower(c) - 'a']++;
        bool ok = true;
        for (char c : word) {
            int idx = tolower(c) - 'a';
            if (cnt[idx] > 0) cnt[idx]--;
            else { ok = false; break; }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
```

**解析**：统计卡片字母数，检查是否充足。

---

### 1123 舍入 (20分)

**题目**：实现四舍六入五成双规则。

```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;
    int dotPos = s.find('.');
    if (dotPos == string::npos) { cout << s << endl; return 0; }
    int intPart = stoi(s.substr(0, dotPos));
    int decimal = s[dotPos + 1] - '0';
    if (decimal < 5) cout << intPart << endl;
    else if (decimal > 5) cout << intPart + (intPart >= 0 ? 1 : -1) << endl;
    else {
        bool hasMore = s.size() > dotPos + 2;
        for (int i = dotPos + 2; i < s.size() && !hasMore; i++)
            if (s[i] != '0') hasMore = true;
        if (hasMore) cout << intPart + (intPart >= 0 ? 1 : -1) << endl;
        else cout << (intPart % 2 == 0 ? intPart : intPart + 1) << endl;
    }
    return 0;
}
```

**解析**：实现银行家舍入法。

---

### 1124 节绳子 (25分)

**题目**：切绳子使各段满足要求。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<double> ropes(n);
    double maxLen = 0;
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        maxLen = max(maxLen, ropes[i]);
    }
    double left = 0, right = maxLen;
    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        int cnt = 0;
        for (double r : ropes) cnt += (int)(r / mid);
        if (cnt >= m) left = mid;
        else right = mid;
    }
    printf("%.2f\n", left);
    return 0;
}
```

**解析**：二分查找最大可切长度。

---

### 1125 子串与子列 (25分)

**题目**：找最长公共子串和子序列。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    // LCS (subsequence)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Longest common substring
    int maxLen = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int len = 0;
            while (i + len <= m && j + len <= n && s[i+len-1] == t[j+len-1]) len++;
            maxLen = max(maxLen, len);
        }
    }
    cout << maxLen << " " << dp[m][n] << endl;
    return 0;
}
```

**解析**：动态规划求最长公共子串和子序列。

---

# 完结

> 本文档包含PAT乙级全部125道题目（1001-1125）的C++题解与解析。
> 
> 每道题包含：题目简述、完整C++代码、解题思路分析。
> 
> 祝刷题顺利！🎉

