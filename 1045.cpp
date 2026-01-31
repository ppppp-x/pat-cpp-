#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> res;
    for(int i = 0;i < n;i++){
        bool left = true;
        bool right = true;
        int temp = arr[i];
        for(int j = 0;j < i;j++){
            if(arr[j] > temp) {left = false;break;}
        }
        for(int k = i + 1;k < n;k++){
            if(arr[k] < temp) {right = false;break;}
        }
        if( left && right) res.push_back(temp);
    }
    sort(res.begin(),res.end());
    int len = res.size();
    cout<<len<<endl;
    for (int i = 0; i < len; i++)
    {
        if(i == 0) cout<<res[i];
        else cout<<" "<<res[i];
    }
    
    return 0;
}