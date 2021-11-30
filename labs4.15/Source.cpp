#include <iostream>

using namespace std;
int main() {
	int n;
	cout << "Please enter n:";
	cin >> n;
	int **arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new  int[n];
	}
	int x = 0;
	int num = 1;
	//заполнение таблицы по описанному в задании алгоритму 
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < x; i++) {
			arr[i][j] = num;
			num++;
		}
		for (int k = j; k >= 0; k--) {
			arr[x][k] = num;
			num++;
		}
		x++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	int number;
	//проверка на наличие в таблице введенного числа 
	do {
		cout << "Please enter number:";
		cin >> number;
	} while (number > n * n);
	//вывод строки и столбца, в которых находится введенное число 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == number) {
				cout << "column:" << endl;
				for (int k = 0;  k < n; k++) {
					cout << arr[k][j] << " ";
				}
				cout << endl << "row:" << endl;
				for (int k = 0; k < n; k++) {
					cout << arr[i][k] << " ";
				}


			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete [] arr;
	return 0;
}
