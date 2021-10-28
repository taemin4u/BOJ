#include <iostream>
#include <algorithm>
using namespace std;
/*
���������� ���� ��ǥ + �������ǥ�� ǥ��
*/
int map[50][50];

int dx[4] = { 0, 1, 0, -1 }; // �� �� �� ��
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

pair<int, int>GetLeftidx(int row, int col, int dirt) { // ��ǥ�� ���� �ٶ󺸴� ������ �������� ���� ��ǥ ���
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
	map[robot_r][robot_c] = 2; // ���� ��ǥ�� û��
	pair<int, int> leftidx = GetLeftidx(robot_r, robot_c, robot_d); // ���� ��ǥ ���
	if (map[leftidx.first][leftidx.second] == 0) { // ���� ��ǥ�� û�� �����ϴٸ�
		int nextdirt = robot_d - 1; // ������ȯ
		if (nextdirt == -1) nextdirt = 3;
		Robot(leftidx.first, leftidx.second, nextdirt);
	}
	else if (map[leftidx.first][leftidx.second] == 2 || map[leftidx.first][leftidx.second] == 1) { // û�� �Ұ���
		bool canmove = false;
		pair<int, int> p;
		int nextdirt = robot_d - 1; // ���� ����
		for (int i = 0; i < 3; ++i) {
			if (nextdirt == -1) nextdirt = 3;
			p = GetLeftidx(robot_r, robot_c, nextdirt); // ���� ������ �������� ���� ��ǥ�� ���� -> ���� ������ �ٶ�ôٸ� ���� ��ǥ�� ��ȯ��
			if (map[p.first][p.second] == 0) {
				canmove = true;
				int _nextdirt = nextdirt - 1; // ���� ����
				if (_nextdirt == -1) _nextdirt = 3;
				Robot(p.first, p.second, _nextdirt);
				break;
			}
			--nextdirt;
		}
		if (canmove == false) { // ����� ���̻� û�� �Ұ�
			int backy = robot_r + dy[(robot_d + 2) % 4];
			int backx = robot_c + dx[(robot_d + 2) % 4];
			if (map[backy][backx] == 2) { // ��������
				Robot(backy, backx, robot_d);
			}
			else if (map[backy][backx] == 1) { // �����Ұ���, ��������
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