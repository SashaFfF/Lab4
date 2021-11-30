//вариант 12
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	const int k = 10;
	int arr[k];
	int i;
	for (i = 0; i < k; i++) {
		arr[i] = rand();
		cout << arr[i] << " ";
	}
	cout << endl;
	int x = 0;
	for (i = 0; i < k; i++) {
		if (i < k - 1) {
			if (arr[i] > arr[i + 1]) {
				x++;
			}
		}
	}
	cout << "x:" << x;
	return 0;
}