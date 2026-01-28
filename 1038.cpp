#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin>>n;
    vector<int> stu(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>stu[i];
    }
    int k = 0;
    cin>>k;
    vector<int> grade(k,0);
    vector<int> count(k,0);
    for(int i = 0;i < k;i++){
        cin>>grade[i];
    }    
    //给出查询一个分数的过程，然后for循环解决
    for( int i = 0;i < k;i++){
        int target = grade[i];
        for(int j = 0;j < n;j++){
            if(stu[j] == target){
                count[i]++;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if( i == k - 1) cout<<count[i];
        else cout<<count[i]<<" ";
    }
    return 0;
}