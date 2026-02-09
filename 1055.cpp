#include <bits/stdc++.h>
using namespace std;

struct stu {
    string name;
    int tall;
};

bool cmp(const stu& a, const stu& b) {
    if (a.tall != b.tall) return a.tall > b.tall;
    return a.name < b.name;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<stu> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].tall;
    }
    sort(arr.begin(), arr.end(), cmp);

    int m = n / k;
    int idx = 0;

    for (int row = 0; row < k; row++) {
        // 第一排（最后排）人数 = m + n%k，其他排 = m
        int num = (row == 0) ? (m + n % k) : m;
        vector<string> line(num);
        int mid = num / 2;
        int left = mid - 1, right = mid + 1;

        // 最高站中间
        line[mid] = arr[idx++].name;

        // 先左后右交替
        while (left >= 0 || right < num) {
            if (left >= 0) line[left--] = arr[idx++].name;
            if (right < num) line[right++] = arr[idx++].name;
        }

        // 输出当前排
        for (int i = 0; i < num; i++) {
            if (i > 0) cout << " ";
            cout << line[i];
        }
        cout << endl;
    }
    return 0;
}
