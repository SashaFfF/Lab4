#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int N;
	cout <<"Please enter N:";
	cin >> N;
	int *arr = new  int[N];
	
	for (int i = 0; i < N; i++) {
		arr[i] = rand()%10;
		cout << arr[i] << " ";
	}

	int min = arr[0];
	int min_Index = 0;
	int max = arr[1];
	int max_Index = 1;
	//нахождение минимального и максимального элементов и их индексов 
	for (int i = 0; i < N; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_Index = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			min_Index = i;
		}
	}
	cout << endl;
	//замена нулями всех элементов массива, стоящих между минимальным и максимальным элементами(не включая их)
	if (min_Index < max_Index) {
		for (int i = min_Index + 1; i < max_Index; i++) {
			arr[i] = 0;
		}
		min = min_Index;
		max = max_Index;
	}
	else if (min_Index > max_Index) {
		for (int i = max_Index + 1; i < min_Index; i++) {
			arr[i] = 0;
		}
		min = max_Index;
		max = min_Index;
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int d = abs(max_Index - min_Index);//расстояние между минимальным и максимальныим элементами 
	int* arr_D = new int[N - d + 1];//инициализация массива с удаленными элементами 
	if (d-1 > N / 2) {
		int j = 0;
		for (int i = 0; i <= min; i++) {
			arr_D[i] = arr[i];
			j++;
		}
		for (int i = max; i < N; i++) {
			arr_D[j] = arr[i];
			j++;
		}
		for (int i = 0; i < N - d + 1; i++) {
			cout << arr_D[i] << " ";
		}
	}

	delete[] arr_D;
	delete[] arr;
	return 0;
}
