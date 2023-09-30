#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){

char s;
int n;
deque <int > dq;
vector<int > v;
vector<int > err;
string s1;
int cnt = 0;
while(cin >> s){
    if(s == '!'){
        break;
    }
    
    
    else if(s == '+'){
        cin >> n ;
        dq.push_front(n);
    }
    else if(s == '-'){
        cin >> n ;
        dq.push_back(n);
    }
    
    else if(s == '*'){
        if(dq.size() >= 2){
        cout << dq.front() + dq.back() << endl;;
        dq.pop_back();
        dq.pop_front();  
        }
    
        else if(dq.size() == 1){
        cout << dq.front()+dq.front() << endl;;
        dq.pop_front();
    }
        else if(dq.size() == 0){
        cout << "error" << endl;
    }
    }
}

  return 0;
}