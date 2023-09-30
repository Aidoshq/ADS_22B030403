#include <iostream>
#include <string>
using namespace std;

string processString(string s) {
string result;
for (char ch : s){
    if (ch== '#') {
        if (!result.empty()) {
            result.pop_back();
        }
    } else {
        result.push_back(ch);
    }
}
return result;
}

int main () {

string s1 , s2;
cin>>s1>>s2;

string processed_s1 = processString(s1);
string processed_s2 = processString(s2);

if (processed_s1 == processed_s2) {
    cout<<"Yes";
} else {
    cout<<"No";
}
    return 0;
}