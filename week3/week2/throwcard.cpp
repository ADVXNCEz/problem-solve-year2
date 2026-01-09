#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        queue<int> deck;
        for (int i = 1; i <= n; i++) deck.push(i);

        cout << "Discarded cards: ";
        while (deck.size() > 1) {
            cout <<deck.front();
            if(deck.size()!=2)cout << ",";
            cout << " ";
            deck.pop();
            int first_card = deck.front();
            deck.push(first_card);
            deck.pop();
        }

        cout << "\nRemaining card: " << deck.front() << "\n";
    }
}
