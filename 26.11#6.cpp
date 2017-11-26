#include <iostream>

using namespace std;

int main()
{
    int i, n, j, nu, maxi = 0;
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];
    for(i = 0; i < n; i++) arr[i] = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j += i + 1) {
            arr[i + j] += 1;
        };
    };

    for(i = 0; i < n; i++) {
        if(arr[i] > maxi) {maxi = arr[i]; nu = i + 1;};
    };

    cout << endl;
    cout << "The maximum is: " << nu << ", it has " << maxi;
    delete arr;
    return 0;
}
