#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 0;
    string s;
    cin>>s;
    vector<string> line = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    for(int i = 0;i<s.size();i++){
        num = num + (s[i] - '0');
    }//计算各位数字之和
    string str = to_string(num);
    for(int i = 0;i<str.size();i++){
        if(i == str.size() - 1) cout<<line[str[i]-'0'];
        else cout<<line[str[i]-'0']<<" ";
    }
    return 0;
}
