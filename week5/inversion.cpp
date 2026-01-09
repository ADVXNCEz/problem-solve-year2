#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp;
    int i = left, j = mid + 1;
    long long inv = 0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inv += (mid - i + 1);  
        }
    }

    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= right) temp.push_back(arr[j++]);

    for(int k = 0; k < temp.size(); k++){
        arr[left + k] = temp[k];
    }

    return inv;
}

long long mergesort(vector<int>& arr, int left, int right){
    if(left >= right) return 0;

    int mid = left + (right - left) / 2;
    long long inv = 0;

    inv += mergesort(arr, left, mid);
    inv += mergesort(arr, mid + 1, right);
    inv += merge(arr, left, mid, right);

    return inv;
}

int main(){
    int num;
    cin >> num;

    vector<int> box(num);
    for(int i = 0; i < num; i++){
        cin >> box[i];
    }

    cout << mergesort(box, 0, num - 1);
}
