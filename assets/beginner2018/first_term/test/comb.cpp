#include <iostream>
#include <vector>

#define MAX_COMB 100

using namespace std;

int main() {
	int N;
	int comb[MAX_COMB][MAX_COMB] = { };

	cin >> N;
	comb[0][0] = 1;
	for(int i = 1; i < N; i++) {
		comb[i][0] = comb[i][i - 1] = 1;
		for(int j = 1; j < i - 1; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%3d", comb[i][j]);
		}
		cout << endl;
	}

	return 0;
}
