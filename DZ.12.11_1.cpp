#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Enter digits, and their total number" << endl;
    int n; // длина мвссива
    //cin >> n; cout << endl;
    n = 5;
    int *arr = new int [n];    //Сам массив чисел
    int *prarr = new int[n];
    //int *prarr1 = new int[n];

    int k, sk, i, b, b1, check, nu;
    nu = 0;

    for (i = 0; i <= n; i++) {prarr[i] = 0;};

    for (i = 0; i <= n - 1 ; i++) {
        cin >> k; //вводится число массива
        //cout << k;

        //sk = sqrt(k); //корень из этого числа, для определения простоты
        //sk = sk / 1; //округление корня до целых
        int *arr1 = new int[k + 1];               // Создание массива с длинной корня из числа для проверки простоты числа
        arr1[0] = 1;   //т.к 0 и 1 - не являются простыми
        arr1[1] = 1;

        for (b = 2; b <= k; b++) {arr1[b] = 0;};           //Все элементы массива,начиная со 2го = 0
            for (b = 0; b <= k; b++) {    //Проверка на простоту
                if (arr1[b] == 1) {continue;} //если число составное, то пропускаем
                else {
                    for (b1 = b * 2; b1 <= k; b1 += b) {arr1[b1] = 1;}; //если оно простое, то ,начиная с этого числа, умноженного на 2, все числа с шагом в это число составные
                };
            };
            //for(b = 0; b <= k; b++) {cout << arr1[b];}; cout << endl; //вывод массива из 0й и 1ц
            check = 0;
            //cout << arr1[k] << endl;

            if(arr1[k] == 1) {   //если число простое
                prarr[i] = k;
                nu += 1;
            } else {
                for(b1 = 0; b1 <= n - 1; b1 ++) {
                    if(arr1[k] == prarr[b1]) {break;}
                    else {
                        check++;
                        //cout << check << endl;
                    };
                };
            };
                //cout << check << endl;
                if (check = n) {
                    //cout << k << endl;
                    prarr[i] = k;
                    nu++;
                }
    }; //The end of the main cickle

    for (b = 0; b <= nu; b++) {cout << prarr[b] << endl;};

    delete [] arr;
};

