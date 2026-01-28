#include <bits/stdc++.h>
using namespace std;

int main(){
    int hour,minute,second;
    size_t c1, c2;
    cin>>c1>>c2;
    int time= c2 - c1;
    time = round(time / 100.0);//除以浮点数保留小数round才有意义
    hour = time / 3600;
    minute = (time % 3600) / 60;
    second = time % 60;
    printf("%02d:%02d:%02d",hour,minute,second);//不足两位高位补0
    return 0;
}
