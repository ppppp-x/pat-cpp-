#include <bits/stdc++.h>
using namespace std;
//先判断是不是插入排序，不是插入排序就是归并排序
int main(){
    int n;
    cin>>n;
    vector<int> origin(n,0);
    vector<int> target(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>origin[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>target[i];
    }//初始化数组
    int index = 0;
    while(index < n && target[index + 1]>=target[index]){
        index++;
    }
    int sort_end = index + 1;
    bool flag = true;
    for(int i = sort_end;i < n;i++){
        if(origin[i] != target[i]){
            flag = false;
            break;
        }  
    }
    if(flag){
        cout<<"Insertion Sort"<<endl;
        //插入排序再迭代一轮
        sort(target.begin(),target.begin()+sort_end+1);//注意左闭右开
    }else{
        cout<<"Merge Sort"<<endl;
        //归并排序再迭代一轮
        int k = 1;
        bool match = false;
        
        // 只要还没匹配，或者匹配了但还没进行"下一步"，就继续循环
        while (true) {
            // 每次匹配完都要做"下一步"操作，所以用标志位控制
            match = (origin == target);
            
            // 增加步长
            k *= 2;
            
            // 执行一次归并 pass
            // 每次对长度为 k 的子序列进行排序
            for (int j = 0; j < n / k; j++) {
                sort(origin.begin() + j * k, origin.begin() + (j + 1) * k);
            }
            // 处理尾部剩余不足 k 的部分
            sort(origin.begin() + (n / k) * k, origin.end());
            
            if (match) {
                target = origin; // 更新结果用于输出
                break;
            }
        }
    }

    //输出结果
    for (int i = 0; i < n; i++)
    {
        if(i){
            cout<<" "<<target[i];
        }else cout<<target[i];
    }
    
    return 0;
}