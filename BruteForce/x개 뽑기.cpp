#include <iostream>
#include <vector>
using namespace std;

int arr[5] = { 1, 2, 3, 4, 5 };
vector<int> v;

void Print1(int idx, int cnt, int len) { // 5개중 len개 뽑기, 중복 X, 반복문 없이
	if (idx == 6) {
		return;
	}
	if (cnt == len) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	//포함 
	v.push_back(arr[idx]);
	Print1(idx + 1, cnt + 1, len);

	v.pop_back();
	//포함 X
	Print1(idx + 1, cnt, len);
}

void Print2(int idx, int cnt, int len) { // 5개중 len개 뽑기, 중복 X, 반복문 없이
	if (idx == 5) {
		return;
	}
	if (cnt == len) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	//포함 
	v.push_back(arr[idx]);
	Print2(0, cnt + 1, len);

	v.pop_back();
	//포함 X
	Print2(idx + 1, cnt, len);
}

void Print3(int idx, int cnt, int len) { // 중복 X, 반복문
	if (cnt == len) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = idx; i < 5; ++i) {
		v.push_back(arr[i]);
		Print3(i + 1, cnt + 1, len);
		v.pop_back();
	}
}

void Print4(int idx, int cnt, int len) { // 중복 O, 반복문
	if (cnt == len) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = idx; i < 5; ++i) {
		v.push_back(arr[i]);
		Print4(0, cnt + 1, len);
		v.pop_back();
	}
}

int main() {

	for (int i = 1; i <= 5; ++i) {
		cout << i << "개" << endl;
		Print4(0, 0, i);
		cout << endl;
	}
	return 0;
}