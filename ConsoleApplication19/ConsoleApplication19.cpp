#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <clocale>
#include <ctime>
#include <ctime>
using namespace std;

int abn(int a, int b, int n)
{
	a %= n;
	int res = a;
	for (int i = 1; i < b; i++)
	{
		res = (res*a) % n;
	}
	return res;
}

/*long int abn(int a, int b, int n)
{
	long int result;
	result = pow(a, b);
	result %= n;
	return result;

}*/

int Evcklid(int a, int b)
{
	int answer;
	if (a%b != 0) answer = Evcklid(b, a%b); else answer = b;
	return answer;
}

int UpgEvcklid(int a, int b, int & x, int & y) 
{
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = UpgEvcklid(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
/*int VzaimnProst(int phi)
{
	int e, k = 1;
	e = rand() % (phi - 2) + 2;
	if ((phi / e) < 2) k = -1;
	for (int i = e; (i < phi) and (i > 1); i += k)
	{
		if (Evcklid(phi, i) == 1)
		{
			e = i;
			i = 0;
		}
	}
	return e;
}*/

int main()
{
	int p, q, n, phi, e, x, d, m, c;
	setlocale(LC_ALL, "rus");
	srand(time(0));
	cout << "Введите простые числа p и q" << endl;
	cin >> p >> q;
	n = p * q;
	phi = (p - 1)*(q - 1);
	e = 59;
	cout << "phi = " << phi << endl;
	cout << "e (открытая часть ключа) = " << e << endl;
	UpgEvcklid(phi, e, x, d);
	cout << "Коэффициент при phi - k =" << x << endl;
	cout << "Коэффициент при e - d (закрытая часть ключа) = " << d << endl;
	if (d < 0) d *= -1;
	cout << "Введите m" << endl;
	cin >> m;
	c = abn(m, e, n);
	cout << "Закодированное число c = " << c << endl;
	m = abn(c, d, n);
	cout << "Раскодированное число m = " << m << endl;
	_getch();
	return 0;
}