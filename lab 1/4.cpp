#include <iostream>

#include <iostream>

using namespace std;

int main(){

int n;
cin >> n;

int a[n];
int b[n];
for(int i = 0; i < n; i++){
    cin >> a[i];
}


for(int i = 1; i <= n; i++){
    for(int j = i - 1; j >= 0; j--){
    if(a[j] <= a[i]){
        b[i] = a[j];
        break;
    }
    else
    b[i] = -1;
}
}
b[0] = -1;

for(int i = 0; i < n; i++){
    cout << b[i] << " ";
}




    return 0;
}