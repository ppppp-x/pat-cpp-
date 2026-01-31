#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    cin>>line;
    map<char, int> mp = {{'P',0},{'A',0},{'T',0},{'e',0},{'s',0},{'t',0}};
    int len = line.length();
    for(char c : line){
        if(mp.find(c) != mp.end()){
            mp[c]++;
        }
    }
    string target = "PATest";
    while(true){
        bool flag = false;
        for(char c : target){
            if(mp[c] != 0){
                cout<<c;
                mp[c]--;
                flag = true;
            }
        }
        if(!flag) break;
    }

    return 0;
}