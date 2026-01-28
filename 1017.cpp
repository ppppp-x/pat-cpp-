#include <bits/stdc++.h>
using namespace std;

//大叔除法，模拟手算过程

int main(){
    string a;
    int b;
    cin>>a>>b;

    for(int i = 0;i < a.size();i++){
        if(a[i] - '0' < b ){
            a[i + 1] = (10*(a[i] - '0') + (a[i + 1] - '0'))%b;
            cout<<(10*(a[i] - '0') + (a[i + 1] - '0'))/b;
        }else {
            a[i] = (a[i] - '0') % b;
            cout<<(a[i] - '0') / b;
            i--;
        }
    }
    cout<<" "<<a[a.size() - 1]-'0';
    return 0;
}
