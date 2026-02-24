#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int N;
pair<int,int> job[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> job[i].first >> job[i].second;
    }

 
    sort(job, job + N, [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    int count = 0;
    int lastEnd = -1;

    for(int i = 0; i < N; i++){
        if(job[i].first >= lastEnd){
            count++;
            lastEnd = job[i].second;
        }
    }

    cout << count;
    return 0;
}
