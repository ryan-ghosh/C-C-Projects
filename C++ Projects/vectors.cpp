#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> practice = {2,4,5,1,7};
    for(int i : practice){
        cout << i << " ";
    }cout << "\n";
    reverse(practice.begin(), practice.end());
    for(int j : practice){
        cout << j << " ";
    }cout << "\n";
    cout << *max_element(practice.begin(), practice.end()) << endl;
    cout << *min_element(practice.begin(), practice.end()) << endl;
    cout << distance(practice.begin(), find(practice.begin(), practice.end(), 4)) << endl;

}