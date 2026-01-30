#include <bits/stdc++.h>
using namespace std;
//mapping，开数组把ASCII码直接映射
int main(){
    string str;
    getline(cin,str);
    vector<int> arr(128,0);
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z' ) || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            arr[str[i]]++;
        }
    }
    int max = 0;
    int index = 0;
    for(int i = 'A';i <= 'Z';i++){
        if(arr[i] + arr[i + 32] > max){
            max = arr[i] + arr[i + 32];
            index = i + 32;
        }
    }
    cout<<(char)index<<" "<<max<<endl;
    return 0 ;
}