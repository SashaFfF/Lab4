#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int i, j, n, m;
	cout << "Please enter n:";
	cin >> n;
	cout << "Please enter m:";
	cin >> m;

	char **arr= new char* [n];
	for (i = 0; i < n; i++) {
		arr[i] = new char[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (rand() % 2 == 1) {
				arr[i][j] = '.';
			}
			else arr[i][j] = '*';
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] == '.') {
				int number = 0;
				//проверка условия существования элементов с данными координатами и подсчет элементов с символом, означающим бомбу
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == '*') {
					number++;
				}
				if (j - 1 >= 0 && arr[i][j - 1] == '*') {
					number++;
				}
				if (i + 1 < n && j - 1 >= 0  && arr[i + 1][j - 1] == '*') {
					number++;
				}
				if (i + 1 < n && arr[i + 1][j] == '*') {
					number++;
				}
				if (i + 1 < n && j + 1 < m && arr[i + 1][j + 1] == '*') {
					number++;
				}
				if (j + 1 < m && arr[i][j + 1] == '*') {
					number++;
				}
				if (i - 1 >= 0 && j + 1 < m && arr[i - 1][j + 1] == '*') {
					number++;
				}
				if (i - 1 >= 0 && arr[i - 1][j]=='*') {
					number++;
				}
				arr[i][j] = number + '0';
			}
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	} 
	
	for (i = 0; i < n; i++) {
		delete [] arr[i];
	}
	delete[] arr;
	return 0;
}
