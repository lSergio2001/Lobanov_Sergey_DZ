/*Напишите программу для работы с оценками за сессию студентов.
В программе должна присутствовать структура хранящая ФИО, оценки
за 6 экзаменов для каждого ученика и умеющая (соответствующими методами)
вычислять средний балл студента, наличие стипендии(стипендия начисляется
закрывшим сессию без троек),  задолженностей (сессия считается закрытой без долгов, если все оценки выше 2)
в программе должны быть функции для работы с массивом студентов находящие средний балл(всех без двух лучших и двух худших),
количества стипендиатов, должников и отчисленных(более двух долгов)
*/
#include <iostream>

using namespace std;

struct Student {
public:
char familia[127];
char imya[127];
char otchestvo[127];
int ocenka[6];
double sredniy_ball() {
double res = 0;
for (int i = 0; i < 6; i++) {
res = res + ocenka[i];
}
res = res / 6;
return res;
}
bool stependiat() {
bool res = 1;
for (int i = 0; i < 6; i++) {
if (ocenka[i] <= 3) res = 0;
}
return res;
}
bool otchislen() {
bool res = 0;
int schet_dolgov = 0;
for (int i = 0; i < 6; i++) {
if (ocenka[i] <= 2) schet_dolgov++;
}
if (schet_dolgov >= 2) res = 1;
return res;
}
}a[10000];

double naiti_sredniy_ball(int n, Student ar[]){
for(int i = 0; i < n - 1; i++){
for(int j = i + 1; j < n; j++){
if(a[i].sredniy_ball() > a[j].sredniy_ball()) swap(a[i], a[j]);
}
}
double resultat = 0;
for(int i = 2; i < n - 2; i++){
resultat = resultat + a[i].sredniy_ball();
}
resultat = resultat/(n-4);
return resultat;
}

int naiti_kolichestvo_otchislennih(int n, Student ar[]){
int resultat = 0;
for(int i = 0; i < n; i++){
if(a[i].otchislen() == 1) resultat++;
}
return resultat;
}

int naiti_kolichestvo_stependiatov(int n, Student ar[]){
int resultat = 0;
for(int i = 0; i < n; i++){
if(a[i].stependiat() == 1) resultat++;
}
return resultat;
}

int naiti_kolichestvo_dolgnikov(int n, Student ar[]){
int resultat = 0;
for(int i = 0; i < n; i++){
bool dolgnik = 0;
for(int j = 0; j < 6; j++){
if(a[i].ocenka[j] <= 2) {
dolgnik = 1;
}
}
if(dolgnik == 1){
resultat++;
}
}
return resultat;
}

int main() {
return 0;
}
