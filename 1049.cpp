#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<long long> count(n,0);
    //双重for循环是肯定超时的，好的思路是统计每个数字出现的次数
    for (int i = 0; i < n; i++)
    {
        int front = i;
        int back = n - (i + 1);
        long long cnt =(long long)(front + 1) * (back + 1);
        count[i] = cnt;
    }
    
    double res = 0;
    for(int i = 0;i < n;i++){
        res = res + arr[i] * count[i];
    }
    printf("%.2f",res);
    return 0;
}