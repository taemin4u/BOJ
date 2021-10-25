#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dirt[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int map[100][100];
bool check[100][100];
int n;
int rain;

int BFS();
bool Find(int& row, int& col) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (check[i][j] == true) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

void Setcheck(int r) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] > r) {
				check[i][j] = true;
			}
			else check[i][j] = false;
		}
	}
}

void Getrain() {
	rain = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			rain = max(rain, map[i][j]);
	}
}

int Getcnt() {
	
	int cnt = 0;
	queue<pair<int, int>> q;
	int row, col;
	if (Find(row, col) == false) {
		return cnt;
	}
	else if (Find(row, col) == true) {
		q.push(make_pair(row, col));
		check[row][col] = false;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nexty = y + dirt[i][0];
				int nextx = x + dirt[i][1];
				if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n) {
					if (check[nexty][nextx] == true) {
						check[nexty][nextx] = false;
						q.push(make_pair(nexty, nextx));
					}
				}
			}
		}
		cnt++;
		cnt += Getcnt();
	}
	return cnt;
}

int BFS() {
	Getrain();
	int ret = 0;
	for (int ra = 0; ra < rain; ++ra) {
		Setcheck(ra);
		ret = max(ret,Getcnt());
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	}

	
	cout << BFS() << endl;
	

	return 0;
}
