#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
bool isprime(int num){
    if(num <= 1) return false;
    for (int i = 2; i * i <= num;i++){
        if(num % i == 0) return false;
    }
    return true;
}

string judgegift(int id){
    if(mp[id] == 1) return "Mystery Award";
    if(isprime(mp[id])) return "Minion";
    else return "Chocolate";
}

int main(){
    vector<bool> arr(10000,0);
    int n;
    cin>>n;
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin>>id;
        mp[id] = rank;
        rank++;
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int temp_id;
        cin>>temp_id;
        if(mp.find(temp_id) != mp.end()){
            if(arr[temp_id]){
                printf("%04d: Checked\n", temp_id);
            }
            else{
                arr[temp_id] = true;
                string res = judgegift(temp_id);
                printf("%04d: %s\n", temp_id, res.c_str());
            }
        }else {
            printf("%04d: Are you kidding?\n", temp_id);
        }
    }
    return 0;
}