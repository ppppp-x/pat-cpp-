#include <bits/stdc++.h>
using namespace std;


//主元的必要条件
//它在排序后的位置和原位置一样。
//它比之前出现过的所有元素的最大值还要大。
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> temp(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        temp[i] = arr[i];
    }
    sort(temp.begin(),temp.end());
    vector<int> res;
    int max_val = -1;
    for(int i = 0;i < n;i++){
        if(arr[i] == temp[i] && arr[i] > max_val){
            res.push_back(arr[i]);
        }
        max_val = max(max_val,arr[i]);
    }
    sort(res.begin(),res.end());
    int len = res.size();
    cout<<len<<endl;
    for (int i = 0; i < res.size(); i++)
    {
        if( i == 0) cout<<res[i];
        else cout<<" "<<res[i];
    }
    cout<<endl;
    return 0;
}
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n,0);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     vector<int> res;
//     for(int i = 0;i < n;i++){
//         bool left = true;
//         bool right = true;
//         int temp = arr[i];
//         for(int j = 0;j < i;j++){
//             if(arr[j] > temp) {left = false;break;}
//         }
//         for(int k = i + 1;k < n;k++){
//             if(arr[k] < temp) {right = false;break;}
//         }
//         if( left && right) res.push_back(temp);
//     }
//     sort(res.begin(),res.end());
//     int len = res.size();
//     cout<<len<<endl;
//     for (int i = 0; i < len; i++)
//     {       
//         if(i == 0) cout<<res[i];
//         else cout<<" "<<res[i];
//     }
    
//     return 0;
// }