#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> score(m,0);
    for (int i = 0; i < m; i++)
    {
        cin>>score[i];
    }
    vector<int> ans(m,0);
    for (int i = 0; i < m; i++)
    {
        cin>>ans[i];
    }
    for (int i = 0; i < n; i++)
    {
        int grade = 0;
        vector<int> stu_ans(m,0);
        for (size_t i = 0; i < m; i++)
        {
            cin>>stu_ans[i];
        }
        for (int i = 0; i < m; i++)
        {
            if(stu_ans[i] == ans[i]){
                grade += score[i];
            }
        }
        cout<<grade<<endl;
    }
    return 0;
}