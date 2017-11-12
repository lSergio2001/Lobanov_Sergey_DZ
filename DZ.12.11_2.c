/*Ќапишите программу, котора€ подсчитывает, сколько раз в строке встретилс€
символ СwТ*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int x, i, k;
    char str[2000];
    cout << 'Enter the string, please:' << endl;
    gets(str);
    x = strlen(str);
    //cout << string[1];
    //cout << x;
    k = 0;
   for(i = 0; i < x; i++) {
        if(str[i] == 'w') {k = k + 1;}
   };
    cout  << k << endl;
    return 0;
}
