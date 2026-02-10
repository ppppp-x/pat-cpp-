#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int len = str.length();
    int num = 0;
    int count_1 = 0,count_0 = 0;
    for (int i = 0; i < len; i++)
    {
        if(isalpha(str[i])){
            num += tolower(str[i]) - 'a' + 1;
        }
    }
    if(num == 0) {cout<<"0 0"<<endl;return 0;}
    while(num != 0){
        if(num & 1) count_1++;
        else count_0++;
        num = num >> 1;
    }
    cout<<count_0<<" "<<count_1<<endl;
    return 0;
}