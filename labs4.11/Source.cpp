#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int i, j, k, n;
	cout << "Please enter n:";
	cin >> n;
	int ***arr = new int**[n];
	for (i = 0; i < n; i++) {
		arr[i] = new int* [n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			arr[i][j] = new int[n];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				arr[i][j][k] = rand();
				cout << arr[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	int sum = 0;
	int max_sum = sum;
	//нахождение суммы элементов первой диагонали 
	for (i = j = k = 0; i < n, j < n, k < n; i++, j++, k++) {
		sum += arr[i][j][k];
	}
	if (sum > max_sum) {
		max_sum = sum;
	}
	sum = 0;
	//нахождение суммы элементов второй диагонали 
	for (i = j = k = n - 1; i >= 0, j >= 0, k >= 0; i--, j--, k--) {
		sum += arr[i][j][k];
	}
	if (sum > max_sum) {
		max_sum = sum;
	}
	cout << "max_sum:" << max_sum;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			delete[] arr[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete [] arr;
	return 0;
}