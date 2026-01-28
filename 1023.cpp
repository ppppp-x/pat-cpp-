#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a(10);
	for(int i = 0;i<10;i++){
		cin>>a[i];
	} 
	
	for(int i = 0;i<a.size();i++){
		if(i != 0 && a[i] != 0){
			cout<<i;
			a[i]--;
			break; 
		}
	}
	 for(int i = 0;i<a.size();i++){
	 	while(a[i]){
	 		cout<<i;
	 		a[i]--;
		 } 
	 }
	
	return 0;
}
