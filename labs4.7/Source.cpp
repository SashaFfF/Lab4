#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main() {
	string number;
	cout << "Please enter number:";
	cin >> number;
	int length = number.length();
	cout << "length:" << length << endl;
	unsigned long long n;
	istringstream(number) >> n;//перевод из строчного типа в целочисленный
	int* arr = new int[length];
	int j = 0;
	do {
		int i = n % 10;
		arr[j] = i;
		cout << arr[j] << " ";
		n = n / 10;
		j++;
	} while (n / 10 != 0);
	arr[length - 1] = n;
	cout << arr[length - 1] << endl;
	int i;
	//проверка ввода i
	do {
		cout << "Please enter i:";
		cin >> i;
	} while (i < 0 || i >= length);
	cout << "arr[" << i << "]:" << arr[i];
	delete[] arr;
	return 0;
}