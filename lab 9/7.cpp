#include <iostream>

#include <vector>

using namespace std;

vector <int> prefixFun(string s) {
    int n = (int) s.size();
    vector <int> pi(n);
    for (int i=1 ; i<n ; i++) {
        int j = pi[i-1];
        while (j>0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;

}

int main () {
    string s;
cin>>s;

vector <int> ans = prefixFun(s);
cout<<s.size() - ans.back() ;

return 0;
}