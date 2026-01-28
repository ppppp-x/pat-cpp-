#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b;
	int da,db;
	int res_a =0,res_b = 0;
	int counta = 0,countb = 0;
	
	cin>>a>>da>>b>>db;
	
    for(int i = 0;i<a.size();i++){
    	if(a[i] - '0' == da) counta++;
	}
	
	for(int i = 0;i<counta;i++){
		res_a = da + res_a*10;
	}
	
	for(int i = 0;i<b.size();i++){
		if(b[i] - '0' == db) countb++; 
	}
	
	for(int i = 0;i<countb;i++){
		res_b = db + res_b*10;
	}
	
	cout<<res_a + res_b<<endl;
	
    return 0;
}
