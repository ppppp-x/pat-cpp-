#include<bits/stdc++.h>
using namespace std;
//无需定义全部变量，使用过的无需储存

int main(){
    int n;
    cin>>n;
    char dash;
    int res_team = 0,res_grade = 0;
    vector<int> num(1005,0);
    
    while(n--){
        int team_num,teammate_num,grade;
        cin>>team_num>>dash>>teammate_num>>grade;
        num[team_num] = num[team_num] + grade;
    }//记录成绩

    for(int i = 0;i < 1005;i++){
        if(num[i] > res_grade) {
            res_team = i;
            res_grade = num[i];
        }
    }//统计成绩最高队伍编号和最高成绩
    cout<<res_team<<" "<<res_grade<<endl;
    return 0;
}
