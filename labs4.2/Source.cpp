//вариант 12
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
srand(time(0));
const int N = 4;
const int M = 5;
int arr[N][M];
cout << "arr[N][M]" << endl;
for (int n = 0; n < N; n++) {
	for (int m = 0; m < M; m++) {
		arr[n][m] = rand();
		cout << arr[n][m] << "\t";
	}
	cout << endl;
}
int min_value[M];
cout << "min_value" << endl;
for (int m = 0; m < M; m++) { 
	int min=arr[0][m];
	for (int n = 1; n < N; n++) {
		if (arr[n][m] < min) {
			min = arr[n][m];
		}
	}
	min_value[m] = min;
	cout << min_value[m] << "\t";
}
	return 0;
}