#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void swap(string* a, string* b) {
	string tmp = *a;
	*a = *b;
	*b = tmp;
}

void QuickSort(string* arr, int left, int right) {
	int pivot = left;
	int low = left + 1;
	int high = right;
	if (left <= right) {
		while (low <= high) {
			//                   ���ڼ��� �� ������ ���� ��                                 ���̰� �������� ����������      ��ȣ�� ������ ���� �ܾ��� ��찡 ������� ����
			while (low <= high && arr[low].length() < arr[pivot].length() || low <= high && arr[low].length() == arr[pivot].length() && arr[low] <= arr[pivot]) low++;
			while (low <= high && arr[high].length() > arr[pivot].length() || low <= high && arr[high].length() == arr[pivot].length() && arr[high] >= arr[pivot]) high--;
			if (low < high) swap(&arr[low], &arr[high]);
		}
		swap(&arr[high], &arr[pivot]);
		QuickSort(arr, left, high - 1);
		QuickSort(arr, high + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	string* s = new string[n];
	for (int i = 0; i < n; i++) cin >> s[i];
	cout << endl;
	QuickSort(s, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i + 1]) continue; // ���� �ܾ ���� �ܾ�� ������ �н�
		else cout << s[i] << endl;
	}

	return 0;
}
