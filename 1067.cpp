#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans;
    int k;
    cin >> ans >> k;
    getchar(); // consume newline
    
    string temp;
    int count = 0;
    while(1) {
        getline(cin, temp);
        if (temp == "#") break;
        
        count++;
        if (temp == ans) {
            cout << "Welcome in" << endl;
            break;
        } else {
            cout << "Wrong password: " << temp << endl;
            if (count == k) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}