#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ability[20][20];
vector<int> start;
vector<int> link;
int check[20]; // 0�̸� ���� ����, 1�̸� �Ұ���
int n;

int ReturnAbility(vector<int> arr);

void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << ReturnAbility(v) << endl;
}

int ReturnAbility(vector<int> arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr.size(); ++j) {
			sum += ability[arr[i]][arr[j]];
		}
	}
	return sum;
}

void Setlink() {
	for (int i = 0; i < n; ++i) {
		if (check[i] == 0) {
			link.push_back(i);
		}
	}
}

int Getmin(int cnt, int t) {
	if (cnt == n / 2) {
		link.clear();
		Setlink();
		print(start);
		cout << endl;
		print(link);
		cout << endl;
		cout << "Start  - link : " << abs(ReturnAbility(start) - ReturnAbility(link)) << endl;
		cout << endl;
		return (abs(ReturnAbility(start) - ReturnAbility(link)));
	}

	int uncheck = -1;
	for (int i = t; i < n; ++i) { // 0���� �����ϸ� uncheck�� 1���� �����ϴ� Getmin()���� i�� 2�� �� 0, 2�� 1�ε� 1�� 0�̾ �̹� ���� 021(012)�� ����
		if (check[i] == 0) {     
			uncheck = i;
			break;
		}
	}
	int ret = 123456789;
	if (uncheck != -1) {
		for (int i = uncheck; i < n; ++i) {
			check[i] = 1;
			start.push_back(i);
			ret = min(ret, Getmin(cnt + 1, i+1));
			start.pop_back();
			check[i] = 0;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ability[i][j];
		}
	}
	cout << Getmin(0, 0) << endl;
	return 0;
}