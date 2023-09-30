#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

bool primeF(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){

int n;

cin >> n;
vector<int> super_prime;
vector<int> prime;

prime.push_back(0);

for(int i = 2; i < 100000; i++){
    if(primeF(i))
        prime.push_back(i);

}


for(int i = 2; i < prime.size(); i++){
    if(primeF(i)){
        super_prime.push_back(prime[i]);
    }
}



cout << super_prime[n-1];
    return 0;
}