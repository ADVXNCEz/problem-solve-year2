#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, target[1000];
	int i;

	while (true) {
		cin >> n;
		if (n == 0)break;
		while (true) {
			cin >> target[0];
			if (target[0] == 0){
				cout << "\n";
				break;
			}
			for (i = 1; i < n; i++) cin >> target[i];

			int now = 1, nub = 0;
			stack<int> station;
			while(now<=n){
				station.push(now);

				while(!station.empty() && station.top() == target[nub]){
					station.pop();
					nub++;
					if(nub>=n) break;
				}
				now++;
			}

			if(station.empty()) cout << "Yes" << "\n";
			else cout << "No" << "\n";
		}
	}

	return 0;
}