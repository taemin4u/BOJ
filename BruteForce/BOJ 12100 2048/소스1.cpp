#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<vector<bool>> canmerge(21, vector<bool>(21, true));

void Totrue() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (canmerge[i][j] == false) {
				canmerge[i][j] = true;
			}
		}
	}
}

int Findmax(vector<vector<int>> map) {
	int ret = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret = max(ret, map[i][j]);
		}
	}
	return ret;
}
void Print(vector<vector<int>> map) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
vector<vector<int>> Left(vector<vector<int>> map) {
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (map[i][j] == 0) continue;
			int cnt = j;
			while (cnt != 0) {
				if (map[i][cnt - 1] == 0) { // 왼쪽이 0이면 옮기기 가능
					swap(map[i][cnt], map[i][cnt - 1]);
				}
				else {
					if (map[i][cnt] == map[i][cnt - 1] && canmerge[i][cnt] == true && canmerge[i][cnt -1] == true) {
						map[i][cnt - 1] *= 2;
						canmerge[i][cnt - 1] = false;
						map[i][cnt] = 0;
					}

					else {
						break;
					}
				}
				--cnt;
			}
		}
	}
	Totrue();
	return map;
}

vector<vector<int>>  Right(vector<vector<int>> map) {
	for (int i = 0; i < n; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			if (map[i][j] == 0) continue;
			for (int k = j + 1; k < n; ++k) {
				if (map[i][k] == 0) {
					swap(map[i][k - 1], map[i][k]);
				}
				else if (map[i][k] == map[i][k - 1] && canmerge[i][k] == true && canmerge[i][k - 1] == true) {
					map[i][k] *= 2;
					canmerge[i][k] = false;
					map[i][k - 1] = 0;
				}
				else
					break;
			}
		}
	}
	Totrue();
	return map;
}


vector<vector<int>> Up(vector<vector<int>> map) {
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (map[j][i] == 0) continue;
			for (int k = j - 1; k >= 0; --k) {
				if (map[k][i] == 0) {
					swap(map[k][i], map[k + 1][i]);
				}
				else if (map[k][i] == map[k + 1][i] && canmerge[k][i] == true && canmerge[k + 1][i] == true) {
					map[k][i] *= 2;
					canmerge[k][i] = false;
					map[k + 1][i] = 0;
				}
				else
					break;
			}
		}
	}
	Totrue();
	return map;
}

vector<vector<int>> Down(vector<vector<int>> map) {
	for (int i = 0; i < n; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			if (map[j][i] == 0) continue;
			for (int k = j + 1; k < n; ++k) {
				if (map[k][i] == 0) {
					swap(map[k][i], map[k - 1][i]);
				}
				else if (map[k][i] == map[k - 1][i] && canmerge[k][i] == true && canmerge[k - 1][i] == true) {
					map[k][i] *= 2;
					canmerge[k][i] = false;
					map[k - 1][i] = 0;
				}
				else
					break;
			}
		}
	}
	Totrue();
	return map;
}


int Getmax(int cnt, vector<vector<int>> map) {
	if (cnt == 5) {
		return Findmax(map);
	}
	int ret = -1;
	ret = max(ret,Getmax(cnt + 1, Left(map)));
	ret = max(ret,Getmax(cnt + 1, Right(map)));
	ret = max(ret, Getmax(cnt + 1, Up(map)));
	ret = max(ret, Getmax(cnt + 1, Down(map)));
	return ret;
}

int main() {
	cin >> n;
	vector<vector<int>> map(21, vector<int>(21));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	if (n == 1) {
		cout << map[0][0];
	}
	else {
		cout << Getmax(0, map);
	}
	
	return 0;

}