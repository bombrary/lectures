#include <iostream>
#include <vector>

#define MAX_COMB 1000

using namespace std;

bool comb[MAX_COMB][MAX_COMB] = { };

int main() {
	int N;

	cin >> N;
	comb[0][0] = true;
	for(int i = 1; i < N; i++) {
		comb[i][0] = comb[i][i - 1] = true;
		for(int j = 1; j < i - 1; j++) {
			comb[i][j] = comb[i - 1][j - 1] ^ comb[i - 1][j];
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < i; j++) {
			if(comb[i][j]) cout << 'o';
			else cout << ' ';
		}
		cout << endl;
	}

	return 0;
}
