#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
	if(n == 0 || n == 1) return false;
    for(int i = 2;i * i <= n; i++){
        if( n % i == 0){
             return false;
        }
    }
    return true;
}

int main(){
    int n;
    int count = 0;
    cin>>n;
    vector<int> num;
    
    for(int i = 2;i <= n;i++){
        if(isprime(i)){
            num.push_back(i);
        }
    }

    for(int i = 1;i<num.size();i++){
        if(num[i] - num[i - 1] == 2) count++;
    }
    cout<<count;
    
    return 0;
}
