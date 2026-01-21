#include <bits/stdc++.h>
using namespace std;

int N,B;
vector<int> MAPs;
int dp[300][300];


int MAX_cost(int now,int prev_Merge,int BIG_cost,int remain,bool Merged){
    int best_cost = 0;
    if(dp[now][remain]!=0)return dp[now][remain];

    if(remain == 0 && Merged == false){
        int num=0;
        for(int i = now ;i<N;i++){
            num += MAPs[i];
        }
        return num;
    }

    if(now+1 == N && Merged == true){
        int num = BIG_cost + ((prev_Merge)*BIG_cost)/2;
        int fence = ((prev_Merge))*B;
        return num-fence;
    }

    if(now +1 == N && Merged == false){
        return MAPs[now];
    }

    if(Merged == true){
        int num = BIG_cost + (prev_Merge*BIG_cost)/2;
        int fence = (prev_Merge)*B;
        int stop_Merge = MAX_cost(now+1,0,0,remain,false) + num-fence;
        int con_Merge = MAX_cost(now+1,prev_Merge+1,max(BIG_cost,MAPs[now]),remain,true);

        best_cost = max(stop_Merge,con_Merge);
    }
    if(Merged == false){
        int no_Merge    = MAX_cost(now+1,0,0,remain-1,false) + MAPs[now];
        int start_Merge = MAX_cost(now+1,1,MAPs[now],remain,true);
        best_cost = max(no_Merge,start_Merge);
    }

    return best_cost;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int K;
    cin >> N >> B >> K;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        MAPs.push_back(a);
    }

    cout << MAX_cost(0,0,0,K,false);
}