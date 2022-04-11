#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> A(n);
vector<int> B(n);

int main() {
	cin >> n;
	int input;
	for (int i = 0; i < n; i++) {

		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		B.push_back(input);
	}
	//B�� ���� ū ����� �ε����� �迭�� �Է�
	vector<int> temp;
	int usedB[50] = { 0 };
	
	int cnt = 0;
	while (cnt <n) {
		int maxIn = 0;
		int maxV = 0;
		for (int i = 0; i < n; i++) {
			if (maxV < B[i] && usedB[i] == 0) {
				maxV = B[i];
				maxIn = i;
			}
		}
		temp.push_back(maxIn);
		usedB[maxIn] = 1;
		cnt++;
	}
	//A�� ���� ������� ����
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (A[i] > A[j]) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	//�� �迭�� A�� B ��Ҷ� ��Ī
	vector<int> newA(n);
	for (int i = 0; i < n; i++) {
		newA[temp[i]] = A[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += newA[i] * B[i];
	}

	cout << sum;
	return 0;
}
