#include <bits/stdc++.h>
using namespace std;

//初始化mp完成字符到数字的映射，开辟的string数组已经完成了数字到字符的映射
string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mp;

void earthtomars(int n){
    if(n >= 0 && n <= 12) cout<<low[n]<<endl;
    else {
        int a = n / 13;
        int b = n % 13;
        if (b == 0) cout<<high[a]<<endl;
        else cout<<high[a]<<" "<<low[b]<<endl;
    } 
}

void marstoearth(string s){
    int res = 0;
    stringstream ss(s);
    string temp;
    while(ss>>temp){
        res = res + mp[temp];
    }
    cout<<res<<endl;
}

int main(){
    for (int i = 0; i < 13; i++)
    {
        mp[low[i]] = i;
        if( i > 0){
            mp[high[i]] = i * 13;
        }
    }
    int n;
    cin>>n;
    getchar();
    while(n--){
        string line;
        getline(cin,line);
        if (isdigit(line[0])){
            earthtomars(stoi(line));
        } else{
            marstoearth(line);
        }
    }
    return 0;
}