#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = n % 100;
    int b = (n - a * 100) % 10;
    int c = n % 10;
    string s1 = a * 'B';
    string s2 = b * 'S';
    string s3 ;
    for(int i = 1;i <= c; i++){
        s3 += 'i';
    }
    cout<<s1 + s2 + s3;
    return 0;
}
