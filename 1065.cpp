#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin>>m;
    vector<int> pair(100000,-1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        pair[a] = b;
        pair[b] = a;
    }
    int n;
    cin>>n;
    vector<int> guest(n);
    vector<bool> is_present(100000,false);
    for (int i = 0; i < n; i++)
    {
        cin>>guest[i];
        is_present[guest[i]] = true;
    }
    set<int> res;
    for (int i = 0; i < n; i++)
    {
        int c = guest[i];
        if(pair[c] != -1 && is_present[pair[c]]) continue;
        else res.insert(c);
    }
    cout<<res.size()<<endl;
    bool flag = true;
    for(int x : res){
        if(flag) printf("%05d",res);
        else printf(" %05d",res);
        flag = false;
    }
    return 0;
}