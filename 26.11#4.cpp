/* Напишите программу, которая выводит все натуральные числа-палиндромы
длины n, делящиеся на 9, в порядке возрастания. */

#include <iostream>
#include <math.h>

using namespace std;

bool is_palindrom(int n) {
    int a, b = 0;
    for (a = n; a > 0; a /= 10)
        b = b * 10 + a % 10;
    return b == n;
}
void prt_palindrom(int n){
if (n == 1){
cout << 9;
};
if (n == 2){
cout << 99;
};
int A = 0;
if (n % 2 == 0)
A = pow(10, n - 1) + 1 + 88 * (pow(10, n / 2 - 1));
else
A = pow(10, n - 1) + 1 + 7 * (pow(10, n / 2));
int M = pow(10, n);
for (A; A < M; A += 9) {
if (is_palindrom(A) == true) {
cout << A << endl;
}
}
}
int main(){
int n;
cout << "Enter the length of the palindromes : ";
cin >> n;
prt_palindrom(n);
return 0;
}
