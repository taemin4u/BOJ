#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[50][50];
int check[50][50]; // 0이면 2가 아니거나 이미 뽑힌 2
int mapsize;
int storenum;
vector<pair<int, int>> two;
int ret = 123456789;

int ChckienRoad() {
	int sum = 0;
	for (int i = 0; i < mapsize; ++i) {
		for (int j = 0; j < mapsize; ++j) {
			if (map[i][j] == 1) {
				int road = 101;
				for (unsigned int u = 0; u < two.size(); ++u) {
					road = min(road, abs(i - two[u].first) + abs(j - two[u].second));
				}
				sum += road;
			}
		}
	}
	return sum;
}

bool Isok(int i, int j) {
	if (two.size() == 0) return true;
	else {
		if (two.back().first == i && two.back().second < j) return true;
		else if (two.back().first < i) return true;
	}
	return false;
}

void Pickstore(int cnt) {
	if (cnt == storenum) {
		ret = min(ret, ChckienRoad());
		return;
	}
	for (int i = 0; i < mapsize; ++i) {
		for (int j = 0; j < mapsize; ++j) {
			if (check[i][j] == 1 && Isok(i, j)) {
				check[i][j] = 0;
				two.push_back(make_pair(i, j));
				Pickstore(cnt + 1);
				check[i][j] = 1;
				two.pop_back();
			}
		}
	}
}

int main() {
	cin >> mapsize >> storenum;
	for (int i = 0; i < mapsize; ++i) {
		for (int j = 0; j < mapsize; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < mapsize; ++i) {
		for (int j = 0; j < mapsize; ++j) {
			if (map[i][j] == 2) {
				check[i][j] = 1;
			}
		}

	}

	Pickstore(0);
	cout << ret;
	return 0;
}