#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,a,b,k;
    cin>>m>>n>>a>>b>>k;
    for (int i = 0; i < m * n; i++)
    {
        int temp;
        cin>>temp;
        if(i % n == 0){
            if(temp >=a && temp <= b) printf("%03d",k);
            else printf("%03d",temp);
        }else {
            if(temp >=a && temp <= b) printf(" %03d",k);
            else printf(" %03d",temp);
        }
        if((i+1)%n==0) cout<<endl;
    }
    return 0;
}