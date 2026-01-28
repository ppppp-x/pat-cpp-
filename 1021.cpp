#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    vector<int> n(10,0);

    for(int i = 0;i<str.length();i++){
        n[str[i] - '0']++;
    }//统计各个数字出现的次数

    for(int i = 0;i < 10;i++){
        if(n[i]) cout<<i<<":"<<n[i]<<endl;
    }

    return 0;
}
