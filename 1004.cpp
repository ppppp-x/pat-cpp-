#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<string>> num(n,vector<string>(2));//初始化存储姓名学号
    vector<int> grade(n,0);//初始化存储成绩
    int maxgrade = 0,mingrade = 101,maxindex = -1,minindex = -1;
    
    for(int i = 0;i<n;i++){
        cin>>num[i][0]>>num[i][1]>>grade[i];
    }//输入姓名，学号，成绩
    
    for(int i = 0;i < n;i++){
        if(grade[i] > maxgrade){
            maxgrade = grade[i];
            maxindex = i;
        }
		if(grade[i] < mingrade){
            mingrade = grade[i];
            minindex = i;
        }
    }
    cout<<num[maxindex][0]<<" "<<num[maxindex][1]<<endl;
    cout<<num[minindex][0]<<" "<<num[minindex][1]<<endl;
    
    return 0;
}
