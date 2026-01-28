#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int main(){
    string original,target;
    cin>>original>>target;
    
    int len = original.length();
    int len_target = target.length();
    vector<int> o(MAX,0);
    vector<int> t(MAX,0);
    for (int i = 0; i < len; i++)
    {
        o[original[i] - '0']++;
    }
    
    for(int i = 0;i < len_target;i++)
    {
        t[target[i] - '0']++;
    }
    bool flag = true;
    int res = 0;
    int res2 = 0;
    for(int i = 0;i < MAX;i++){
        if(o[i] - t[i] >= 0) res = res + o[i] - t[i];
        else {
            flag = false;
            res2 = res2 + abs(o[i] - t[i]);
        }
    }  
    if(flag) cout<<"Yes "<<res<<endl;
    else cout<<"No "<<res2<<endl;

    return 0;
}