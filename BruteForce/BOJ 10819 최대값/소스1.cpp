#include<iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<bool> check;
vector<int> save;

int Getresult() {
	int sum = 0;
	for (int i = 0; i < save.size() - 1; ++i) {
		sum += abs(save[i] - save[i + 1]);
	}
	return sum;
}

int DFS(int cnt) {
	if (cnt == n) {
		return Getresult();
	}
	int ret = -1;
	for (int i = 0; i < n; ++i) {
		if (check[i] == true) {
			save.push_back(arr[i]);
			check[i] = false;
			ret = max(ret, DFS(cnt + 1));
			check[i] = true;
			save.pop_back();
		}
		else continue;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		check.push_back(true);
	}
	cout << DFS(0) << '\n';
	return 0;
}