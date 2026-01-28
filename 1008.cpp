#include <bits/stdc++.h>
using namespace std;

//先写出循环右移一位的情况，在使用for循环循环右移M位

int main(){
    int m = 0,n = 0;
    cin>>n>>m;
    int temp;
    vector<int> arr(n,0);

    for(int i =0;i < n;i++){
         cin>>arr[i];
    }
	
    for(int j = 0;j < m;j++){
    	temp = arr[arr.size() - 1];
        for(int i = n - 2;i >= 0;i--){
            arr[i + 1] = arr[i];
         }
         arr[0] = temp;
    }
	
    for(int i = 0;i<n;i++){
        if( i != n - 1){
            cout<<arr[i]<<" ";
        }else cout<<arr[i];
    }
    
    return 0;
}
