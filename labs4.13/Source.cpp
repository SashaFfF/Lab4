#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int N;
	cout << "Please enter N:";
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand()%10;
		cout << arr[i] << " ";
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	//количество розеток
	int sum_result = sum - N;
	cout << "sum_result:" << sum_result;
	delete[] arr;
	return 0;
}