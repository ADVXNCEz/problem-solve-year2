#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;

    int head=0;
    int i = 0;
    while(true){
        if(head + ((2*i)-1) > num)break;
        head += (2*i)-1;
        i++;
    }
    
    cout << head<<" "<< i;


    if(i%2 == 0){
        
    }

}