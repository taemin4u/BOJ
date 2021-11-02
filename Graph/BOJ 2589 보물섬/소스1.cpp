#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int M;
char map[50][50];
bool check[50][50];
int dirt[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // y, x
vector<pair<int, int>> landidx;

struct Info {
	int y;
	int x;
	int cost;
	Info(int y, int x, int cost) : y(y), x(x), cost(cost) {};
};

void Tofalse() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			check[i][j] = false;
		}
	}
}
int DFS(int i, int j) {
	int re = -1;
	queue<Info> q;
	Info info(0, 0, 0);
	q.push(Info(i, j, 0));
	check[i][j] = true;
	while (!q.empty()) {
		info = q.front();
		re = max(re, info.cost);
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int dy = info.y + dirt[k][0];
			int dx = info.x + dirt[k][1];
			if (dy >= 0 && dx >= 0 && dy < N && dx < M && check[dy][dx] == false && map[dy][dx] == 'L') {
				q.push(Info(dy, dx, info.cost+1));
				check[dy][dx] = true;	
			}
		}
	}
	return re;
}

int Workspace() {
	int ret = -1;
	for (int start = 0; start < landidx.size(); ++start) {
		int row = landidx[start].first;
		int col = landidx[start].second;
		ret = max(ret, DFS(row, col));
		Tofalse();
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'L') landidx.push_back(make_pair(i, j));
		}
	}

	cout << Workspace();

	return 0;
}