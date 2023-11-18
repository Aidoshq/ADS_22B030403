#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin>>n;
    vector <long long> v(n);
    for (int i=0 ; i<n ; i++) {
        cin>> v[i];
    }

    string  s = "";
    long long x=2;
    s+=char('a' + v[0]);
    for (int i=1; i<v.size(); i++) {
        s+= char('a'+((v[i]-v[i-1])/x));
        x*=2;
    }
    cout<<s<<"\n";

    return 0;
}