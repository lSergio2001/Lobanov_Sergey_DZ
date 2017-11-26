#include <iostream>

using namespace std;

int strange_sum(int n, int* arr) {
    if(n == 1) {return arr[0];}
    else {
        int *arr1 = new int [n/2];
        for(int i = 0; i < n / 2; i++) {
            arr1[i] = arr[i];
        };
        int *arr2 = new int [n - n/2];
        for(int i = 0; i < n - n / 2; i++) {
            arr2[i] = arr[i + n / 2];
        };
        return strange_sum(n / 2, arr1) + strange_sum(n - n / 2, arr2);
    };
}


int main()
{
    int k, n;
    cout << "Enter the massive number: " << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter a massive: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> k;
        arr[i] = k;
    };



    cout << "The summ of your array is:  " << strange_sum(n, arr) << endl;

    delete arr;
    return 0;
}
