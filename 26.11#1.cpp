/* Ќапишите программу, котора€ удал€ет из массива все
простые числа встречающиес€ больше одного раза. */

#include <iostream>

using namespace std;

bool prime(int x){
    if(x < 0) return 0;
    switch(x) {
    case 0: return 0; break;
    case 1: return 0; break;
    case 2: return 1; break;
    case 3: return 1; break;
    case 4: return 0; break;
    };

for(long i = 5; i <= x / 2; i++){
if(x % i == 0) return 0;
else return 1;
};
}

void delete_annoying_primes(int* arr, int n){
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int size_arr = n,
        size_arr1 = 0,
        size_arr2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if((arr[i] == arr[j]) && (prime(arr[i])) == 1){
                arr1[size_arr1] = arr[i];
                size_arr1++;
            };
        };
    };
    for(int i = 0; i < size_arr; i++){
        bool hellish_arr2 = 0;
        for(int j = 0; j < size_arr1; ++j){
        if(arr[i] == arr1[j]) {
        hellish_arr2 = 1;
        };
        };
        if(hellish_arr2 != 1){
        arr2[size_arr2] = arr[i];
        size_arr2++;
        };
    };
    for (int i = 0; i < size_arr2; i++){
        cout << arr2[i] << " ";
    };
}
int main(){
int n;
cin >> n;
int* A = new int[n];
for(int i = 0; i < n; ++i){
cout << "Enter Arr[" << i + 1 << "]: ";
cin >> A[i];
}
delete_annoying_primes(A, n);
return 0;
}
