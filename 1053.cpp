#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double e;
    int d;
    cin>>n>>e>>d;
    int possible_empty = 0;
    int empty = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int k;
        cin>>k;
        vector<double> data(k);
        for (int i = 0; i < k; i++)
        {
            cin>>data[i];
            if(data[i] < e) count++;
        }
        if (k <= d && count > k / 2) possible_empty++;
        if( k > d && count > k / 2) empty++;
    }
    printf("%.1f%% %.1f%%",(double)possible_empty / n * 100,(double)empty / n * 100);
    return 0;
}