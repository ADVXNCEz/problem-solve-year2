#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    pair<int,int> job[MAX_N];
    cin >> N;
    int d,c;

    for(int i = 0; i<N; i++){
        cin >> d >> c;
        job[i]= {d,c};
    }

    sort(job,job+N);
    int fine = 0;
    int sum = 0;
    for(int i= 0; i<N; i++){
        sum += job[i].second;
        if(job[i].first < sum-10){
            fine = max((sum-job[i].first-10)*1000,fine);
        }
    }
    cout << fine;
}
