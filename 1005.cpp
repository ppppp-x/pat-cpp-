#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);//初始化
    vector<bool> b(n, true);
    vector<bool> res(10000,false);
    vector<int> ans(n,0);
    
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }//输入待判断的数字
    

    for(int i = 0;i < n;i++){
        while(a[i] != 1){
            if (res[a[i]] == false){
                res[a[i]] = true;
            }else {
                 
                break;
            }
            if(a[i] % 2 == 0) a[i] = a[i] / 2;
            else a[i] = (3 * a[i] + 1) / 2;
        }
    }
    
    for(bool x : b) cout<<x<<" "; 

//    for(int i = 0;i < n;i++){
//        if(b[i]){
//           ans[i] = a[i]; 
//        }
//    }
//    sort(ans.begin(), ans.end(), greater<int>());
//    for(int x : ans) cout<<x<<" ";
    
    return 0;
}
