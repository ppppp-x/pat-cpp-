#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num(n,0);
    vector<bool> map(100,false);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int temp = num[i]*10+num[j];
            if(!map[temp]) {
                res += temp;
                map[temp] = true;
            }
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int temp = num[i]*10+num[j];
            if(!map[temp]) {
                res += temp;
                map[temp] = true;
            }
        }
        
    }
    cout<<res<<endl;
    return 0;
}