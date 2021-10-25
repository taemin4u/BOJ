#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ability[20][20];
vector<int> start;
vector<int> link;
int check[20]; // 0이면 선택 가능, 1이면 불가능
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
	for (int i = t; i < n; ++i) { // 0부터 시작하면 uncheck가 1에서 시작하는 Getmin()에서 i가 2일 때 0, 2가 1인데 1이 0이어서 이미 뽑힌 021(012)가 나옴
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