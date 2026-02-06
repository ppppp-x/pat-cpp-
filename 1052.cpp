#include <bits/stdc++.h>
using namespace std;

void parse(string &line,vector<string> &str){
    bool inside = false;
    string temp = "";
    for(char c : line){
        if(c == '['){
            inside = true;
            temp = "";
        }else if( c == ']'){
            str.push_back(temp);
            inside = false;
        }else if(inside){
            temp = temp + c;
        }
    }
}
//左手 左眼 口 右眼 右手
int main(){
    vector<vector<string>> s(3);
    for (int i = 0; i < 3; i++)
    {
        string line;
        getline(cin,line);
        parse(line,s[i]);
    }
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int arr[5];
        for (int i = 0; i < 5; i++)
        {
            cin>>arr[i];
            arr[i] -= 1;
        }
        bool flag = true;
        if( arr[0] < 0 || arr[0] >= s[0].size()) flag = false;
        if( arr[1] < 0 || arr[1] >= s[1].size()) flag = false;
        if( arr[2] < 0 || arr[2] >= s[2].size()) flag = false;
        if( arr[3] < 0 || arr[3] >= s[1].size()) flag = false;
        if( arr[4] < 0 || arr[4] >= s[0].size()) flag = false;
        if(flag){
            for (int i = 0; i < 5; i++)
            {
                if(i==0) cout<<s[0][arr[i]]<<"(";
                if(i==1) cout<<s[1][arr[i]];
                if(i==2) cout<<s[2][arr[i]];
                if(i==3) cout<<s[1][arr[i]]<<")";
                if(i==4) cout<<s[0][arr[i]]<<endl;
            }
            
        }else cout<<"Are you kidding me? @\\/@"<<endl;
    }
    return 0;
}