/*Ќапишите функции min, max, avg, med, процедуру swap принимающие в себ€ три вещественных аргумента
и программу с примером из использовани€. min - находит минимальное из трех значений, max - максимальное,
avg - среднее арифметическое, med  - медианное (гуглим, что это такое). swap - переставл€ет значени€ по
кругу ( первое во второе, второе в третье, третье в первое).
*/
#include <iostream>

using namespace std;

double min(double A[3])
{
    double a,b,c,m;
    a=A[0] - A[1];
    if (a<=0) {
        m=A[0];
        b=m - A[2];
        if (b>=0)
            m=A[2];
        else m=A[0];
    } else {
    c=A[0] - A[2];
    if (c>=0) m=A[2];
    else m=A[0];

    };
    return m;
}

double max(double A[3])
{
    double a,b,c,m;
    a=A[0] - A[1];
    if (a>=0) {
        m=A[0];
        b=m - A[2];
        if (b<=0)
            m=A[2];
        else m=A[0];
    } else {
    c=A[0] - A[2];
    if (c<=0) m=A[2];
    else m=A[0];
    }
    return m;
}

double avg(double A[3]){
double a=A[0] + A[1] + A[2];
return a/=3;
}

double med(double A[3])
{
    double a,b,c,m;
    a=A[0] - A[1];
    if (a<=0) {
        b=A[1] - A[2];
        if (b>=0)
            m=A[2];
        else m=A[1];
    } else {
    c=A[0] - A[2];
    if (c>=0) m=A[2];
    else m=A[0];

    };
    return m;
}

void swap(double A[3])
{
    double a;
    a=A[0];
    A[0]=A[2];
    A[2]=A[1];
    A[1]=a;
    cout << A[0] << A[1] << A[2];
}

int main(){

    double a,b,c,d,e;
    double arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    cout << arr[0] << arr[1] << arr[2] << "  ";
    a=min(arr);
    cout << a << "  ";
    b=max(arr);
    cout << b << "  ";
    c=avg(arr);
    cout << c << "  ";
    d=med(arr);
    cout << d << "  ";
    swap(arr);
    return 0;
}
