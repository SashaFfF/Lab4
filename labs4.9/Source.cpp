#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int i, j, l, n, m, k;
	cout << "Please enter n:";
	cin >> n;
	cout << "Please enter m:";
	cin >> m;
	cout << "Please enter k:";
	cin >> k;

	int** arr_A = new int* [n];
	for (i = 0; i < n; i++) {
		arr_A[i] = new int[m];
	}
	int** arr_B = new int* [m];
	for (i = 0; i < m; i++) {
		arr_B[i] = new int[k];
	}
	int** arr_result = new int* [n];
	for (i = 0; i < n; i++) {
		arr_result[i] = new int[k];
	}

	cout << "arr_A" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			arr_A[i][j] = rand()%10;
			cout << arr_A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "arr_B"<< endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++) {
			arr_B[i][j] = rand()%10;
			cout << arr_B[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "arr_result" << endl;
	//умножение матриц А и В, заполнение результирующей матрицы 
	for (i = 0; i < n; i++) {
		for (l = 0; l < k; l++) {
			int x_result = 0;
			for (j = 0; j < m; j++) {
				x_result += arr_A[i][j] * arr_B[j][l];
			}
			arr_result[i][l] = x_result;
			cout << arr_result[i][l] << "\t";
		}
		cout << endl;
	}

	for (i = 0; i < n; i++) {
		delete[] arr_result[i];
	}
	delete[] arr_result;
	for (i = 0; i < n; i++) {
		delete [] arr_A[i];
	}
	delete [] arr_A;
	for (i = 0; i < m; i++) {
		delete [] arr_B[i];
	}
	delete [] arr_B;
	return 0;
}
