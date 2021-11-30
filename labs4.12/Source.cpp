#include <iostream>
#include <cstdlib>
#include <ctime>

//функци€, провер€юща€, включает ли массив переданный элемент 
bool includes(int* arr, int n, int element) {
	bool is_include = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == element) {
			is_include = true;
		}
	}
	return is_include;
}

using namespace std;
int main() {
	srand(time(0));
	int n;
	cout << "Please enter n:";
	cin >> n;
	int *arr = new int[n];
	cout << "arr" << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl; 
	//промежуточный массив дл€ сохранени€ уникальных элементов исходного массива 
	int* arr_unique = new int[n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (!includes(arr_unique, n, arr[i])) {
			arr_unique[j] = arr[i];
			j++;
		}
	}
	cout << "arr_result" << endl;
	int* arr_result = new int[j];
	for (int k = 0; k < j; k++) {
		arr_result[k] = arr_unique[k];
		cout << arr_result[k] << " ";
	}
	cout << endl << "array size:" << j;

	delete[] arr_result;
	delete[] arr_unique;
	delete[] arr;
	return 0;
}