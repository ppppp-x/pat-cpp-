#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> res;
    for(int i = 0;i < n;i++){
        string str;
        cin>>str;
        int sum = 0;
        for(int j = 0;j < str.size();j++){
            sum += str[j] - '0';
        }
        res.insert(sum);
    }
    cout<<res.size()<<endl;
    bool flag = true;
    for(int x : res){
        if(flag) cout<<x;
        else cout<<" "<<x;
        flag = false;
    } 
    return 0;
}