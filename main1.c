/*�������� ��������� ��� ������ � ������ �������� ��������������
���������. � ��������� ������ ��������������: ��������� ��������
���, �����, ����� � �������(� ������� ���������������� ������)
���������� �� ���� ���� ������. 3 ������� ������������ �������
���, ������� � ���� ������ ����� ����� ������ */

#include <iostream>

using namespace std;

struct calendar{
int day, month, year;
calendar (int a, int b, int c):
day(a), month(b), year(c){}
int Date(){
int x, w, z, d;
x = ( 14 - month ) / 12;
w = year - x;
z = month + 12 * x - 2;
d = (7000 + ( day + w + w / 4 - w / 100 + w / 400 + (31 * z) / 12 )) % 7;
return d;
}
};
int d1, d2, m1, m2, y1, y2;
int Years(int d1, int m1, int y1, int d2, int m2, int y2){
if (y1 < y2){
int y = y1, u = m1, h = d1;
y1 = y2;
m1 = m2;
d1 = d2;
y2 = y;
m2 = u;
d2 = h;
}
int y = 0;
if (y1 != y2){
if (m1 > m2)
y = y1 - y2;
if (m1 == m2){
if (d1 >= d2)
y = y1 - y2;
else
y = y1 - y2 - 1;
}
if (m1 < m2)
y = y1 - y2 - 1;
} else {
y = 0;
}
return y;
}
int Month(int d1, int m1, int y1, int d2, int m2, int y2){
if (y1 < y2){
int y = y1, u = m1, h = d1;
y1 = y2;
m1 = m2;
d1 = d2;
y2 = y;
m2 = u;
d2 = h;
}
int z=0;
if (y1 == y2){
if (m1 > m2){
if (d1 >= d2)
z = m1 - m2;
else
z = m1 - m2 - 1;
}
if (m1 == m2){
z = 0;
}
if (m1 < m2){
if (d1 > d2)
z = m1 - m2 + 1;
else
z = m1 - m2;
}
if(z < 0)
z = -z;
} else {
if (m1 < m2){
if (d1 > d2){
z = (12 - m2) + m1;
} else {
z = (12 - m2) + m1 -1;
}
} else {
if (d1 > d2){
z = m1 - m2 -1;
} else {
z = m1 - m2;
}
}
}
return z;
}
int Days(int d1, int m1, int y1, int d2, int m2, int y2){
int r;
r = ( 1461 * ( y1 + 4800 + ( m1 - 14 ) / 12)) / 4 +
( 367 * ( m1 - 2 - 12 * (( m1 - 14 ) / 12))) / 12 -
3 * (( y1 + 4900 + ( m1 - 14 ) / 12) / 100) / 4 + d1 - 32075
- (( 1461 * ( y2 + 4800 + ( m2 - 14 ) / 12)) / 4 +
( 367 * ( m2 - 2 - 12 * (( m2 - 14 ) / 12))) / 12 -
3 * (( y2 + 4900 + ( m2 - 14 ) / 12) / 100) / 4 + d2 - 32075);
if (r < 0) r = -r;
return r;
}
int main(){
int a, b, c;
cout << " Enter the day: ";
cin >> a;
cout << " Enter the month: ";
cin >> b;
cout << " Enter the year: ";
cin >> c;
calendar A(a, b, c);
if(A.Date() == 0)
cout << " Sunday" << endl;
else if(A.Date() == 1)
cout << " Monday" << endl;
else if(A.Date() == 2)
cout << " Tuesday" << endl;
else if(A.Date() == 3)
cout << " Wednesday" << endl;
else if(A.Date() == 4)
cout << " Thursday" << endl;
else if(A.Date() == 5)
cout << " Friday" << endl;
else if(A.Date() == 6)
cout << " Saturday" << endl;
int e, d, f, q, v, t;
cout << " Enter first date (DD.MM.YY): " << endl;
cout << " Enter the day: ";
cin >> e;
cout << " Enter the month: ";
cin >> d;
cout << " Enter the year: ";
cin >> f;
cout << " Enter second date (DD.MM.YY): " << endl;
cout << " Enter the day: ";
cin >> q;
cout << " Enter the month: ";
cin >> v;
cout << " Enter the year: ";
cin >> t;
cout << Years(e, d, f, q, v, t) << endl;
cout << Month(e, d, f, q, v, t) + Years(e, d, f, q, v, t) * 12 << endl;
cout << Days(e, d, f, q, v, t) << endl;
return 0;
}
