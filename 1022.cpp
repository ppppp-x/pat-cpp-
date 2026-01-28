#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t a,b,c;
    cin>>a>>b>>c;
    size_t res = a + b;
    vector<int> n;
    while( res >= c){
        n.push_back(res % c);
        res = res / c;
    }
    n.push_back(res);
    int len = n.size();
    for(int i = len - 1;i >= 0; i--){
        cout<<n[i];
    }  
    return 0;
}
