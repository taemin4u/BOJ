#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 암호는 최소 모음 한개, 자음 두개
// 사전순

int l; // 암호의 길이
int c; // 문자 개수
int check[15];
vector<char> arr(15);
vector<char> tmp;
vector<vector<char>> result;

bool Isok() {
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		char ch = tmp[i];
		if (ch == 'a') {
			mo++;
		}
		else if (ch == 'e') {
			mo++;
		}
		else if (ch == 'i') {
			mo++;
		}
		else if (ch == 'o') {
			mo++;
		}
		else if (ch == 'u') {
			mo++;
		}
	}
	ja = tmp.size() - mo;
	if (mo < 1 || ja < 2) {
		return false;
	}
	return true;
}

void print() {
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j];
		}
		cout << endl;
	}
}

void Get(int start, int len) {
	if (len == l && Isok()) {
		vector<char> save(tmp);
		sort(tmp.begin(), tmp.end());
		result.push_back(tmp);
		tmp = save;
		return;
	}

	int firstfree = -1;
	for (int i = start; i < c; ++i) {
		if (check[i] == 0) {
			firstfree = i;
			break;
		}
	}

	if (firstfree != -1) {
		for (int pick = firstfree; pick < c; ++pick) {
			tmp.push_back(arr[pick]);
			check[pick] = 1;
			Get(pick + 1, len + 1);
			tmp.pop_back();
			check[pick] = 0;
		}
	}
}



int main() {

	cin >> l >> c;
	for (int i = 0; i < c; ++i) {
		cin >> arr[i];
	}

	Get(0, 0);
	print();

	return 0;
}