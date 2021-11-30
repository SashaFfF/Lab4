#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int N, M, i, j;;
	cout << "Please enter N:";
	cin >> N;
	cout << "Please enter M:";
	cin >> M;
	int** arr = new int* [N];
	for (i = 0; i < N; i++) {
		arr[i] = new int[M];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr[i][j] = rand();
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	int x_result = 0;
	//проход по внутренней части матрицы 
	for (i = 1; i < N-1; i++) {
		for (j = 1; j < M-1; j++) {
			if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i + 1][j] &&
				arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i][j - 1] &&
				arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i - 1][j + 1] &&
				arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j + 1]) {
				x_result += 1;
			}
		}
	}
	//проход по первой строке матрицы (не включая угловые элементы)
	for (j = 1; j < M - 1; j++) {
		i = 0;
		if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] &&
			arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i][j + 1]) {
			x_result += 1;
		}
	}
	//проход по последнему столбцу матрицы (не включая угловые элементы) 
	for (i = 1; i < N - 1; i++) {
		j = M - 1;
		if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1] &&
			arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j]) {
			x_result += 1;
		}
	}
	//проход по последней строке матрицы (не включая угловые элементы)
	for (j = 1; j < M - 1; j++) {
		i = N-1;
		if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j - 1] && 
			arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i][j + 1]) {
			x_result += 1;
		}
	}
	//проход по первому столбцу матрицы (не включая угловые элементы)
	for (i = 1; i < N - 1; i++) {
		j = 0;
		if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1] && 
			arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j]) {
			x_result += 1;
		}
	}
	//просмотр угловых элементов 
	if (arr[0][0] < arr[1][0] && arr[0][0] < arr[1][1] && arr[0][0] < arr[0][1]) {
		x_result += 1;
	}
	if (arr[N-1][0] < arr[N-2][0] && arr[N-1][0] < arr[N - 2][1] && arr[N-1][0] < arr[N-1][1]) {
		x_result += 1;
	}
	if (arr[0][M - 1] < arr[0][M - 2] && arr[0][M - 1] < arr[1][M - 2] && arr[0][M - 1] < arr[1][M - 1]) {
		x_result += 1;
	}
	if (arr[N - 1][M - 1] < arr[N-2][M-1] && arr[N - 1][M - 1] < arr[N-2][M-2] && arr[N - 1][M - 1] < arr[N-1][M-2]) {
		x_result += 1;
	}
	cout << "x_result:" << x_result;
	for (i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}