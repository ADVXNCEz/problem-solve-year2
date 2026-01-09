#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, T;
    cin >> N >> S >> T;

    vector<int> box(N);
    for(int i = 0; i < N; i++) cin >> box[i];

    sort(box.begin(), box.end());

    long long count = 0;
    int i = 0, j = N - 1;

    while(i < j){
        if(box[i] + box[j] >= S && box[j] - box[i] <= T){
            // ทุกคู่ (i, i+1 ... j-1) กับ j ใช้ได้
            count += (j - i);
            j--;
        } else {
            i++;
        }
    }

    cout << count;
}
