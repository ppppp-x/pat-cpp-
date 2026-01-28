#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<string> arr;

    while(cin>>s){
        arr.push_back(s);
    }

    for(int i = arr.size() - 1;i >=0;i--){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

