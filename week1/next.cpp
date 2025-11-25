#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int box[N],check[N],hav[N],old[N];
    int nub = 0 ;
    int round = 0;

    for(int i = 0; i < N; i++){
        cin >> box[i];
        hav[i] = i;
        old[i] = i;
        check[i] = 0;
    }

    while (nub != N){

        for(int i = 0; i<N; i++){ 
            int target = box[i]-1;
            hav[target] = old[i];

            if(hav[target] == target && check[target] == 0){
                nub++;
                check[target] = 1;
            }

       }
       
        for(int i = 0; i<N; i++) old[i] = hav[i];
        round++;
    }

    cout << round;
    return 0;
}
