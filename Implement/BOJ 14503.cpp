#include <iostream>
#include <algorithm>
using namespace std;
/*
동서남북을 원래 좌표 + 상대적좌표로 표시
*/
int map[50][50];

int dx[4] = { 0, 1, 0, -1 }; // 북 동 남 서
int dy[4] = { -1, 0, 1, 0 };

int N, M;
int row, col, dirt;

int GetCleanarea() {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 2) ++ret;
		}
	}
	return ret;
}

pair<int, int>GetLeftidx(int row, int col, int dirt) { // 좌표와 현재 바라보는 방향을 기준으로 왼쪽 좌표 얻기
	pair<int, int> p;
	int _dx, _dy;
	switch (dirt)
	{
	case 0:
		_dx = col + dx[3];
		_dy = row + dy[3];
		p.first = _dy;
		p.second = _dx;
		break;
	case 1:
		_dx = col + dx[0];
		_dy = row + dy[0];
		p.first = _dy;
		p.second = _dx;
		break;
	case 2:
		_dx = col + dx[1];
		_dy = row + dy[1];
		p.first = _dy;
		p.second = _dx;
		break;
	case 3:
		_dx = col + dx[2];
		_dy = row + dy[2];
		p.first = _dy;
		p.second = _dx;
		break;
	}
	return p;
}

void Robot(int robot_r, int robot_c, int robot_d) {
	map[robot_r][robot_c] = 2; // 현재 좌표를 청소
	pair<int, int> leftidx = GetLeftidx(robot_r, robot_c, robot_d); // 왼쪽 좌표 얻기
	if (map[leftidx.first][leftidx.second] == 0) { // 왼쪽 좌표도 청소 가능하다면
		int nextdirt = robot_d - 1; // 방향전환
		if (nextdirt == -1) nextdirt = 3;
		Robot(leftidx.first, leftidx.second, nextdirt);
	}
	else if (map[leftidx.first][leftidx.second] == 2 || map[leftidx.first][leftidx.second] == 1) { // 청소 불가능
		bool canmove = false;
		pair<int, int> p;
		int nextdirt = robot_d - 1; // 다음 방향
		for (int i = 0; i < 3; ++i) {
			if (nextdirt == -1) nextdirt = 3;
			p = GetLeftidx(robot_r, robot_c, nextdirt); // 다음 방향을 기준으로 왼쪽 좌표를 얻음 -> 원래 북쪽을 바라봤다면 남쪽 좌표가 반환됨
			if (map[p.first][p.second] == 0) {
				canmove = true;
				int _nextdirt = nextdirt - 1; // 방향 조정
				if (_nextdirt == -1) _nextdirt = 3;
				Robot(p.first, p.second, _nextdirt);
				break;
			}
			--nextdirt;
		}
		if (canmove == false) { // 사방이 더이상 청소 불가
			int backy = robot_r + dy[(robot_d + 2) % 4];
			int backx = robot_c + dx[(robot_d + 2) % 4];
			if (map[backy][backx] == 2) { // 후진가능
				Robot(backy, backx, robot_d);
			}
			else if (map[backy][backx] == 1) { // 후진불가능, 종료조건
				cout << GetCleanarea() << '\n';
				return;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> row >> col >> dirt;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	Robot(row, col, dirt);
	return 0;
}