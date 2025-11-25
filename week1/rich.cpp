#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int sum = 0;
    cin >> N;
    int n ;
    for(int i = 0; i<N; i++){
        cin >> n;
        if(n>0)sum+=n;
    }
    cout << sum;
    return 0;
}
