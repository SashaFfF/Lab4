#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int i, j, N, M;
	cout << "Please enter N:";
	cin >> N;
	cout << "Please enter M:";
	cin >> M;
	double** arr = new double* [N];
	for (i = 0; i < N; i++) {
		arr[i] = new double[M];
	}
	double** arr_result = new double* [N];
	for (i = 0; i < N; i++) {
		arr_result[i] = new double[M];
	}
	cout << "original matrix"<< endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr[i][j] = rand() / 100.0;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr_result[i][j] = 0.;
		}
	}
	//проход по внутренней части матрицы 
	for (i = 1; i < N - 1; i++) {
		for (j = 1; j < M - 1; j++) {
			arr_result[i][j] = (arr[i - 1][j] + arr[i + 1][j] + arr[i - 1][j - 1] + arr[i][j - 1] + 
				arr[i + 1][j - 1] + arr[i - 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 1]) / 8.;
		}
	}
	//проход по первой строке матрицы (не включая угловые элементы)
	for (j = 1; j < M - 1; j++) {
		i = 0;
		arr_result[i][j] = (arr[i][j - 1] + arr[i][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1]) / 5.;
	}
	//проход по последнему столбцу матрицы (не включая угловые элементы)
	for (i = 1; i < N - 1; i++) {
		j = M - 1;
		arr_result[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j]) / 5.;
	}
	//проход по последней строке матрицы (не включая угловые элементы)
	for (j = 1; j < M - 1; j++) {
		i = N - 1;
		arr_result[i][j] = (arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +  arr[i][j + 1]) / 5.;
	}
	//проход по первому столбцу матрицы (не включая угловые элементы)
	for (i = 1; i < N - 1; i++) {
		j = 0;
		arr_result[i][j] = (arr[i - 1][j] + arr[i - 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j]) / 5.;
	}
	//просмотр угловых элементов 
	arr_result[0][0] = (arr[1][0] + arr[1][1] + arr[0][1]) / 3.;
	arr_result[N - 1][0] = (arr[N - 2][0] + arr[N - 2][1] + arr[N - 1][1]) / 3.;
	arr_result[0][M - 1] = (arr[0][M - 2] + arr[1][M - 2] + arr[1][M - 1]) / 3.;
	arr_result[N - 1][M - 1] = (arr[N - 2][M - 1] + arr[N - 2][M - 2] + arr[N - 1][M - 2]) / 3.;
	cout << "resulting matrix" << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << arr_result[i][j] << "\t";
		}
		cout << endl;
	}

	for (i = 0; i < N; i++) {
		delete[] arr_result[i];
	}
	delete[] arr_result;
	for (i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}