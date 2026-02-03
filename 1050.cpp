#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row,col;//m >= n
    int min = n;
    for(int i = 1;i <= sqrt(n);i++){
        int temp_row,temp_col;
        if ( n % i == 0) {
            temp_row = n / i;
            temp_col = i;
        }
        int temp = temp_row - temp_col;
        if(temp >= 0 && temp < min){
            row = temp_row;
            col = temp_col;
            min = temp;
        }
    }
    //还有一种更好的思路，就是直接i = sqrt(N)向下走第一个能整除的肯定就是最小的
    vector<vector<int>> res(row,vector<int>(col,0));
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<int>());
    //将一维数组映射到二维数组
    // 4. 螺旋填充逻辑 (模拟)
    // 方向数组：右(0,1), 下(1,0), 左(0,-1), 上(-1,0)
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int x = 0, y = 0; // 当前坐标
    int d = 0;        // 当前方向索引 (0:右, 1:下, 2:左, 3:上)

    for (int i = 0; i < n; i++) {
        res[x][y] = arr[i]; // 填入数字

        // 预判下一步的位置
        int next_x = x + dx[d];
        int next_y = y + dy[d];
  
        // 判断是否需要转向：
        // 1. 越界 (next_x, next_y 超出范围)
        // 2. 已被填充 (res[next_x][next_y] 不为 0)
        if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= col || res[next_x][next_y] != 0) {
            d = (d + 1) % 4; // 顺时针转向
            next_x = x + dx[d];
            next_y = y + dy[d];
        }
        
        // 更新坐标
        x = next_x;
        y = next_y;
    }

    // 5. 输出结果
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << res[i][j];
            if (j != col - 1) cout << " "; // 行末不输出空格
        }
        cout << endl;
    }
    return 0;
}