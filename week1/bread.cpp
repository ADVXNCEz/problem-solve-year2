#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int W,H,M,N;

    cin >> W >> H >> M >> N;

    vector<int> hor(M), ven(N);

    for(int i=0; i<M;i++)cin >> hor[i];
    for(int i=0; i<N;i++)cin >> ven[i];

    vector<int> length(0);
    length.push_back(hor[0]);
    for(int i=0;i<M-1;i++){
        length.push_back(hor[i+1]-hor[i]);
    }
    length.push_back(W-hor[M-1]);

    vector<int> height(0);
    height.push_back(ven[0]);
    for(int i=0;i<N-1;i++){
        height.push_back(ven[i+1]-ven[i]);
    }
    height.push_back(H-ven[N-1]);

    vector<int> area(0);

    for(int i = 0; i<height.size();i++){
        for(int j = 0; j<length.size();j++){
            area.push_back(length[j]*height[i]);
        }
    }

    sort(area.begin(), area.end(),greater<int>());


    cout << area[0]<< " "<< area[1];
}