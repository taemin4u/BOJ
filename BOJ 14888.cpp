#include<iostream>
// +   -   *   /
using namespace std;

int n;
int result;
int arr[11];
int oper[4];
int maxnum = -100000;
int minnum = 100000;

void Tracking(int start) {
	if (start == n) {
		if (result >= maxnum) maxnum = result;
		if (result <= minnum) minnum = result;
		return;
	}
	for (int j = 0; j < 4; ++j) {
		int tmp;
		if (oper[j] != 0) {
			if (j == 0) result += arr[start];
			else if (j == 1) result -= arr[start];
			else if (j == 2) result *= arr[start];
			else if (j == 3) {
				tmp = result % arr[start];
				result /= arr[start];
			}
			
			oper[j]--;
			Tracking(start + 1);
			oper[j]++;
			if (j == 0) result -= arr[start];
			else if (j == 1) result += arr[start];
			else if (j == 2) result /= arr[start];
			else if (j == 3) {
				result *= arr[start];
				result += tmp;
			} 
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	result = arr[0];
	for (int i = 0; i < 4; ++i) cin >> oper[i];
	Tracking(1);
	cout << maxnum << '\n' << minnum;
	return 0;
}
