#include <iostream>
using namespace std;

int cnt = 0;
int n, r, c;
int ret;
void WorkSpace(int row, int col, int n) {
	if (row == r && col == c) {
		cout << cnt;
		return;
	}
	if (r >= row && r < row + n && c >= col && c < col + n) {
		WorkSpace(row, col, n / 2);
		WorkSpace(row, col + n / 2, n / 2);
		WorkSpace(row + n / 2, col, n / 2);
		WorkSpace(row + n / 2, col + n / 2, n / 2);
	}
	else {
		cnt += int(pow(n, 2));
	}
}

int main() {
	cin >> n >> r >> c;
	WorkSpace(0, 0, int(pow(2, n)));
	return 0;
}