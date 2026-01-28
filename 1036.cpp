#include <bits/stdc++.h>
using namespace std;

int main(){
    float n = 0;
    char c;
    cin>>n>>c;
    float count = n;
    while(count--){
        cout<<c;
    }
    int row = round(n/2) - 2;
    while(row--){
    	int i = n - 2;
        cout<<endl;
        cout<<c;
        while(i--) cout<<" ";
        cout<<c;
    }
    cout<<endl;
    while(n--){
        cout<<c;
    }
    return 0;
}
