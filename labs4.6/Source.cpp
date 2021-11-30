#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int i, j, k, n, N, M;
	cout << "Please enter N:";
	cin >> N;
	cout << "Please enter M:";
	cin >> M;
	int** arr_A = new int* [N];
	for (i = 0; i < N; i++) {
		arr_A[i] = new int[M];
	}
	int** arr_B = new int* [N];
	for (i = 0; i < N; i++) {
		arr_B[i] = new int[M];
	}
	cout << "arr_A" << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr_A[i][j] = rand()%10;
			cout << arr_A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "arr_B" << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int max = arr_A[1][1];
			for (k = 1; k <= i; k++) {
				for (n = 1; n <= j; n++) {
					if (arr_A[k][n] > max) {
						max = arr_A[k][n];
					}
				}
			}
			if (i == 0 || j == 0) {
				arr_B[i][j] = arr_A[i][j];
			}
			else arr_B[i][j] = max;
			cout << arr_B[i][j] << "\t";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++) {
		delete[] arr_B[i];
	}
	delete[] arr_B;
	for (i = 0; i < N; i++) {
		delete[] arr_A[i];
	}
	delete[] arr_A;
	return 0;
}