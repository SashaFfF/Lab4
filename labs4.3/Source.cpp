//вариант 12
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int N;
	cout << "Please enter N:";
	cin >> N;
	double **arr = new double* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new double[N];
	}
	int** arr_result = new int* [N];
	for (int i = 0; i < N; i++) {
		arr_result[i] = new int[N];
	}
	cout << "arr[" << N << "][" << N << "]"<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand()/100.0;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr_result[i][j] = 0;
		}
	}
	cout << "arr_result [" << N << "][" << N << "]" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > arr[j][j]) {
				arr_result[i][j] = 1;
			}
			cout << arr_result[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] arr_result[i];
	}
	delete[] arr_result;
	for (int i = 0; i <N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}