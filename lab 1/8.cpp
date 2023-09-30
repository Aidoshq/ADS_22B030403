#include<iostream>
#include<queue>
using namespace std;

int main(){
int n;
string s;
cin >> n >> s;
queue<char> q;
int K_last = 0, K_pts = 0, K_podr = 0;
int S_last = 0, S_pts = 0, S_podr = 0;
for(int i = 0; i < s.size(); i++){
q.push(s[i]);
if(s[i] == 'K'){
    K_last++;
}
else{
    S_last++;
}
}

while(true){
    if(q.front() == 'S'){
        if(K_podr >= 1){
            q.pop();
            K_podr--;
            S_last--;
        }
        else{
            q.push('S');
            q.pop();
            S_podr++;
            S_pts++;
        }
    }
    if(q.front() == 'K'){
        if(S_podr >= 1){
            S_podr--;
            K_last--;
            q.pop();
        }
        else{
            q.push('K');
            q.pop();
            K_podr++;
            K_pts++;
        }
    }
    if(K_last == 0 or S_last == 0){
        if(K_pts > S_pts){
             cout << "KATSURAGI";
            return 0;
        }
        else{
            cout << "SAKAYANAGI";
            return 0;
        }
    }
}
}   
