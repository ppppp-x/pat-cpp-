#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    double l = 0.00;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        double temp = (double)sqrt(a*a+b*b);
        if(temp > l) l = temp;
    }           
    printf("%.2f",l);
    return 0;
}