#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int to_channel;
int bbnum;
int button[10]; // 1이면 고장난 버튼
int ret = 987654321;
vector<int> v;

void Pick(int cnt, int value, int len) {
	if (cnt == len) {
		ret = min(ret, abs(to_channel - value) + len);
		return;
	}
	for (int i = 0; i < v.size(); ++i) {
		Pick(cnt + 1, value * 10 + v[i], len);
	}
}

int main() {
	cin >> to_channel >> bbnum;
	while (bbnum != 0) {
		int tmp;
		cin >> tmp;
		button[tmp] = 1;
		--bbnum;
	}
	for (int i = 0; i < 10; ++i) {
		if (button[i] == 0) {
			v.push_back(i);
		}
	}
	
	int to100 = 0;
	int hun = 100;
	
	if (to_channel > 100) {
		while (hun != to_channel) {
			++to100;
			++hun;
		}
	}
	else if (to_channel < 100) {
		while (hun != to_channel) {
			++to100;
			--hun;
		}
	}

	for (int i = 1; i < 8; ++i) {
		Pick(0, 0, i);
	}
	cout << min(ret, to100);
	return 0;
}
