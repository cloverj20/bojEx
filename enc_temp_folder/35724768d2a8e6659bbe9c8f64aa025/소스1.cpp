#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int dp[1001][2] = { {0} };
	int value[1001][3] = { {0} };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> value[i+1][j];
		}
	}
	int min = 2000;
	int minIn;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			if (min > value[1][i] + value[2][j]) {
				min = value[1][i] + value[2][j];
				minIn = j;
			}
		}
	}
	dp[2][0] = min;
	dp[2][1] = minIn;
	
	for (int i = 3; i <= n; i++) {
		min = 2000;
		for (int j = 0; j < 3; j++) {
			if (dp[i-1][1] == j) {
				continue;
			}
			if (value[i][j] < min) {
				min = value[i][j];
				minIn = j;
			}
		}
		dp[i][0] = dp[i - 1][0] + value[i][minIn];
		dp[i][1] = minIn;
	}
	cout << dp[n][0];
	return 0;
}