#include <iostream>
using namespace std;

int n;
int s;
int arr[20];
int taken[20]; // 0이면 선택가능 1이면 불가능
int ret = 0;
int cnt = 0;

int Get(int startPoint) {
	if (ret == s) {
		cnt++;
	}
	int firstfree = -1;
	for (int i = startPoint; i < n; ++i) {
		if (taken[i] == 0) {
			firstfree = i;
			break;
		}
	}
	if (firstfree != -1) {
		for (int start = firstfree; start < n; ++start) {
			ret += arr[start];
			taken[start] = 1;
			Get(start + 1);
			ret -= arr[start];
			taken[start] = 0;
		}
		
	}
	return cnt;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (s == 0) {
		cout << Get(0) - 1 << endl;
	}
	else cout << Get(0) << endl;
	return 0;
}