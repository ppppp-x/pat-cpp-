//打印⭐
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//首先计算能打几层

    int n;
    char c;
    cin>>n>>c;
    int count = 1;
    int a = 3;
    n = n - 1;
    while( n > 0){
        if(n - a * 2 >= 0){
            count++;
            n = n - a * 2;
            a+=2;
        }else break;
    }
    int num_star = 1 + (count - 1) * 2;
    int num = num_star;
    while(num_star > 0){
        //判断输入空格
        if(num != num_star){
            int j = (num - num_star)/2;
            while(j--){
                cout<<" ";
            }
        }
        for(int i = 0;i < num_star;i++){
            if(i == num_star - 1) cout<<c<<endl;
            else cout<<c;
        }
        num_star-=2;
    }
    int begin = 3;
    int block = (num - 1)/2 - 1;//最多需要打印的空格
    while(begin <= num){
        //输入空格
        if(begin != num){
            int j = block;
            while(j--){
                cout<<" ";
            }
        }
        block--;
        for(int i = 0;i < begin;i++){
            if(i == begin - 1){
                cout<<c<<endl;
            }else cout<<c;
        }
        begin+=2;
    }
    cout<<n<<endl;
    return 0;
}    
