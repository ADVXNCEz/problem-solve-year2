#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int box[N],check[N],hav[N];
    int nub = 0 ;
    int round =0;

    for(int i = 0; i<N; i++){
        cin >> box[i];
        hav[i] = box[i];
        check[i] = 0;
    }
    int i = 0;

    int temp = hav[0];
    while (nub == N){
        int n = box[i]-1;
        temp = hav[n];
        hav[n] = temp;

        if(hav[n] == i+1){
            if(check[i] == 0){
                check[i] = 1;
                nub ++;
            }
        }

        i++;
        i %=N;
        round++;
    }

    cout << round;
    return 0;
}
