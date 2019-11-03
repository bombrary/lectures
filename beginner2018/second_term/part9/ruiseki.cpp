#include <iostream>

using namespace std;

long long sum[110000];

int main() {
	int N, K;
	cin >> N >> K;
	sum[0] = 0;
	for(int i = 1; i <= N ; i++) {
		long long a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	
	long long ans = 0;
	for(int i = 0; i < N - K + 1; i++) {
		ans += sum[i + K] - sum[i];
	}
	cout << ans << endl;

	return 0;
}

