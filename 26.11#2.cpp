#include <iostream>
#include <cstdlib>

using namespace std;

int** big_trench(int n, int** arr) {
    for(int i = 0; i < n; i++) {
        arr[i] = new int [n];
        for(int j = 0; j < n; j++) {
            arr[i][j] = abs(i - j);
        };
    };
    return arr;
}

int prt_trench(int n, int** arr) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        };
        cout << endl;
    };
}

int main()
{
    int n;
    cout << "Enter main massive number" << endl;
    cin >> n;
    int **Trench = new int* [n];
    prt_trench(n, big_trench(n, Trench));

    delete Trench;
    return 0;
}
