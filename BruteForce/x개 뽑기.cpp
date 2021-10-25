#include <iostream>
#include <vector>
using namespace std;

int arr[5] = { 1, 2, 3, 4, 5 };
vector<int> v;

void Print1(int idx, int cnt, int len) { // 5���� len�� �̱�, �ߺ� X, �ݺ��� ����
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

	//���� 
	v.push_back(arr[idx]);
	Print1(idx + 1, cnt + 1, len);

	v.pop_back();
	//���� X
	Print1(idx + 1, cnt, len);
}

void Print2(int idx, int cnt, int len) { // 5���� len�� �̱�, �ߺ� X, �ݺ��� ����
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

	//���� 
	v.push_back(arr[idx]);
	Print2(0, cnt + 1, len);

	v.pop_back();
	//���� X
	Print2(idx + 1, cnt, len);
}

void Print3(int idx, int cnt, int len) { // �ߺ� X, �ݺ���
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

void Print4(int idx, int cnt, int len) { // �ߺ� O, �ݺ���
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
		cout << i << "��" << endl;
		Print4(0, 0, i);
		cout << endl;
	}
	return 0;
}