#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Enter digits, and their total number" << endl;
    int n; // ����� �������
    //cin >> n; cout << endl;
    n = 5;
    int *arr = new int [n];    //��� ������ �����
    int *prarr = new int[n];
    //int *prarr1 = new int[n];

    int k, sk, i, b, b1, check, nu;
    nu = 0;

    for (i = 0; i <= n; i++) {prarr[i] = 0;};

    for (i = 0; i <= n - 1 ; i++) {
        cin >> k; //�������� ����� �������
        //cout << k;

        //sk = sqrt(k); //������ �� ����� �����, ��� ����������� ��������
        //sk = sk / 1; //���������� ����� �� �����
        int *arr1 = new int[k + 1];               // �������� ������� � ������� ����� �� ����� ��� �������� �������� �����
        arr1[0] = 1;   //�.� 0 � 1 - �� �������� ��������
        arr1[1] = 1;

        for (b = 2; b <= k; b++) {arr1[b] = 0;};           //��� �������� �������,������� �� 2�� = 0
            for (b = 0; b <= k; b++) {    //�������� �� ��������
                if (arr1[b] == 1) {continue;} //���� ����� ���������, �� ����������
                else {
                    for (b1 = b * 2; b1 <= k; b1 += b) {arr1[b1] = 1;}; //���� ��� �������, �� ,������� � ����� �����, ����������� �� 2, ��� ����� � ����� � ��� ����� ���������
                };
            };
            //for(b = 0; b <= k; b++) {cout << arr1[b];}; cout << endl; //����� ������� �� 0� � 1�
            check = 0;
            //cout << arr1[k] << endl;

            if(arr1[k] == 1) {   //���� ����� �������
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

