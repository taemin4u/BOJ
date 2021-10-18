#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int result = -1;
int h, w;
int map[8][8];
int tmp[8][8];

int dirt[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void Copy() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			tmp[i][j] = map[i][j];
		}
	}
}

int GetZero() {
	int sum = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (tmp[i][j] == 0) sum++;
		}
	}
	return sum;
}

void BFS() {
	queue<pair<int, int>> q;
	pair<int, int> p;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (tmp[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nexty = y + dirt[i][0];
			int nextx = x + dirt[i][1];
			if (nexty >= 0 && nexty < h && nextx >= 0 && nextx < w) {
				if (tmp[nexty][nextx] == 0) {
					tmp[nexty][nextx] = 2;
					q.push(make_pair(nexty, nextx));
				}
			}
		}
	}
}

void Setwall(int cnt) {
	if (cnt == 3) {
		Copy();
		BFS();
		result = max(result, GetZero());
		return;
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				Setwall(++cnt);
				map[i][j] = 0;
				cnt--;
			}
		}
	}
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> map[i][j];
		}
	}
	Setwall(0);
	cout << result << endl;
	return 0;
}