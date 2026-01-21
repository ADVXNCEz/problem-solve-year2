#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, nub;
	queue<int> box;

	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; i++) {
			box.push(i);
		}

		printf("Discarded cards:");
		while (box.size() > 1) {
			printf(" %d", box.front());
			box.pop();
			nub = box.front();
			box.pop();

			if (!box.empty())printf(",");
			box.push(nub);
		}
		printf("\nRemaining card: %d\n", box.front());
		box.pop();
	}

	return 0;
}