#include <iostream>
#include <stack>

using namespace std;

bool check (string s) {
    stack <char> blnc;
    for (int i=0 ; i<s.size() ; i++) {
        if(blnc.empty()) {
            blnc.push(s[i]) ;
        }
        else if(blnc.top() == s[i]) {
            blnc.pop();
        }
        else {
            blnc.push(s[i]);
        }
    }
    return blnc.empty();
}

int main () {
 string s;
 cin>>s ;
 if(check(s))
    cout<<"YES";
else
    cout<<"NO";

    return 0;
}