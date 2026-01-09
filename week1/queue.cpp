#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> box(N), cus(L);

    for(int i = 0; i < N; i++){
        cin >> box[i];
    }
    for(int j = 0; j < L; j++){
        cin >> cus[j];
    }

    for(int x : cus){
        if(x == 1){
            cout << 0 << "\n";
            continue;
        }

        int chair = 0;
        int idx = x - 1; 

        for(int i = 0; i < idx; i++){
            if(box[i] >= box[idx]){
                chair = max(chair, box[i] + 1 - box[idx]);
            }
        }
        cout << chair << "\n";
    }
}
