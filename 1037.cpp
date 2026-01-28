#include <bits/stdc++.h>
using namespace std;

int main(){
    struct money{
        int sickle;
        int galleon;
        int knut;
    };
    
    money a,b;
    scanf("%d.%d.%d %d.%d.%d",&a.galleon,&a.sickle,&a.knut,&b.galleon,&b.sickle,&b.knut);
    int money_a = (a.galleon * 17 + a.sickle) * 29 + a.knut;
    int money_b = (b.galleon * 17 + b.sickle) * 29 + b.knut;
    int ans = money_b - money_a;
    int abs_ans = abs(money_b - money_a);
    int ans_gallon = abs_ans / (17 * 29);
    int ans_sickle = (abs_ans % (17 * 29))/29;
    int ans_kunt = abs_ans % 29;
    if(ans >= 0) cout<<ans_gallon<<"."<<ans_sickle<<"."<<ans_kunt;
    else cout<<"-"<<ans_gallon<<"."<<ans_sickle<<"."<<ans_kunt;
    return 0;
}