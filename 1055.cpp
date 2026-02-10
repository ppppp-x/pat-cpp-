#include <bits/stdc++.h>
using namespace std;

struct stu {
    string name;
    int height;
};

int main() {
    int n,k;
    cin>>n>>k;
    vector<stu> student(n);
    for (int i = 0; i < n; i++)
    {
        cin>>student[i].name>>student[i].height;
    }
    sort(student.begin(),student.end(),[](const stu& a,const stu& b){
        if(a.height != b.height) return a.height > b.height;
        else return a.name < b.name; 
    });//LAMBDA expression
    int t = 0;
    for (int i = 0; i < k; i++)
    {
        int m = (i == 0) ? n/k+n%k : n/k;
        vector<string> temp(m);
        int mid = m/2;
        int left = mid - 1;
        int right = mid + 1;
        temp[mid] = student[t++].name;
        while(left >= 0 || right < m){
            if(left >= 0){
                temp[left--] = student[t++].name;
            }
            if(right < m){
                temp[right++] = student[t++].name;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if(i == 0) cout<<temp[i];
            else cout<<" "<<temp[i];
        }
        cout<<endl;
    }
    return 0;
}
