#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
int M;
int map[1000][1000];
bool visited[1000][1000][2]; // false�� �湮 x
							 // [i][j][0] �������� �� ���� ���� ���� ���� [i][j][1] ���� ����
vector<pair<int, int>> oneidx;
int dirt[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // �ϵ�����

struct Info {
	int y;
	int x;
	int cost; // (0, 0)���� (y, x)�� ���� �ִ� �Ÿ�
	bool breakwall; // ���� ���� ���� ��ǥ�� �Դ��� ǥ��
	Info(int _y, int _x, int _cost, bool _breakwall) : y(_y), x(_x), cost(_cost), breakwall(_breakwall) {};
};

int BFS() { // (N, M)�� cost�� ��ȯ
	queue<Info> q;
	Info tinfo(0, 0, 1, false); // y, x, cost
	visited[0][0][0] = true;
	q.push(tinfo);
	while (!q.empty()) {
		tinfo = q.front();
		if (tinfo.y == N - 1 && tinfo.x == M - 1) {
			return tinfo.cost;
		}
		bool bw = tinfo.breakwall;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int dy = tinfo.y + dirt[i][0];
			int dx = tinfo.x + dirt[i][1];
			if (dx >= 0 && dy >= 0 && dx < M && dy < N && visited[dy][dx][bw] == false) { // �湮���� ���� ���
				if (map[dy][dx] == 0) { // 0�̾ �湮 ������ ���
					visited[dy][dx][bw] = true;
					q.push(Info(dy, dx, tinfo.cost + 1, bw));
				}
				else if (bw == false) { // �������� ���� ���� ���� ���� �������μ� �湮 ������ ���
					visited[dy][dx][true] = true;
					q.push(Info(dy, dx, tinfo.cost + 1, true));
				}
			}
		}
	}
	return -1;
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			int k = s[j] - '0';
			map[i][j] = k;
			if (map[i][j] == 1) {
				oneidx.push_back(make_pair(i, j));
			}
		}
	}

	cout << BFS();


	return 0;
}