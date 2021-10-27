/*
각 방향을 그리는 코드가 중복이 되어서 따로 함수를 만듬
map을 매개변수로 넘김으로써 한 경우가 끝나고 다시 원 상태로 복구해줘야 하는 코드를 따로 작성안해도 됨
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// -1 : CCTV가 감시하는 구역
vector<pair<int, int>> idxarr;

int Getzero(vector<vector<int>> map) {
	int sum = 0;
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j] == 0) ++sum;
		}
	}
	return sum;
}

vector<vector<int>> Draw12(vector<vector<int>> map, int row, int col) {
	while (row >= 0) {
		if (map[row][col] == 6) {
			break;
		}
		else if (map[row][col] == 0) {
			map[row][col] = -1;
		}
		--row;
	}
	return map;
}

vector<vector<int>> Draw3(vector<vector<int>> map, int row, int col) {
	while (col < map[row].size()) {
		if (map[row][col] == 6) {
			break;
		}
		else if (map[row][col] == 0) {
			map[row][col] = -1;
		}
		++col;
	}
	return map;
}

vector<vector<int>> Draw6(vector<vector<int>> map, int row, int col) {
	while (row < map.size()) {
		if (map[row][col] == 6) {
			break;
		}
		else if (map[row][col] == 0) {
			map[row][col] = -1;
		}
		++row;
	}
	return map;
}

vector<vector<int>> Draw9(vector<vector<int>> map, int row, int col) {
	while (col >= 0) {
		if (map[row][col] == 6) {
			break;
		}
		else if (map[row][col] == 0) {
			map[row][col] = -1;
		}
		--col;
	}
	return map;
}

vector<vector<int>> CCTV_1(vector<vector<int>> map, int status, int idx) {
	pair<int, int> p = idxarr[idx];
	if (status == 1) { // 12시 방향
		int row = p.first - 1;
		map = Draw12(map, row, p.second);
	}
	else if (status == 2) { // 3시 방향
		int col = p.second + 1;
		map = Draw3(map, p.first, col);
	}
	else if (status == 3) { // 6시 방향
		int row = p.first + 1;
		map = Draw6(map, row, p.second);
	}
	else if (status == 4) { // 9시 방향
		int col = p.second - 1;
		map = Draw9(map, p.first, col);
	}
	return map;
}

vector<vector<int>> CCTV_2(vector<vector<int>> map, int status, int idx) {
	pair<int, int> p = idxarr[idx];
	if (status == 1) { // 가로
		int col1 = p.second + 1; // 3시
		int col2 = p.second - 1; // 9시
		map = Draw3(map, p.first, col1);
		map = Draw9(map, p.first, col2);
	}

	else if (status == 2) { // 세로
		int row1 = p.first + 1; // 6시
		int row2 = p.first - 1; // 12시
		map = Draw6(map, row1, p.second);
		map = Draw12(map, row2, p.second);
	}
	return map;
}

vector<vector<int>> CCTV_3(vector<vector<int>> map, int status, int idx) {
	pair<int, int> p = idxarr[idx];
	if (status == 1) { // 12시 3시
		int row1 = p.first - 1;
		int col1 = p.second + 1;
		map = Draw12(map, row1, p.second);
		map = Draw3(map, p.first, col1);
	}
	else if (status == 2) { // 3시 6시
		int col3 = p.second + 1;
		int row6 = p.first + 1;
		map = Draw3(map, p.first, col3);
		map = Draw6(map, row6, p.second);
	}
	else if (status == 3) { // 6시 9시
		int row6 = p.first + 1;
		int col9 = p.second - 1;
		map = Draw6(map, row6, p.second);
		map = Draw9(map, p.first, col9);
	}
	else if (status == 4) { // 9시 12시
		int col9 = p.second - 1;
		int row12 = p.first - 1;
		map = Draw9(map, p.first, col9);
		map = Draw12(map, row12, p.second);
	}
	return map;
}

vector<vector<int>> CCTV_4(vector<vector<int>> map, int status, int idx) {
	pair<int, int> p = idxarr[idx];
	if (status == 1) { // 9 12 3
		int col9 = p.second - 1;
		int col3 = p.second + 1;
		int row12 = p.first - 1;
		map = Draw9(map, p.first, col9);
		map = Draw12(map, row12, p.second);
		map = Draw3(map, p.first, col3);
	}
	else if (status == 2) { // 12 3 6
		int row6 = p.first + 1;
		int row12 = p.first - 1;
		int col3 = p.second + 1;
		map = Draw12(map, row12, p.second);
		map = Draw3(map, p.first, col3);
		map = Draw6(map, row6, p.second);
	}
	else if (status == 3) { // 3 6 9
		int col3 = p.second + 1;
		int row6 = p.first + 1;
		int col9 = p.second - 1;
		map = Draw3(map, p.first, col3);
		map = Draw6(map, row6, p.second);
		map = Draw9(map, p.first, col9);
	}
	else if (status == 4) { // 6 9 12
		int row6 = p.first + 1;
		int col9 = p.second - 1;
		int row12 = p.first - 1;
		map = Draw6(map, row6, p.second);
		map = Draw9(map, p.first, col9);
		map = Draw12(map, row12, p.second);
	}
	return map;
}

vector<vector<int>> CCTV_5(vector<vector<int>> map,int idx) {
	pair<int, int> p = idxarr[idx];
	int col3 = p.second + 1;
	int row6 = p.first + 1;
	int col9 = p.second - 1;
	int row12 = p.first - 1;

	map = Draw3(map, p.first, col3);
	map = Draw6(map, row6, p.second);
	map = Draw9(map, p.first, col9);
	map = Draw12(map, row12, p.second);

	return map;

}

int Workspace(vector<vector<int>> map, int idx) {
	if (idx == idxarr.size()) {
		return Getzero(map);
	}

	int ret = 987654321;
	if (map[idxarr[idx].first][idxarr[idx].second] == 1) {
		for (int i = 1; i <= 4; ++i) {
			ret = min(ret, Workspace(CCTV_1(map, i, idx), idx + 1));
		}
	}
	else if (map[idxarr[idx].first][idxarr[idx].second] == 2) {
		for (int i = 1; i <= 2; ++i) {
			ret = min(ret, Workspace(CCTV_2(map, i, idx), idx + 1));
		}
	}
	else if (map[idxarr[idx].first][idxarr[idx].second] == 3) {
		for (int i = 1; i <= 4; ++i) {
			ret = min(ret, Workspace(CCTV_3(map, i, idx), idx + 1));
		}
	}
	else if (map[idxarr[idx].first][idxarr[idx].second] == 4) {
		for (int i = 1; i <= 4; ++i) {
			ret = min(ret, Workspace(CCTV_4(map, i, idx), idx + 1));
		}
	}
	else if (map[idxarr[idx].first][idxarr[idx].second] == 5) {
			ret = min(ret, Workspace(CCTV_5(map, idx), idx + 1));
	}
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				idxarr.push_back(make_pair(i, j));
			}
		}
	}

	cout << Workspace(map, 0) << '\n';
	return 0;
}