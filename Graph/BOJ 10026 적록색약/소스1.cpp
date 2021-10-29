#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char map[500][500];
int N;
bool check[500][500];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; //ºÏ µ¿ ³² ¼­
int nonrg = 0;
int rg = 0;

bool Finish() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check[i][j] == true) return false;
		}
	}
	return true;
}
void Non_RG() {
	if (Finish()) {
		return;
	}
	pair<int, int> p;
	queue<pair<int, int>> q;
	bool find = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check[i][j] == true) {
				p.first = i;
				p.second = j;
				find = true;
				break;
			}
		}
		if (find) break;
	}

	q.push(p);
	check[p.first][p.second] = false;
	pair<int, int> tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nexty = tmp.first + dy[i];
			int nextx = tmp.second + dx[i];
			if (nexty >= 0 && nexty < N && nextx >= 0 && nextx < N) {
				if (map[nexty][nextx] == map[tmp.first][tmp.second] && check[nexty][nextx] == true) {
					check[nexty][nextx] = false;
					q.push(make_pair(nexty, nextx));
				}
			}
		}
	}
	++nonrg;
	Non_RG();
}

void RG() {
	if (Finish()) {
		return;
	}
	pair<int, int> p;
	queue<pair<int, int>> q;
	bool find = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check[i][j] == true) {
				p.first = i;
				p.second = j;
				find = true;
				break;
			}
		}
		if (find) break;
	}

	q.push(p);
	check[p.first][p.second] = false;
	pair<int, int> tmp;
	if (map[p.first][p.second] == 'R' || map[p.first][p.second] == 'G') {
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nexty = tmp.first + dy[i];
				int nextx = tmp.second + dx[i];
				if (nexty >= 0 && nexty < N && nextx >= 0 && nextx < N) {
					if ((map[nexty][nextx] == 'R' || map[nexty][nextx] == 'G') && check[nexty][nextx] == true) {
						check[nexty][nextx] = false;
						q.push(make_pair(nexty, nextx));
					}
				}
			}
		}
		++rg;
		RG();
	}
	else if (map[p.first][p.second] == 'B') {
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nexty = tmp.first + dy[i];
				int nextx = tmp.second + dx[i];
				if (nexty >= 0 && nexty < N && nextx >= 0 && nextx < N) {
					if (map[nexty][nextx] == map[tmp.first][tmp.second] && check[nexty][nextx] == true) {
						check[nexty][nextx] = false;
						q.push(make_pair(nexty, nextx));
					}
				}
			}
		}
		++rg;
		RG();
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			check[i][j] = true;
		}
	}

	Non_RG();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			check[i][j] = true;
		}
	}
	RG();
	cout << nonrg << " " << rg;
	return 0;
}