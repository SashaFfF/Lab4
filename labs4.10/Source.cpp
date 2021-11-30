#include <iostream>
using namespace std;


int main()
{
    int size, i, j;
    do {
        cout << "Please enter size:";
        cin >> size;
    } while (size % 2 == 0);
    int max_size = size + (size - 1);

    int** Magic_square = new  int* [max_size];
    for (int i = 0; i < max_size; i++) {
        Magic_square[i] = new int[max_size];
    }
    for (i = 0; i < max_size; i++) {
        for (j = 0; j < max_size; j++)
            Magic_square[i][j] = 0;
    }
    int k = 1;
    i = (max_size >> 1);
    j = 0;
    while (i < max_size) {
        int i1 = i;
        int j1 = j;
        int gr = size >> 1; //gr-расстояние от границы увеличенного массива
        while (j1 < j + (max_size >> 1) + 1) {
            Magic_square[i1][j1] = k;
            if (i1 > gr && j1 < gr) {
                Magic_square[i1][j1 + size] = k;
            }
            if (i1 > size + gr - 1 && j1 > gr) {
                Magic_square[i1 - size][j1] = k;
            }
            if (i1 < gr && j1 > gr) {
                Magic_square[i1 + size][j1] = k;
            }
            if (i1 > gr && j1 > size + gr - 1) {
                Magic_square[i1][j1 - size] = k;
            }
            --i1;
            ++j1;
            ++k;
        }
        ++i;
        ++j;
    }
    cout << endl << "Magic square: " << endl;
    for (i = (size - 1) >> 1; i <= max_size - (size >> 1) - 1; i++) {
        for (j = (size - 1) >> 1; j <= max_size - (size >> 1) - 1; j++) {
            cout << Magic_square[i][j] << "\t";
        }
       cout << endl;
    }

    for (int i = 0; i < max_size; ++i) {
        delete[] Magic_square[i];
    }
    delete[] Magic_square;

    return 0;
}