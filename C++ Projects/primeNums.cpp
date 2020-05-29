#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


bool isPrime(int n){
    for(int i=2; i<n/2+1; i++){
        if(n%i==0){
            return false;
        }
    }return true;
}
void allPrimes(int n){
    for(int i=0; i<=n;i++){
        if(i<=3){
            cout << i << endl;
        }
        if(i>3 && i%2!=0){
            if(isPrime(i)){
                cout << i << endl;
            }
        }
    }
}
int main(){
    int num;
    cout << "enter a number: ";
    cin >> num;
    allPrimes(num);
}